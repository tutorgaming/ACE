#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "angen_apps/angen_actuator_controls.h"
#include <math.h>

using namespace actuator_controls;
using namespace std;

#define door_open_yaw -0.928
#define door_close_yaw 1.569
#define window_open_yaw 0
#define window_close_yaw 1.57

int level; string actuator_joint; float act_goal_yaw;

void ActuatorPoseCallback(const nav_msgs::Odometry::ConstPtr& epc)
{
      AngenActuatorControls ac;

      double act_joint_yaw =  atan2( 2*(epc->pose.pose.orientation.x*epc->pose.pose.orientation.y + epc->pose.pose.orientation.z*epc->pose.pose.orientation.w), 1 - 2*(epc->pose.pose.orientation.y*epc->pose.pose.orientation.y + epc->pose.pose.orientation.z*epc->pose.pose.orientation.z)); //converting quaternions to yaw 
      
      if(level == 1) { if ((act_goal_yaw - act_joint_yaw) < -0.011) ac.door_control(actuator_joint, level);               else exit(0);}
      if(level == -1) {if ((act_goal_yaw - act_joint_yaw) > 0.011) ac.door_control(actuator_joint, level);                else exit(0);}
}

void error_notification() {  ROS_ERROR("Malformed arguments. Accepted format rosrun angen_apps actuator_control door/window open/close 'room_name'");  exit(0);  }

int main(int argc, char **argv)
{

  ros::init(argc, argv, "actuator_control");
  ros::NodeHandle nh;
  void error_notification();
  
  string actuator_pose_topic = string("/") + string(argv[1]) + string("/") + string(argv[3]) + string("_") +  string(argv[1]) + string("_pose");
  actuator_joint = argv[3] +  string("_") + string(argv[1]) + string("_joint"); 
  
 
  if(!std::string(argv[2]).compare("close"))
        { 
           level = -1; 
           if (!std::string(argv[1]).compare("door")) {act_goal_yaw = door_close_yaw;} 
          else if (!std::string(argv[1]).compare("window")) {act_goal_yaw = window_close_yaw;} 
          else {error_notification();} 
        }
        
 else if(!std::string(argv[2]).compare("open"))
        { 
           level = 1; 
           if (!std::string(argv[1]).compare("door")) {act_goal_yaw = door_open_yaw;}   
           else if (!std::string(argv[1]).compare("window")) {act_goal_yaw = window_open_yaw;}
           else {error_notification(); } 
        }
 else {error_notification();}
   
  ros::Subscriber ac_sub = nh.subscribe(actuator_pose_topic, 20, ActuatorPoseCallback);
    
  while(ros::ok())
       ros::spin();

  return 0;
}
