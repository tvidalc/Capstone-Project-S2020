#include <robotic_sensing/robot.h>


Robot::Robot(ros::NodeHandle &nh) 
: nh_(nh)
, move_group("manipulator")
, sub(nh_.subscribe < pcl::PointCloud<pcl::PointXYZ> > ("position", 2, &Robot::callback, this))
{

  //sub = nh_.subscribe < pcl::PointCloud<pcl::PointXYZ> > ("position", 2, &Robot::callback, this);
  move_group.allowReplanning(true);
  move_group.setNumPlanningAttempts(5);
  move_group.setPoseReferenceFrame("world");
  move_group.setNamedTarget("posDown");
  desired_robot_position = {0, -1.29, 1.5, 0, 1.57, 0};  
  



}



void 
Robot::robotInit() {                                                                                          // robotIinit()

  std::cout << "From init\n\n" << std::endl;

 // move_group.setNamedTarget("posDown");

  for (int i = 0; i<move_group.getCurrentJointValues().size();i++) 
  {

    robot_joint_values.push_back (move_group.getCurrentJointValues()[i]);

    robot_joint_values[i] = (int)(robot_joint_values[i]*100 + .5);              // round off joint values
    robot_joint_values[i] = (float)(robot_joint_values[i]/100);

    ROS_INFO(" Check 1 %f", robot_joint_values[i]);
  }

  for (int i = 0; i < sizeof(desired_robot_position) / sizeof(desired_robot_position[0]); i++)
  ROS_INFO("Check 2 %f",desired_robot_position[i]);


  if (robot_joint_values != desired_robot_position) 
  {

    move_group.setStartStateToCurrentState();
    move_group.plan(my_plan);
    bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    ROS_INFO("Visualising plan: %s", success?"Success": "FAILED to find plan");

    if (success == true) 
    { 
      ROS_INFO("executing plan");
      move_group.execute(my_plan);    // dangerous - make sure real robot is clear of obsticles 
    }           

    else ROS_INFO(" Unable to execute as no plan was found");

  }

  else ROS_INFO("Robot already at desired position %s", "test");

} 



void 
Robot::control(pcl::PointXYZ point)                                                                            // control
{

  std::cout << "start control\n\n" << std::endl;

  std::cout << "From control\n\n" << std::endl;

  static bool initialised = false;
  if (!initialised) {

    robotInit();

    initialised = true;
  } 

  move_group.clearPoseTargets();

  target_pose = move_group.getCurrentPose().pose;
  target_pose.position.x = point.x;
  target_pose.position.y = point.y;
  target_pose.position.z = point.z;
  move_group.setPoseTarget(target_pose);

  ros::Duration(0.5).sleep();
  bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  /*while (!success) //keep trying until a plan is found
  {
    success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  }*/
            
  if(!success) //execute
  throw std::runtime_error("No plan found");

  //move_group.move(); //blocking

}
 


    
void Robot::callback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& msg)                                  // callback
    {

  std::cout << "From subscriber\n\n" << std::endl;

  std::cout << msg->points.at(0).x << "   "  << msg->points.at(0).y  << "   "  << msg->points.at(0).z  << std::endl;

  pcl::PointXYZ point;
  point.x = msg->points.at(0).x;
  point.y = msg->points.at(0).y;
  point.z = msg->points.at(0).z;

  std::cout << "end subscriber\n\n" << std::endl;
    
  control(point);

 }
 


int main(int argc, char** argv)
{
  ros::init(argc, argv, "sub_position");
  ros::NodeHandle nh;
    ros::AsyncSpinner spinner(2);
  spinner.start();

  Robot robot(nh);

  std::cout << "end of loop" << std::endl;
   
  // ros::AsyncSpinner spinner(1);
  // spinner.start();
  //ros::spin();
}
