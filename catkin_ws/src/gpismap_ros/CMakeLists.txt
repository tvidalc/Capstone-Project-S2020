cmake_minimum_required(VERSION 2.8.3)
project(gpismap_ros)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  tf2
  sensor_msgs
  std_srvs
  visualization_msgs
  pcl_ros
  image_transport
  image_geometry
  message_filters
  depth_image_proc
  roslib
  cv_bridge

  actionlib_msgs
  geometry_msgs
  actionlib
  genmsg
  tf_conversions
)

## System dependencies
find_package(Boost REQUIRED COMPONENTS thread system program_options)
find_package(Eigen3 REQUIRED)
find_package(PCL 1.7 REQUIRED)
find_package(OpenCV REQUIRED)


## Generate actions in the 'action' folder
add_action_files(
  FILES
  MoveArm.action
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  actionlib_msgs   geometry_msgs   std_msgs
)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
# catkin_python_setup()


################################################
## Declare ROS dynamic reconfigure parameters ##
################################################


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
    CATKIN_DEPENDS
    roscpp rospy tf tf2 pcl_ros image_transport
        sensor_msgs  std_srvs  visualization_msgs
        image_geometry message_filters depth_image_proc roslib
  CATKIN_DEPENDS actionlib_msgs geometry_msgs roscpp rospy 
         DEPENDS
#        BOOST
#        EIGEN3
         OpenCV

)

###########
## Build ##
########### 

#message("Boost_INCLUDE_DIRS is ${Boost_INCLUDE_DIRS}")

add_definitions(${PCL_DEFINITIONS})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
#  ${EIGEN3_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/mrc_common.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#message("OpenCV_LIBRARIES is ${OpenCV_LIBRARIES}")

add_executable(gpismap3
        src/gpis3_main.cpp
        src/gp/covFnc.cpp
        src/gp/ObsGP.cpp
        src/gp/OnGPIS.cpp
        src/gp/strct.cpp
        src/gp/octree.cpp
        src/gp/GPisMap3.cpp
        src/isosurface/IsoSurfaceExtraction.cpp
        )

#target_include_directories(pile_mapper ${OpenCV_INCLUDE_DIRS})

target_link_libraries(
        gpismap3
        ${catkin_LIBRARIES}
        ${Boost_LIBRARIES}
        ${YAML_CPP_LIBRARIES}
        ${OpenCV_LIBRARIES}
)
add_dependencies(
        gpismap3
        ${catkin_EXPORTED_TARGETS}
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_actionlib_tutorials.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
