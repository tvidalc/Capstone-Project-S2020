#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometric_shapes/shape_operations.h>
#include <moveit_msgs/DisplayRobotState.h>
//#include <geometry_msgs.h>
#include <moveit_msgs/DisplayTrajectory.h>
//#include <planning_environment/util/construct_object.h>

#include <visualization_msgs/Marker.h>
#include <tf/transform_datatypes.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "tester");
  ros::NodeHandle node_handle;
  ros::Publisher marker_pub = node_handle.advertise<visualization_msgs::Marker>("visualization_marker", 10);  

  ros::AsyncSpinner spinner(1);
  spinner.start();

  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  
  moveit::planning_interface::MoveGroup move_group("manipulator");
  move_group.setPoseReferenceFrame("world");
//  move_group.setNamedTarget("posDown");


  // objects 
 // moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 0, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  moveit::planning_interface::MoveGroup::Plan my_plan;

    move_group.allowReplanning(true);
    move_group.setNumPlanningAttempts(10);

// plan and go to pos1 (initial)

for(int k = 0; k< 5; k++) {

  move_group.setNamedTarget("posDown");
std::vector<float> robot_joint_values;
for (int i = 0; i<move_group.getCurrentJointValues().size();i++) {

robot_joint_values.push_back (move_group.getCurrentJointValues()[i]);

robot_joint_values[i] = (int)(robot_joint_values[i]*100 + .5);              // round off joint values
robot_joint_values[i] = (float)(robot_joint_values[i]/100);

ROS_INFO(" Check 1 %f", robot_joint_values[i]);
}

std::vector<float> desired_robot_position{0, -1.29, 1.5, 0, 1.57, 0};      

for (int i = 0; i < sizeof(desired_robot_position) / sizeof(desired_robot_position[0]); i++)
ROS_INFO("Check 2 %f",desired_robot_position[i]);


if (robot_joint_values != desired_robot_position) {

  move_group.setStartStateToCurrentState();
  move_group.plan(my_plan);
bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
ROS_INFO("Visualising plan: %s", success?"success": "FAILED to find plan");

if (success == true) { 
ROS_INFO("executing plan");
move_group.execute(my_plan);    // dangerous - make sure real robot is clear of obsticles 
 }           

else ROS_INFO(" Unable to execute as no plan was found");

}

else ROS_INFO("Robot already at desired position %s", "test");

move_group.clearPoseTargets();

// ############# Cartesian Motion Planning #############

//Cartesian Points 
double c_x;
double c_y;
double c_z;

  moveit_msgs::RobotTrajectory trajectory;
  const double jump_threshold = 0.0;
  const double eef_step = 0.01;



geometry_msgs::Pose target_pose1 = move_group.getCurrentPose().pose;
std::vector<geometry_msgs::Pose> waypoints;
waypoints.push_back(target_pose1);

/*
  tf::Quaternion q_tf = tf::createQuaternionFromRPY(0.3, 0.0, 0.0);
target_pose1.orientation.x = q_tf[0];
target_pose1.orientation.y = q_tf[1];
target_pose1.orientation.z = q_tf[2];
target_pose1.orientation.w = q_tf[3];

waypoints.push_back(target_pose1); */

c_x = 0.3;
for(double i = 0; i < c_x; i += c_x/2) {

target_pose1.position.x += c_x/2;
waypoints.push_back(target_pose1);

}

//target_pose1.position.x += 0.3;
//target_pose1.position.y -= 0.2;
//waypoints.push_back(target_pose1);

//planning
double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);

//sleep(0.5);


for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);
//move_group.clearPoseTarget();
move_group.move();
} 
//move_group.clearPoseTargets();

//move_group.setPoseTargets(waypoints);
//move_group.move();




waypoints.clear();
geometry_msgs::Pose target_pose = move_group.getCurrentPose().pose;


waypoints.push_back(target_pose);

c_y = 0.3;
for(double i = 0; i < c_y; i += c_y/2) {

target_pose.position.y -= c_y/2;
waypoints.push_back(target_pose);

}

//target_pose.position.y -= 0.2;
//waypoints.push_back(target_pose);



 fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
 ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);
//sleep(0.5);

for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);
move_group.move();
} 

waypoints.clear();
//target_pose.pose.clear()
target_pose = move_group.getCurrentPose().pose;
waypoints.push_back(target_pose);

c_x = 0.2;
for(double i = 0; i < c_x; i += c_x/2) {

target_pose.position.x -= c_x/2;
waypoints.push_back(target_pose);

}

 fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
 ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);
//sleep(0.5);

for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);
move_group.move();
} 

waypoints.clear();
target_pose = move_group.getCurrentPose().pose;
waypoints.push_back(target_pose);

c_y = 0.3;
for(double i = 0; i < c_y; i += c_y/2) {

target_pose.position.y += c_y/2;
waypoints.push_back(target_pose);

}

//target_pose.position.y += 0.2;
//waypoints.push_back(target_pose);

 fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
 ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);
//sleep(0.5);

for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);

move_group.move();
} 

}

//execution
//if (fraction > 0.95) move_group.move();

//move_group.execute(my_plan);




  //ros::shutdown();
spinner.stop();  
  return 0;
}
