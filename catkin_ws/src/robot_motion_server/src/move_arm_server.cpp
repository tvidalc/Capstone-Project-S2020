//
// Created by Abdel Saeed 09/10/2020
//

#include <robot_motion_server/MoveArmAction.h>
#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>    // For providing functionality
#include <actionlib/client/simple_action_client.h>    // For calling the joint trajectory action
#include <control_msgs/FollowJointTrajectoryAction.h> // for sending arm to home position
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit/robot_model/robot_model.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>

#define PLANNING_GROUP "manipulator"
#define REF_EELINK "ee_link"
#define REF_FRAME "world"
#define PLANNING_TIME 200.0
#define MAX_VELOCITY 0.1

namespace robot_manipulation
{
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> TrajClient;

class MoveArmServer
{
private:
    ros::NodeHandle nh_;
    std::string action_name_;
    actionlib::SimpleActionServer<robot_motion_server::MoveArmAction> action_server_;

    robot_motion_server::MoveArmFeedback feedback_;
    robot_motion_server::MoveArmResult result_;
    robot_motion_server::MoveArmGoalConstPtr goal_;
    bool new_goal_received;
    TrajClient *traj_client_;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan_;



public:
    moveit::planning_interface::MoveGroupInterface::Plan motion_plan_;
    moveit::planning_interface::MoveGroupInterface move_group;

    MoveArmServer() : nh_("~"), action_server_("move_arm", false), action_name_("move_arm"), move_group(PLANNING_GROUP)
    {
        traj_client_ = new TrajClient("/scaled_pos_joint_traj_controller/follow_joint_trajectory", true);
        while (!traj_client_->waitForServer(ros::Duration(5.0)))
        {
            ROS_INFO("[move arm] Waiting for the joint_trajectory_action server");
        }
        new_goal_received = false;

        action_server_.registerGoalCallback(boost::bind(&MoveArmServer::goalCB, this));
        action_server_.registerPreemptCallback(boost::bind(&MoveArmServer::preemptCB, this));
        action_server_.start();

        ROS_INFO("[move arm] Action server started ");
    }


    void goalCB()
    {
        goal_ = action_server_.acceptNewGoal();
        new_goal_received = true;
    }

    bool newGoalReceived()
    {
        return new_goal_received;
    }


    void execute()
    {
        new_goal_received = false;
        if (goal_->command == "RESET")
        {
            ROS_INFO("[move arm] Moving robot arm to reset pose");
            resetArm();
        }
        else if (goal_->command == "GTWP")
        {
            ROS_INFO("[move arm] Moving robot arm to goal");
            gtWaypoint();
        }
        else if (goal_->command == "GTP")
        {
            ROS_INFO("[move arm] Moving robot arm to goal");
            gtPose();
        }
        else
        {
            ROS_ERROR_STREAM("Unknown command to move_arm_action_server: " << goal_->command);
        }
    }


    // Cancel the action
    void preemptCB()
    {
        new_goal_received = false;
        ROS_INFO("[%s] Preempted", action_name_.c_str());
        action_server_.setPreempted();
    }


    void resetArm()
    {
        ROS_INFO("[move arm] Start to reset arm");
        ROS_ERROR("You can implement something here ");
        //you can hardcode your default pose here
        ROS_INFO("[move arm] Finished");
        action_server_.setSucceeded(result_);
    }


    void gtWaypoint()
    {
        ROS_INFO("[move arm] Start to move the robot");
        //plan handler
        geometry_msgs::Pose target_pose;
        target_pose = goal_->target_pose;
        bool is_plan_generated = false;
        bool is_plan_executed = false;

        is_plan_generated = plan_handler(target_pose);

        if (is_plan_generated)
        {
            if (goal_->command == "GTWP")
                is_plan_executed = execute_trajectory();

            else
            {
                is_plan_executed = execute_pose();
            }
            
        }

        if (is_plan_executed)
        {
            ROS_INFO("[move arm] Action success");
            action_server_.setSucceeded(result_);
        }
        else
        {
            ROS_INFO("[move arm] Action failed");
            action_server_.setAborted(result_);
        }
    }

    void gtPose()
    {
        ROS_INFO("[move arm] Start to move the robot to pose");
        geometry_msgs::Pose target_pose;

        target_pose = goal_->target_pose;

        //move_group.setMaxVelocityScalingFactor(MAX_VELOCITY);
        move_group.setPoseTarget(target_pose);
        //moveit::planning_interface::MoveGroupInterface::Plan my_plan;

        bool is_plan_generated = (bool)move_group.plan(motion_plan_);

        if (is_plan_generated)
        {
            //move_group.move();
            if (execute_trajectory())
            {
                ROS_INFO("[move arm] Pose execution SUCCESS");
                action_server_.setSucceeded(result_);
            }
            else  // execution failure
            {
                ROS_INFO("[move arm] Pose execution FAILED");
                action_server_.setAborted(result_);

            }
            
        }

        else  // planning failure
        {
            ROS_INFO("[move arm] Pose Plannning FAILED");
            action_server_.setAborted(result_);
        }
        
    }



    bool execute_trajectory()
    {
        //send to execute
        control_msgs::FollowJointTrajectoryGoal goal;
        //goal.
        goal.trajectory.points.clear();
        goal.trajectory = motion_plan_.trajectory_.joint_trajectory;
        goal.trajectory.header.stamp = ros::Time::now();
        traj_client_->sendGoal(goal);
        int goal_size = goal.trajectory.points.size();
        double waiting_time = goal.trajectory.points[goal_size - 1].time_from_start.toSec() + 3.0;
        std::cout << "traj time : " << goal.trajectory.points[goal_size - 1].time_from_start.toSec() << std::endl;
        bool finished_before_timeout = traj_client_->waitForResult(ros::Duration((waiting_time)));

        if (finished_before_timeout)
        {
            actionlib::SimpleClientGoalState state = traj_client_->getState();
            ROS_INFO("Action finish: %s", state.toString().c_str());
            if (state == state.ABORTED || state == state.REJECTED)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            ROS_ERROR("Execution didn't finish on time");
            return false;
        }
        //end of execution
    }

    bool execute_pose()
    {
        move_group.move();
        move_group.clearPoseTarget();
        return true;
    }


    bool plan_handler(geometry_msgs::Pose target_pose)
    {
        moveit_msgs::RobotTrajectory trajectory;

        bool success = generate_motion_plan(trajectory, target_pose);

        if (success == true && goal_->command == "GTWP")
        {
            motion_plan_.trajectory_ = trajectory;
            return true;
        }
        else
        {
            ROS_ERROR("Unable to generate plan ");
            return false;
        }
    }


    bool generate_motion_plan(moveit_msgs::RobotTrajectory &planned_trajectory, geometry_msgs::Pose target_pose)
    {
        if (goal_->command == "GTWP") {
        const double jump_threshold = 0.0;
        const double eef_step = 0.01;

        std::vector<geometry_msgs::Pose> waypoints;
        waypoints.clear();
        waypoints.push_back(target_pose);

        move_group.setStartStateToCurrentState();
        move_group.setEndEffectorLink(REF_EELINK);
        move_group.setPlanningTime(PLANNING_TIME);
        move_group.setPoseReferenceFrame(REF_FRAME);
        move_group.setMaxVelocityScalingFactor(MAX_VELOCITY);

        double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, planned_trajectory);
        if (fraction < 1.0)
        {
            std::cout << "Fraction value = " << fraction << std::endl;
            // return false;
        }
        
        return true;
        }

        else if (goal_->command == "GTP"){

        move_group.setPoseTarget(target_pose);
        bool success = (move_group.plan(my_plan_) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

        move_group.setStartStateToCurrentState();
        move_group.setPlanningTime(PLANNING_TIME);
        move_group.setPoseReferenceFrame(REF_FRAME);
        move_group.setMaxVelocityScalingFactor(MAX_VELOCITY);
std::cout << "check" << std::endl;
        return success;

        }
    }


};
}; // namespace robot_manipulation


int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_arm_action_server");
    ros::NodeHandle nh;

    ros::NodeHandle nh_priv("~");
    double RATE = 100;
    ros::Rate looprate(RATE);

    ros::AsyncSpinner async_spinner(1);
    async_spinner.start();
    robot_manipulation::MoveArmServer server;
    // ros::spin();
    while (ros::ok())
    {
        if (server.newGoalReceived())
        {
            // ROS_INFO("main: new move received");
            server.execute();
        }
    }
    ros::waitForShutdown();

    return 0;
}