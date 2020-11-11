//
// Created by liyang on 1/13/20
//
// Edited by Abdel Saeed 09/10/2020
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
#include <geometry_msgs/PoseStamped.h>
#include <tf_conversions/tf_eigen.h>
#include <tf/tf.h>
#include <tf2_ros/transform_listener.h>
#include <image_transport/image_transport.h>
#include <image_geometry/pinhole_camera_model.h>
#include <std_srvs/Empty.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/String.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <gpismap_ros/MoveArmAction.h>
#include <geometry_msgs/Pose.h>

#include <iostream>
#include <fstream>

#include <algorithm>
#include <bits/stdc++.h>

namespace gpis_ros
{

    struct Point {
    double x;     // coordinates
    int cluster;     // no default cluster
    double minDist;  // default infinite dist to nearest cluster

    Point() :
        x(0.0),
        cluster(-1),
        minDist(__DBL_MAX__) {}

    Point(double x) :
        x(x),
        cluster(-1),
        minDist(__DBL_MAX__) {}

    double distance(Point p) {
        return (p.x - x) * (p.x - x);
    }
};



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

        void publishPosition( pcl::PointXYZ point, int cnt);

        //float getGradient (float var, float vtop, float vbottom, float vleft, float vright, float vfront, float vback);

        void getArrayIndex(int pos, int length, int &value1, int &value2, int &value3);
        int getVectorIndex(int i, int j, int k);
        int getFacePos(int pos, int length, int face);
        float getGradient(float var, float top, float bottom, float front, float back, float left, float right);
        pcl::PointXYZ findMax(std::vector<float> util);
        geometry_msgs::Pose getPose(int cnt);


        int mode(int n, int arr[], int clus[], int sizeofpoints);
        double kMeansClustering(std::vector<Point>* points, int epochs, int k, int sizeofpoints);


    private:
        ros::NodeHandle m_nh;
        ros::NodeHandle m_pnh;	
        std::string command;

        image_transport::CameraSubscriber m_sub_depth;
        ros::Publisher m_mapPub;
        ros::Publisher m_pclPub, m_gpis_internal_pub;
        ros::Publisher m_pileMeshPub;
        ros::Publisher m_position;
        actionlib::SimpleActionClient<gpismap_ros::MoveArmAction> client_;

        std::string m_worldFrameId; // the map frame
        bool m_latchedTopics;

        pcl::PointCloud<pcl::PointXYZ>::Ptr m_cloud;

        tf::Transform m_robotTF;

        image_transport::ImageTransport m_it;
        image_geometry::PinholeCameraModel m_model;

        ros::ServiceServer m_trigger_svc;
	
        tf2_ros::Buffer m_tf2Buffer;
        tf2_ros::TransformListener m_tf2Listener;

        bool m_should_receive_depth;

        gp::GPisMap3 m_gpm;

        std::vector<float> x_samples, y_samples, z_samples;
        std::vector<float> pRes;
        std::vector<float> xtest;
        std::vector<float> pose_ptr;
        std::vector<float> transform_ptr;

        matlab::RangeInfo<float> x_range, y_range, z_range;

        IsoInfo m_isoinfo;

        visualization_msgs::Marker m_mesh_msg;
        std::string m_mesh_fbase;

        pcl::PointCloud<pcl::PointXYZ>::Ptr m_cloud_filtered;
        int Tp, Bt, Ft, Bk, Rt, Lt;

        bool success;
        bool finished_within_time;

        gpismap_ros::MoveArmGoal goal;
        geometry_msgs::Pose target_pose, target_pose1, target_pose2, target_pose3, target_pose4;

        std::ofstream myfile;
        char filename[50];

        bool check;

        //std::vector<Point> pointskmeans;



    };

}

#endif //SRC_PILE_2D_MAPPER_H
