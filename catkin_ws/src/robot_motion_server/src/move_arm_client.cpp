//
// Created by Abdel Saeed 09/10/2020
//


#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <robot_motion_server/MoveArmAction.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf_conversions/tf_eigen.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_arm_client");
    actionlib::SimpleActionClient<robot_motion_server::MoveArmAction> client_("move_arm", true);
    ROS_INFO("Waiting for server");
    client_.waitForServer();
    ROS_INFO("Connected to server");

    geometry_msgs::Pose pose1;
    pose1.orientation = tf::createQuaternionMsgFromRollPitchYaw(2.904, 1.524, -1.808);
    pose1.position.x = 0.4;
    pose1.position.y = 0.0;
    pose1.position.z = 0.50;

    geometry_msgs::Pose pose2;
    pose2.orientation = tf::createQuaternionMsgFromRollPitchYaw(2.904, 1.524, -1.808);
    pose2.position.x = 0.4;
    pose2.position.y = 0.5;
    pose2.position.z = 0.50;

    geometry_msgs::Pose pose3;
    pose3.orientation = tf::createQuaternionMsgFromRollPitchYaw(2.904, 1.524, -1.808);
    pose3.position.x = 0.4;
    pose3.position.y = -0.5;
    pose3.position.z = 0.50;

    bool success = false;
    bool finished_within_time = false;

    robot_motion_server::MoveArmGoal goal;
    // goal.command = "RESET"; //nothing is implemented in here
    goal.command = "GTWP"; //go to waypoint with cartesian planning
    goal.target_pose = pose1;
    client_.sendGoal(goal);
    finished_within_time = client_.waitForResult(ros::Duration(200.0));
    if (!finished_within_time)
    {
        ROS_INFO("Timed out !!!");
    }
    else
    {
        actionlib::SimpleClientGoalState state = client_.getState();
        success = (state == actionlib::SimpleClientGoalState::SUCCEEDED);
        if (success)
            ROS_INFO("Action finished: %s", state.toString().c_str());
        else
            ROS_INFO("Action failed: %s", state.toString().c_str());
    }

    while (1)
    {
        /// go to pose 2
        goal.command = "GTWP";
        goal.target_pose = pose2;
        client_.sendGoal(goal);
        finished_within_time = false;
        finished_within_time = client_.waitForResult(ros::Duration(200.0));
        if (!finished_within_time)
        {
            ROS_INFO("Timed out !!!");
        }
        else
        {
            actionlib::SimpleClientGoalState state = client_.getState();
            success = (state == actionlib::SimpleClientGoalState::SUCCEEDED);
            if (success)
                ROS_INFO("Action finished: %s", state.toString().c_str());
            else
                ROS_INFO("Action failed: %s", state.toString().c_str());
        }

        /// go to pose 3
        goal.command = "GTWP";
        goal.target_pose = pose3;
        client_.sendGoal(goal);
        finished_within_time = false;
        finished_within_time = client_.waitForResult(ros::Duration(200.0));
        if (!finished_within_time)
        {
            ROS_INFO("Timed out !!!");
        }
        else
        {
            actionlib::SimpleClientGoalState state = client_.getState();
            success = (state == actionlib::SimpleClientGoalState::SUCCEEDED);
            if (success)
                ROS_INFO("Action finished: %s", state.toString().c_str());
            else
                ROS_INFO("Action failed: %s", state.toString().c_str());
        }
    }
    ros::shutdown();
}
