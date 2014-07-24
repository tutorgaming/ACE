#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "angen_apps/angen_actuator_controls.h"
#include <math.h>

using namespace actuator_controls;
using namespace std;

#define window_open_yaw 0
#define window_close_yaw 1.57

int level; string window_joint;

void windowPoseCallback(const nav_msgs::Odometry::ConstPtr& epc)
{
      AngenActuatorControls ac;

      double window_joint_yaw =  atan2( 2*(epc->pose.pose.orientation.x*epc->pose.pose.orientation.y + epc->pose.pose.orientation.z*epc->pose.pose.orientation.w), 1 - 2*(epc->pose.pose.orientation.y*epc->pose.pose.orientation.y + epc->pose.pose.orientation.z*epc->pose.pose.orientation.z)); //converting quaternions to yaw 
      cout<<window_joint_yaw<<endl;
      if(level == 1) { if ((window_open_yaw - window_joint_yaw) < -0.011) ac.door_control(window_joint, level);               else {exit(0);}}
      if(level == -1) {if ((window_close_yaw - window_joint_yaw) > 0.011) ac.door_control(window_joint, level);                else {exit(0);}}
}
      
int main(int argc, char **argv)
{

  ros::init(argc, argv, "actuator_control");
  ros::NodeHandle nh;
  string actuator_pose_topic = string("/") + string(argv[1]) + string("/") + string(argv[3]) + string("_") +  string(argv[1]) + string("_pose");
  window_joint = argv[3] +  string("_window_joint"); 
  if(!std::string(argv[2]).compare("close"))
     level = -1;
  else if(!std::string(argv[2]).compare("open"))
     level = 1;
  ros::Subscriber ec_sub = nh.subscribe(actuator_pose_topic, 20, windowPoseCallback);
   while(ros::ok())
   ros::spin();
  return 0;
}
