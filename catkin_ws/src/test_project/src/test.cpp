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
#include <moveit/robot_model/robot_model.h>
#include <thread>
#include <chrono>

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


  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 0, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  moveit::planning_interface::MoveGroup::Plan my_plan;

    move_group.allowReplanning(false);
    move_group.setNumPlanningAttempts(5);

    geometry_msgs::Pose poset;

/*
for (int i = 0; i < 50; i++){

    poset = move_group.getCurrentPose().pose;
std::cout << poset.position.x << "  " << poset.position.y << "  " <<  poset.position.z << std::endl;

    std::cout << "RPY" << std::endl;

for (int i =0; i <3; i++)
    std::cout << move_group.getCurrentRPY().at(i) << "   " << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "\n" << std::endl;
}

*/
    std::this_thread::sleep_for(std::chrono::seconds(3));

geometry_msgs::Pose target_pose;

// 1

            target_pose .orientation = tf::createQuaternionMsgFromRollPitchYaw(1.55, 0.0, 1.1);

            //move_group.setStartStateToCurrentState();
           /* move_group.clearPoseTarget();
            target_pose.position.x = 0.10;
            target_pose.position.y = 0.57;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);
            move_group.plan(my_plan);
            move_group.move();
            move_group.clearPoseTarget();
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
  
// 2



            target_pose .orientation = tf::createQuaternionMsgFromRollPitchYaw(2.0, -0.635, -0.69);
            move_group.clearPoseTarget();
            target_pose.position.x = -0.48;
            target_pose.position.y = 0.52;
            target_pose.position.z = 1.4;
            move_group.setPoseTarget(target_pose);
            move_group.plan(my_plan);
            move_group.move();
            move_group.clearPoseTarget();
            std::this_thread::sleep_for(std::chrono::seconds(1));


// 3
            target_pose .orientation = tf::createQuaternionMsgFromRollPitchYaw(1.55, 0.0, 1.1);
            move_group.clearPoseTarget();
            target_pose.position.x = -0.05;
            target_pose.position.y = 0.60;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);
            move_group.plan(my_plan);
            move_group.move();
            move_group.clearPoseTarget();
            std::this_thread::sleep_for(std::chrono::seconds(1));  

// 4

            move_group.clearPoseTarget();
            target_pose.position.x = 0.30;
            target_pose.position.y = 0.60;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));

// 5

            move_group.clearPoseTarget();
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.22, 0.5, -0.6);
            target_pose.position.x = 0.37;
            target_pose.position.y = 0.45;
            target_pose.position.z = 1.50;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            
// 6
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.55, 0.0, 1.1);
            
            move_group.clearPoseTarget();
            target_pose.position.x = 0.30;
            target_pose.position.y = 0.77;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));

// 7


            move_group.clearPoseTarget();
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.3, 0.44, 1.04);
            target_pose.position.x = 0.11;
            target_pose.position.y = 1.0;
            target_pose.position.z = 1.5;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));


// 8
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.54, 0.0, 1.1);
            move_group.clearPoseTarget();
            target_pose.position.x = 0.0;
            target_pose.position.y = 0.37;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));

// 9

            move_group.clearPoseTarget();
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.8, -0.47, 0.607);
            target_pose.position.x = -0.32;
            target_pose.position.y = 0.0;
            target_pose.position.z = 1.62;
            move_group.setPoseTarget(target_pose);

            move_group.plan(my_plan);
            move_group.move();
            std::this_thread::sleep_for(std::chrono::seconds(1));
*/
// 10
            move_group.clearPoseTarget();
            target_pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(1.54, 0.0, 1.1);
            target_pose.position.x = 0.20;
            target_pose.position.y = 0.30;
            target_pose.position.z = 1.67;
            move_group.setPoseTarget(target_pose);  
            move_group.move();



            //move_group.move(); 
   /*
// plan and go to pos1 (initial)

//for(int k = 0; k< 5; k++) {

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
ROS_INFO("Visualising plan: %s", success?"Success": "FAILED to find plan");

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

double w_1;
double w_2;
double w_3;

  moveit_msgs::RobotTrajectory trajectory;
  const double jump_threshold = 0.0;
  const double eef_step = 0.01;

geometry_msgs::Pose target_pose1; */

/*
geometry_msgs::Pose target_pose2;
target_pose2.orientation.w = 1.0;
target_pose2.position.x = 0.38;
target_pose2.position.y = +0.2;
target_pose2.position.z = 1.6;
move_group.setPoseTarget(target_pose2);

  ros::Duration(0.5).sleep();
   bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);  */
  /*while (!success) //keep trying until a plan is found
   {
                    
    success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
   }*/

/*
 if(!success) //execute
 throw std::runtime_error("No plan found");

 move_group.move(); //blocking   */


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  tf::Quaternion q_tf = tf::createQuaternionFromRPY(0.0, 0.785, 0.0);

ROS_INFO_STREAM("\nPose Reference Frame: " << move_group.getPoseReferenceFrame());      //////  Checking reference frame = world

//for (int i =0; i < 6; i++){

//ROS_INFO_STREAM("\nTF QUATERNION: " << q_tf[i]); }

// target_pose1.orientation.x = q_tf[0];
// target_pose1.orientation.y = q_tf[1];
// target_pose1.orientation.z = q_tf[2];
// target_pose1.orientation.w = q_tf[3];
// target_pose1.position.x = 0;
// target_pose1.position.y = 0;
// target_pose1.position.z = 0;

//move_group.setPoseTarget(target_pose1);
//move_group.move();

/*
target_pose1 = move_group.getCurrentPose().pose;
std::vector<geometry_msgs::Pose> waypoints;
waypoints.push_back(target_pose1);



target_pose1.position.y += 0.1;
waypoints.push_back(target_pose1);

double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);


for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{
move_group.setPoseTarget(*it);
move_group.move();
} 
move_group.clearPoseTargets();

*/

/* checking joint limits
const robot_state::JointModelGroup *joint_model_group =
    move_group.getCurrentState()->getJointModelGroup("manipulator");

for(int i = 0; i < 50; i++){
moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
std::vector<double> joint_group_positions;
current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);

ROS_INFO_STREAM("\nBase Joint: " << joint_group_positions[0]);  
std::this_thread::sleep_for(std::chrono::milliseconds(500));  }
/*joint_group_positions[0] += 0.1;  // rad
move_group.setJointValueTarget(joint_group_positions);

//moveit::planning_interface::MoveGroupInterface::Plan my_plan;
move_group.plan(my_plan); 
move_group.move();

move_group.clearPoseTargets();   */

/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

target_pose1 = move_group.getCurrentPose().pose;
waypoints.push_back(target_pose1);

c_x = 0.3;
for(double i = 0; i < c_x; i += c_x/2) {

target_pose1.position.x += c_x/2;
waypoints.push_back(target_pose1);

}


//planning
fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);


for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);
move_group.move();
} 
move_group.clearPoseTargets();



joint_group_positions.clear();
current_state = move_group.getCurrentState();
current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
joint_group_positions[3] -= 0.25;  // rad - wrist 1 
//joint_group_positions[5] -= 1.5708;  // rad - wrist 3
//joint_group_positions[4] += 0.4;  // rad - wrist 2

move_group.setJointValueTarget(joint_group_positions);
move_group.plan(my_plan); 
move_group.move();

move_group.clearPoseTargets();


//

joint_group_positions.clear();
current_state = move_group.getCurrentState();
current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
joint_group_positions[5] += 1.5708;  // rad - wrist 3

move_group.setJointValueTarget(joint_group_positions);
move_group.plan(my_plan); 
move_group.move();

move_group.clearPoseTargets();

//

joint_group_positions.clear();
current_state = move_group.getCurrentState();
current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);
joint_group_positions[4] += 0.4;  // rad - wrist 2

move_group.setJointValueTarget(joint_group_positions);
move_group.plan(my_plan); 
move_group.move();

move_group.clearPoseTargets();


waypoints.clear();
geometry_msgs::Pose target_pose = move_group.getCurrentPose().pose;


waypoints.push_back(target_pose);

c_y = 0.3;
for(double i = 0; i < c_y; i += c_y/3) {

target_pose.position.y -= c_y/3;
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
move_group.clearPoseTargets();

waypoints.clear();
target_pose = move_group.getCurrentPose().pose;
waypoints.push_back(target_pose);

c_x = 0.3;
for(double i = 0; i < c_x; i += c_x/2) {

target_pose.position.x -= c_x/2;
waypoints.push_back(target_pose);

}

 fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
 ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);
//sleep(0.5);


joint_group_positions.clear();
current_state = move_group.getCurrentState();
current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);

for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);
move_group.move();

joint_group_positions[4] += 0.4/waypoints.size(); // rad - wrist 2
move_group.plan(my_plan);
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


 fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
 ROS_INFO("Visualizing plan (Cartesian path) (%.2f%% acheived)", fraction * 100.0);
//sleep(0.5);

for (std::vector<geometry_msgs::Pose>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
{

ROS_INFO(" IT values :  %f", *it);
move_group.setPoseTarget(*it);

move_group.move();
}    

//}  for loop

*/

  //ros::shutdown();
spinner.stop();  
  return 0;
}







// Waypoints No Rotation

/*

    geometry_msgs::Pose GPMapper::getPose(int cnt)
    {
        target_pose .orientation = tf::createQuaternionMsgFromRollPitchYaw(1.55, 0.0, 1.1);
        if (cnt == 0){
            target_pose.position.x = -0.05;
            target_pose.position.y = 0.60;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 1){
            target_pose.position.x = 0.11;
            target_pose.position.y = 0.50;
            target_pose.position.z = 1.67;
        }

        else if (cnt == 2){
            target_pose.position.x = 0.30;
            target_pose.position.y = 0.60;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 3){
            target_pose.position.x = 0.30;
            target_pose.position.y = 0.77;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 4){
            target_pose.position.x = 0.0;
            target_pose.position.y = 0.77;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 5){
            target_pose.position.x = 0.0;
            target_pose.position.y = 0.37;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 6){
            target_pose.position.x = 0.0;
            target_pose.position.y = 0.30;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 7){
            target_pose.position.x = 0.25;
            target_pose.position.y = 0.30;
            target_pose.position.z = 1.67;
        }
        else if (cnt == 8){
            target_pose.position.x = -0.05;
            target_pose.position.y = 0.30;
            target_pose.position.z = 1.67;
        }

        return target_pose;


    }



}











*/