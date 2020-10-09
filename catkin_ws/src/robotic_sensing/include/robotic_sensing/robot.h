
#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometric_shapes/shape_operations.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <visualization_msgs/Marker.h>
#include <tf/transform_datatypes.h>
#include <vector>
#include <moveit/robot_model/robot_model.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>




class Robot {

public:

Robot(ros::NodeHandle &nh);
//moveit::planning_interface::MoveGroup move_group
//void control(pcl::PointXYZ point);
//void callback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& msg);
//void robotInit();



private:
void callback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& msg);

ros::NodeHandle nh_;
ros::Subscriber sub;
moveit::planning_interface::MoveGroup move_group;
moveit::planning_interface::MoveGroupInterface::Plan my_plan;
//void callback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& msg);
void control(pcl::PointXYZ point);
void robotInit();

geometry_msgs::Pose target_pose;
std::vector<float> robot_joint_values;
std::vector<float> desired_robot_position;








};
