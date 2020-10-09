#include <ros/ros.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <geometric_shapes/shape_operations.h>
#include <moveit_msgs/DisplayRobotState.h>

#include <moveit_msgs/DisplayTrajectory.h>
#include <tf2/LinearMath/Quaternion.h>

#include <visualization_msgs/Marker.h>
#include <tf/transform_datatypes.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "environment");
  ros::NodeHandle node_handle;
  ros::Publisher marker_pub = node_handle.advertise<visualization_msgs::Marker>("visualization_marker", 10);  

  ros::AsyncSpinner spinner(1);
  spinner.start();

  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  
  moveit::planning_interface::MoveGroup move_group("manipulator");

  tf2::Quaternion myQuaternion;
  myQuaternion.setRPY( 0, 0, 3.14 );

/****************** Environemnt ********************************************************8*/

Eigen::Vector3d scale(1,1,1);

// Define a collision object ROS message.
moveit_msgs::CollisionObject co;
// The id of the object is used to identify it.
co.id = "bench";

//Path where the .dae or .stl object is located
shapes::Mesh* m = shapes::createMeshFromResource("package://robotic_sensing/environment/bench2.stl",scale); 
ROS_INFO("Your mesh was loaded");

  tf::Quaternion quat_tf = tf::createQuaternionFromRPY(0.0, 0.0, 1.570796);

shape_msgs::Mesh mesh;
shapes::ShapeMsg mesh_msg;  
shapes::constructMsgFromShape(m, mesh_msg);
mesh = boost::get<shape_msgs::Mesh>(mesh_msg);

co.header.frame_id = move_group.getPlanningFrame();
//Define a pose for your mesh (specified relative to frame_id)
geometry_msgs::Pose obj_pose;
obj_pose.position.x = 0;
obj_pose.position.y = 0;
obj_pose.position.z = 0;

obj_pose.orientation.x = quat_tf[0];
obj_pose.orientation.y = quat_tf[1];
obj_pose.orientation.z = quat_tf[2];
obj_pose.orientation.w = quat_tf[3];
// Add the mesh to the Collision object message 
co.meshes.push_back(mesh);
co.mesh_poses.push_back(obj_pose);
co.operation = co.ADD;


// Create vector of collision objects to add 
std::vector<moveit_msgs::CollisionObject> object;
object.push_back(co);

// Add the collision object into the world
//moveit::planning_interface::MoveGroupInterface move_group("manipulator");
planning_scene_interface.applyCollisionObjects(object);

//###********************************************************************************************



//move_group.move();

  //ros::shutdown();
spinner.stop();  
  return 0;
}
