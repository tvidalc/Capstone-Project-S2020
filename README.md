# Capstone-Project-S2020
ROS project for scanning architectural panels and various objects using GPIS algorithm. 

catkin_ws contains source code packages for robot control and Algorithm
thirdparty_ws contains all third party packages


Usage: 

1. Launch system to setup real robot, intel camera, and moveit nodes
$ roslaunch robotic_sensing system_start.launch

2. Start robot server to send motion commands 
$ roslaunch robot_motion_server move_arm_server.launch

3. Initialise GPIS algorithm with commandline arguments stating whats being scanned. panel option does a single scan from top view while object option obtains mutliple views
$ rosrun gpismap_ros gpismap3 _command:=panel   or   rosrun gpismap_ros gpismap3 _command:=object

4. perform a service call to start algorithm and robot server
$ rosservice call /srv_mapper_update "{}"

5. allow system to run and will auto terminate else for any issues hit ctrl-z on all terminals to cancel processes


Note: All commands must be entered in a new terminal 
