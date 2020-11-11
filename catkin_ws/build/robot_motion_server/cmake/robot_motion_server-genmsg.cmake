# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robot_motion_server: 7 messages, 0 services")

set(MSG_I_FLAGS "-Irobot_motion_server:/home/abdel/catkin_ws/devel/share/robot_motion_server/msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robot_motion_server_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" "robot_motion_server/MoveArmActionResult:actionlib_msgs/GoalID:std_msgs/Header:robot_motion_server/MoveArmActionFeedback:robot_motion_server/MoveArmGoal:geometry_msgs/Quaternion:robot_motion_server/MoveArmFeedback:geometry_msgs/Point:robot_motion_server/MoveArmResult:robot_motion_server/MoveArmActionGoal:geometry_msgs/Pose:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" "geometry_msgs/Pose:std_msgs/Header:robot_motion_server/MoveArmGoal:geometry_msgs/Quaternion:geometry_msgs/Point:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" "robot_motion_server/MoveArmResult:actionlib_msgs/GoalID:std_msgs/Header:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" "robot_motion_server/MoveArmFeedback:actionlib_msgs/GoalID:std_msgs/Header:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" ""
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Point"
)

get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_custom_target(_robot_motion_server_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robot_motion_server" "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_cpp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
)

### Generating Services

### Generating Module File
_generate_module_cpp(robot_motion_server
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robot_motion_server_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robot_motion_server_generate_messages robot_motion_server_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_cpp _robot_motion_server_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_motion_server_gencpp)
add_dependencies(robot_motion_server_gencpp robot_motion_server_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_motion_server_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)
_generate_msg_eus(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
)

### Generating Services

### Generating Module File
_generate_module_eus(robot_motion_server
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(robot_motion_server_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(robot_motion_server_generate_messages robot_motion_server_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_eus _robot_motion_server_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_motion_server_geneus)
add_dependencies(robot_motion_server_geneus robot_motion_server_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_motion_server_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)
_generate_msg_lisp(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
)

### Generating Services

### Generating Module File
_generate_module_lisp(robot_motion_server
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robot_motion_server_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robot_motion_server_generate_messages robot_motion_server_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_lisp _robot_motion_server_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_motion_server_genlisp)
add_dependencies(robot_motion_server_genlisp robot_motion_server_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_motion_server_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)
_generate_msg_nodejs(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
)

### Generating Services

### Generating Module File
_generate_module_nodejs(robot_motion_server
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(robot_motion_server_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(robot_motion_server_generate_messages robot_motion_server_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_nodejs _robot_motion_server_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_motion_server_gennodejs)
add_dependencies(robot_motion_server_gennodejs robot_motion_server_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_motion_server_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)
_generate_msg_py(robot_motion_server
  "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
)

### Generating Services

### Generating Module File
_generate_module_py(robot_motion_server
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robot_motion_server_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robot_motion_server_generate_messages robot_motion_server_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmAction.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmActionFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmResult.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmGoal.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/abdel/catkin_ws/devel/share/robot_motion_server/msg/MoveArmFeedback.msg" NAME_WE)
add_dependencies(robot_motion_server_generate_messages_py _robot_motion_server_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robot_motion_server_genpy)
add_dependencies(robot_motion_server_genpy robot_motion_server_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robot_motion_server_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robot_motion_server
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(robot_motion_server_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(robot_motion_server_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(robot_motion_server_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/robot_motion_server
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(robot_motion_server_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(robot_motion_server_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(robot_motion_server_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robot_motion_server
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(robot_motion_server_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(robot_motion_server_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(robot_motion_server_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/robot_motion_server
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(robot_motion_server_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(robot_motion_server_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(robot_motion_server_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robot_motion_server
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(robot_motion_server_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(robot_motion_server_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(robot_motion_server_generate_messages_py std_msgs_generate_messages_py)
endif()
