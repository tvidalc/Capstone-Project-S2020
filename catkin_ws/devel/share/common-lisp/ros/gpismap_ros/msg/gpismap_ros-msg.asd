
(cl:in-package :asdf)

(defsystem "gpismap_ros-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MoveArmAction" :depends-on ("_package_MoveArmAction"))
    (:file "_package_MoveArmAction" :depends-on ("_package"))
    (:file "MoveArmActionFeedback" :depends-on ("_package_MoveArmActionFeedback"))
    (:file "_package_MoveArmActionFeedback" :depends-on ("_package"))
    (:file "MoveArmActionGoal" :depends-on ("_package_MoveArmActionGoal"))
    (:file "_package_MoveArmActionGoal" :depends-on ("_package"))
    (:file "MoveArmActionResult" :depends-on ("_package_MoveArmActionResult"))
    (:file "_package_MoveArmActionResult" :depends-on ("_package"))
    (:file "MoveArmFeedback" :depends-on ("_package_MoveArmFeedback"))
    (:file "_package_MoveArmFeedback" :depends-on ("_package"))
    (:file "MoveArmGoal" :depends-on ("_package_MoveArmGoal"))
    (:file "_package_MoveArmGoal" :depends-on ("_package"))
    (:file "MoveArmResult" :depends-on ("_package_MoveArmResult"))
    (:file "_package_MoveArmResult" :depends-on ("_package"))
  ))