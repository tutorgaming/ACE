#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "angen_apps/angen_actuator_controls.h"

using namespace actuator_controls;
using namespace std;

int level;
double gap_between_floors;

void ElevatorPoseCallback(const nav_msgs::Odometry::ConstPtr& epc)
{
  AngenActuatorControls ac;
  float z_diff;
  if(level == 5) z_diff = ((3.325 + gap_between_floors) - epc->pose.pose.position.z); 
  else z_diff = (epc->pose.pose.position.z - 0);      
  //cout<<z_diff<<endl;
  if(abs(z_diff) > .3) ac.elevator_control(level);
  else exit(0);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "elevator_control");
  ros::NodeHandle nh;
  
  nh.param("/gap_between_floors", gap_between_floors, 0.1);
  
  if(argc != 3)
        { ROS_ERROR("Improper input! Requires 2 arguments. Format: rosrun angen_apps elevator_control goto floor1/floor0"); exit(0); }
  else
        {
                if(!std::string(argv[2]).compare("floor1"))
                       level = 5;
                else if(!std::string(argv[2]).compare("floor0"))
                        level = -5;
                else 
                      { ROS_ERROR("Improper input! Format: rosrun angen_apps elevator_control goto floor1/floor0"); exit(0); }
         }                

 ros::Subscriber ec_sub = nh.subscribe("/elevator/elevator_pose", 20, ElevatorPoseCallback);

  while(ros::ok())
    ros::spin();
  
  return 0;
}
