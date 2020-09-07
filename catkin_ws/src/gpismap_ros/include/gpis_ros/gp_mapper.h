//
// Created by liyang on 1/13/20.
//

#ifndef SRC_GP_MAPPER_H
#define SRC_GP_MAPPER_H


#include "matlab.h"
#include "../gp/GPisMap3.h"

#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <visualization_msgs/Marker.h>
#include <tf/tf.h>
#include <tf2_ros/transform_listener.h>
#include <image_transport/image_transport.h>
#include <image_geometry/pinhole_camera_model.h>
#include <std_srvs/Empty.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/String.h>


namespace gpis_ros
{

    struct IsoInfo{
        int res[3] ;
        float scale[3] ;
        float range_st[3];
        int N_mesh;
    };

    class GPMapper
    {

    public:
        GPMapper( ros::NodeHandle& nh );

    private:
        void depthImageCallback(const sensor_msgs::ImageConstPtr& depth_msg,
                           const sensor_msgs::CameraInfoConstPtr& info_msg);

        bool setEnablerSwitch(std_srvs::Empty::Request &req,
                              std_srvs::Empty::Response &res);

 void setEnabler(const std_msgs::String& message);

        bool fetchRobotTF( tf::Transform& tran );

        void resetMap( int width, int height );

        void publishOutputs( const std_msgs::Header& header, const std::string& fname );

        void publishMesh( const std_msgs::Header& header, const std::string& fname );

    private:
        ros::NodeHandle m_nh;
        ros::NodeHandle m_pnh;	

        image_transport::CameraSubscriber m_sub_depth;
        ros::Publisher m_mapPub;
        ros::Publisher m_pclPub, m_gpis_internal_pub;
        ros::Publisher m_pileMeshPub;

        std::string m_worldFrameId; // the map frame
        bool m_latchedTopics;

        pcl::PointCloud<pcl::PointXYZ>::Ptr m_cloud;

        tf::Transform m_robotTF;

        image_transport::ImageTransport m_it;
        image_geometry::PinholeCameraModel m_model;

        ros::ServiceServer m_trigger_svc;
        //ros::ServiceServer m_console_svc;

	//ros::Publisher m_pub;	
	//ros::Subscriber m_sub;
	
        tf2_ros::Buffer m_tf2Buffer;
        tf2_ros::TransformListener m_tf2Listener;

        bool m_should_receive_depth;

        gp::GPisMap3 m_gpm;

        std::vector<float> x_samples, y_samples, z_samples;
        std::vector<float> pRes;
        std::vector<float> xtest;
        std::vector<float> pose_ptr;

        matlab::RangeInfo<float> x_range, y_range, z_range;

        IsoInfo m_isoinfo;

        visualization_msgs::Marker m_mesh_msg;
        std::string m_mesh_fbase;

    };

}

#endif //SRC_PILE_2D_MAPPER_H
