//
// Created by liyang on 1/13/20.
//

#include <gpis_ros/gp_mapper.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/image_encodings.h>
#include <pcl/point_cloud.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <depth_image_proc/depth_traits.h>
#include <ros/package.h>
#include <tf/tf.h>
#include <tf2_ros/transform_listener.h>
#include <image_transport/image_transport.h>
#include <image_geometry/pinhole_camera_model.h>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <std_msgs/String.h>

namespace isosurface
{
    extern int iso_main(std::vector<float>& my_cloud, float bias, float *val, int res[], float scale[], float range_st[], char *fname);
}

namespace
{
    double PILE_RADIUS = 3;
    int MAX_RETRIES = 2;
    unsigned char EMPTY_COLOR = 100;
    float EMPTY_COLOR_F32 = 0.5;

    std::string
    do_iso( pcl::PointCloud<pcl::PointXYZ>& cloud, float bias, std::vector<float>& pRes, gpis_ros::IsoInfo& isoinfo, int gp_cnt )
    {
        std::string fbase =  ( boost::format( "pile_%02d.ply" ) % gp_cnt ).str();
        {
            std::string fpath = ros::package::getPath("gpismap_ros") + "/mesh/";
            if (!boost::filesystem::exists(fpath))
                boost::filesystem::create_directory(boost::filesystem::path(fpath));

            std::string fname = fpath + fbase;

            std::cout << "Generate PLY mesh: " << fname << std::endl;
            std::vector<float> data;
            char *fname_buf = const_cast<char *>(fname.c_str());

            isosurface::iso_main(data, bias, pRes.data(), isoinfo.res, isoinfo.scale, isoinfo.range_st, fname_buf);

            int N = (int) data.size() / 3;

            cloud.points.resize(N);
            for (int i = 0; i < N; ++i) {
                int k3 = i * 3;
                cloud.points[i] = pcl::PointXYZ(data[k3], data[k3 + 1], data[k3 + 2]);
            }
        }
        return fbase;
    }

}

namespace gpis_ros
{
	
    GPMapper::GPMapper( ros::NodeHandle& nh )
    : m_nh( nh )
    , m_pnh( "~" )
    , m_worldFrameId( "/base_link" )
    , m_it(nh)
    , m_tf2Listener(m_tf2Buffer)
    , m_should_receive_depth( false )
    {

        image_transport::TransportHints hints("raw", ros::TransportHints(), nh);
        m_sub_depth = m_it.subscribeCamera("/camera/depth/image_rect_raw",
                2, &GPMapper::depthImageCallback, this, hints);

        m_pclPub = m_nh.advertise<sensor_msgs::PointCloud2>( "gp_pcl", 1 );

        m_pileMeshPub = m_nh.advertise<visualization_msgs::Marker>( "gp_mesh", 5 );

        m_trigger_svc = nh.advertiseService( "srv_mapper_update", &GPMapper::setEnablerSwitch, this ); 

	//m_pub = nh.advertise < std_msgs::String > ("sv_mapper",1);
        //m_sub = nh.subscribe( "/sv_mapper", 1, &GPMapper::setEnabler, this);

    }

    void
    GPMapper::resetMap( int width, int height )
    {
        ROS_INFO_STREAM( "GPMapper::resetMap " );

        ROS_INFO_STREAM( "GPMapper::resetMap :> fx=" << m_model.fx() << ", fy=" << m_model.fy()
                          << ", cx=" << m_model.cx() << ", cy=" << m_model.cy()
                          << ", width=" << width << ", height=" << height );

        gp::camParam c( m_model.fx(), m_model.fy(), m_model.cx(), m_model.cy(), width, height);
        m_gpm.resetCam(c);
        pose_ptr.resize( 12 );

        // generate mesh grid * Smaller increments makes it more defined but more points X*Y*Z which takes longer to process
        x_range = matlab::RangeInfo<float>( -0.3, 0.01, 0.3 );
        y_range = matlab::RangeInfo<float>( 0.0, 0.01, 0.9 );
        z_range = matlab::RangeInfo<float>( 0.052, 0.01, 0.4 );

        x_samples = matlab::colonRange<float>( x_range.begin, x_range.inc, x_range.end );
        y_samples = matlab::colonRange<float>( y_range.begin, y_range.inc, y_range.end );
        z_samples = matlab::colonRange<float>( z_range.begin, z_range.inc, z_range.end );
        int X = x_samples.size();
        int Y = y_samples.size();
        int Z = z_samples.size();
        ROS_INFO_STREAM( "GPMapper::resetMap :> generate mesh grid"
                         << ", x_s.size=" << X
                         << ", y_s.size=" << Y
                         << ", z_s.size=" << Z
                         << ", X*Y*Z=" << X * Y * Z );
        matlab::mesh_grid<float>( xtest, x_samples, y_samples, z_samples );
        int N_out = x_samples.size() * y_samples.size() * z_samples.size();
        pRes.clear();
        pRes.resize( N_out * 2 * (1 + 3), 0 );
        ROS_INFO_STREAM( "GPMapper::resetMap :> mesh_grid.size=" << xtest.size()
                << ", pRes.size="<< pRes.size() );

        // set isosurface info
        ROS_INFO_STREAM("GPMapper::resetMap :> set isosurface info");
        m_isoinfo.res[0] = X;
        m_isoinfo.res[1] = Y;
        m_isoinfo.res[2] = Z;
        m_isoinfo.scale[0] = x_range.inc;
        m_isoinfo.scale[1] = y_range.inc;
        m_isoinfo.scale[2] = z_range.inc;
        m_isoinfo.range_st[0] = x_range.begin;
        m_isoinfo.range_st[1] = y_range.begin;
        m_isoinfo.range_st[2] = z_range.begin;
        m_isoinfo.N_mesh = X * Y * Z;       // number of points in mesh

	//CHECK
	ROS_INFO_STREAM("Checking N_mesh Points: " << m_isoinfo.N_mesh );

        // set pose_ptr in the format GPisMap3 expects
        ROS_INFO_STREAM("GPMapper::resetMap :> set robot Pose");
        fetchRobotTF( m_robotTF );
        pose_ptr[0] = m_robotTF.getOrigin().x();
        pose_ptr[1] = m_robotTF.getOrigin().y();
        pose_ptr[2] = m_robotTF.getOrigin().z();

        pose_ptr[3] = m_robotTF.getBasis()[0][0];
        pose_ptr[4] = m_robotTF.getBasis()[1][0];
        pose_ptr[5] = m_robotTF.getBasis()[2][0];

        pose_ptr[6] = m_robotTF.getBasis()[0][1];
        pose_ptr[7] = m_robotTF.getBasis()[1][1];
        pose_ptr[8] = m_robotTF.getBasis()[2][1];

        pose_ptr[9] = m_robotTF.getBasis()[0][2];
        pose_ptr[10] = m_robotTF.getBasis()[1][2];
        pose_ptr[11] = m_robotTF.getBasis()[2][2];


        // transform manipulability bounding box from arm_base frame to map frame

        m_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>());

    }

    bool
    GPMapper::fetchRobotTF( tf::Transform& tran )
    {
        geometry_msgs::TransformStamped local_transformStamped;
        try {
            local_transformStamped = m_tf2Buffer.lookupTransform("base_link", "camera_link",
                                                                 ros::Time(0) );
            //m_transformStamped = local_transformStamped; 

	//ROS_INFO_STREAM("Checking Transform: " << local_transformStamped.transform);

            tf::transformMsgToTF( local_transformStamped.transform, tran );
            return true;
        }
        catch (tf2::TransformException &ex) {
            ROS_WARN("%s", ex.what());
            return false;
        }
    }

    bool
    GPMapper::setEnablerSwitch( std_srvs::Empty::Request &req, std_srvs::Empty::Response &res )
    {
        ROS_INFO_STREAM("GP_mapper enabled" );
        m_should_receive_depth = true;

        return true;
    }

 /* void
    GPMapper::setEnabler( const std_msgs::String& message )
    {
        ROS_INFO_STREAM("GP_mapper enabled" );
        m_should_receive_depth = true;

        //return true;
    } */

    void
    GPMapper::depthImageCallback(const sensor_msgs::ImageConstPtr& depth_msg,
                                 const sensor_msgs::CameraInfoConstPtr& info_msg)
    {
        static int gp_cnt = -1;

        // check if enabled
        if ( !m_should_receive_depth ) {
            return;
        }

        ++gp_cnt;

        ROS_INFO_STREAM("depthImageCallback[" << gp_cnt << "]=> Received a new depth image message (frame = '" << depth_msg->header.frame_id
                         << "', encoding='" << depth_msg->encoding << "')" << "image size: " << depth_msg->height<<" "<< depth_msg->width);

        // get depth image
        ros::WallTime start = ros::WallTime::now();

        const bool is_u_short = depth_msg->encoding == sensor_msgs::image_encodings::TYPE_16UC1;

        // Update camera model
        m_model.fromCameraInfo(info_msg);

        int rows = depth_msg->height;
        int cols = depth_msg->width;
        resetMap( cols, rows );

        ROS_INFO_STREAM( "GPMapper::depthImageCallback=> process NANs " );
        float *input_z = 0;
        cv::Mat gp_img( cols, rows, CV_32FC1 );  // GPisMap3 uses transposed image mat

        if (is_u_short) {
            ROS_INFO_STREAM("GPMapper::depthImageCallback=>Depth input is int");
            const uint16_t* depth_row = reinterpret_cast<const uint16_t*>(&depth_msg->data[0]);
            input_z = reinterpret_cast<float*>(gp_img.data);
            int row_step = depth_msg->step / sizeof(uint16_t);

            for (int v = 0; v < (int)rows; ++v, depth_row += row_step )
            {
                std::stringstream sstrm;
                for (int u = 0; u < (int)cols; ++u )
                {
                    float depth = static_cast<float>( depth_row[u] );
                    // Missing points denoted by NaNs
                    if (!depth_image_proc::DepthTraits<uint16_t>::valid(depth)) {
                        depth = 0;
                    }

                    int k = rows * u + v;       // transposed image
                    input_z[ k ] = depth_image_proc::DepthTraits<uint16_t>::toMeters( depth );
                }
            }
        }
        else {
            ROS_INFO_STREAM("GPMapper::depthImageCallback=>Depth input is float");
            cv::Mat debug_image( rows, cols, CV_16UC1 );

            const float* depth_row = reinterpret_cast<const float*>(&depth_msg->data[0]);
            input_z = reinterpret_cast<float*>(gp_img.data);
            int row_step = depth_msg->step / sizeof(float);

            for (int v = 0; v < (int)rows; ++v, depth_row += row_step )
            {
                std::stringstream sstrm;
                for (int u = 0; u < (int)cols; ++u )
                {
                    float depth = depth_row[u];

                    // Missing points denoted by NaNs
                    if (!depth_image_proc::DepthTraits<float>::valid(depth)) {
                        depth = 0;
                    }
                    //gp_img.at<float>(u, v) = depth;
                    int k = rows * u + v;       // transposed image
                    input_z[ k ] = depth;
                    debug_image.at<uint16_t>(v, u) = //static_cast<uint16_t>( depth * 10000 );
                            depth_image_proc::DepthTraits<uint16_t>::fromMeters( depth );
                }
            }

        }

        // GP update & fuse
        ROS_INFO_STREAM("GPMapper::depthImageCallback=> GP Update ...");
        int N_in = rows * cols;
        m_gpm.update( input_z, N_in, pose_ptr );

        // query GP for mesh grid
        ROS_INFO_STREAM("GPMapper::depthImageCallback=> GPIS Query mesh-grid ...");
        int N_out = x_samples.size() * y_samples.size() * z_samples.size();
        m_gpm.test( xtest.data(), 3, N_out, pRes.data() );

        // generate implicit surface
        ROS_INFO_STREAM("GPMapper::depthImageCallback=> GPIS generate iso ...");

        m_mesh_fbase = do_iso( *m_cloud, 0.17, pRes, m_isoinfo, gp_cnt );

        publishOutputs( depth_msg->header, m_mesh_fbase );


       // m_should_receive_depth = false;
    }


    void GPMapper::publishMesh( const std_msgs::Header& header, const std::string& fbasename )
    {
        ROS_INFO_STREAM( "GPMapper::publishMesh" );

        // publish pile mesh
        m_mesh_msg.header = header;
        m_mesh_msg.header.frame_id = m_worldFrameId;
        m_mesh_msg.ns = "pile_outline";
        if ( !m_mesh_msg.id )
            m_mesh_msg.action = visualization_msgs::Marker::ADD;
        else
            m_mesh_msg.action = visualization_msgs::Marker::MODIFY;
        m_mesh_msg.id = 1;
        m_mesh_msg.lifetime = ros::Duration();
        m_mesh_msg.color.r = 0.5;
        m_mesh_msg.color.g = 0.1;
        m_mesh_msg.color.a = 1.0;
        //m_mesh_msg.pose.position = geometry_msgs::Point(0, 0, 0);
        //m_mesh_msg.pose.orientation
        m_mesh_msg.type = visualization_msgs::Marker::MESH_RESOURCE;
        m_mesh_msg.mesh_use_embedded_materials = true;
        m_mesh_msg.mesh_resource = "package://gpismap_ros/mesh/" + fbasename;
        m_mesh_msg.scale.x = 1.0;
        m_mesh_msg.scale.y = 1.0;
        m_mesh_msg.scale.z = 1.0;
        m_pileMeshPub.publish( m_mesh_msg );

        ROS_INFO_STREAM("Publishing " << m_mesh_msg.mesh_resource );
    }


    void
    GPMapper::publishOutputs( const std_msgs::Header& header, const std::string& fbasename )
    {
        ROS_INFO_STREAM( "GPMapper::publishOutputs " );

        // publish iso pcl
        sensor_msgs::PointCloud2 pclmsg;
        pcl::toROSMsg( *m_cloud, pclmsg );
        pclmsg.header = header;
        pclmsg.header.frame_id = m_worldFrameId;
        m_pclPub.publish( pclmsg );

        // publish markers
        publishMesh( header, fbasename );
    }

}

int main( int argc, char** argv )
{
    ros::init( argc, argv, "gpismap3" );
    ros::NodeHandle node_handle;

    ROS_INFO_STREAM("ROS module uses GPisMap3");
    gpis_ros::GPMapper gpmapper( node_handle );
    ros::spin();

}
