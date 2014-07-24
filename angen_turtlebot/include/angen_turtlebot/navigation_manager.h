#include "ros/ros.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"
#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
#include "angen_turtlebot/navigaton_status.h"
#include <sstream>
#include <string>
#include "angen_turtlebot/key_handler.h"

#define POINTS 1
#define TOTAL_GOALS 7

static bool COMPLETE = false;

int g=0,h=0,v=0, m=0;
	
using namespace ros;
using namespace std;

class Select
{
	
	ros::Publisher point_selector;
	ros::Publisher goal_cancel;
	ros::Subscriber pose_confirm;
	ros::Publisher nav_status;
	ros::Subscriber abortc;
	
	ros::NodeHandle nodeh;
	std_msgs::Float64MultiArray point;
	std_msgs::String status;
	uint8_t u;
	
	//static bool hasreached;
	
	KeyHandler FR;
  public:
        
	uint8_t get_place_key();
        void extract() { FR.extract(); }
        void publish_points();
        void init_points();
        
        void callback(const geometry_msgs::PoseStamped::ConstPtr&);
        void abortcall(const std_msgs::UInt8::ConstPtr&);
        Select()
        {
        	goal_cancel = nodeh.advertise<actionlib_msgs::GoalID>("move_base/cancel", 1);
          	point_selector = nodeh.advertise<move_base_msgs::MoveBaseActionGoal>("move_base/goal", 10);
          	pose_confirm = nodeh.subscribe("current_pose", 10, &Select::callback, this);
          	nav_status = nodeh.advertise<std_msgs::String>("nav_status",1);
          	abortc = nodeh.subscribe<std_msgs::UInt8>("abort_signal",1, &Select::abortcall, this);
        }
};        

void Select::abortcall(const std_msgs::UInt8::ConstPtr& asignal)
{
 u =1;
 ROS_INFO("Navigation Error");
}

void Select::callback(const geometry_msgs::PoseStamped::ConstPtr& CurrentPose)
{
	                        if(u==1)
			   	{
			   	 status.data = "Aborting&" + FR.get_caller();
		                 if (++m == 1) {ROS_INFO("Status: %s", status.data.c_str());}
		                 nav_status.publish(status);
		                 ROS_INFO("Restarting Navigation");
		                 exit(0);
		                } 
		                
	if(KeyHandler::get_is_key_there())
	{
		if((POINTS - KeyHandler::get_current_point()) == 1)
		{
			if((abs(CurrentPose->pose.position.x - point.data[0]) < 0.5) &&
			   (abs(CurrentPose->pose.position.y - point.data[1]) < 0.5) &&
			   (abs(CurrentPose->pose.orientation.z - point.data[5]) < 0.5) &&
			   (abs(CurrentPose->pose.orientation.w - point.data[6]) < 0.5) )
			   {
			   	actionlib_msgs::GoalID current_goal_id;
			   	current_goal_id.id = "current_goal" + string(1,48+KeyHandler::get_current_point());
			   	goal_cancel.publish(current_goal_id);
			   	 status.data = "Complete&" + FR.get_caller();
		                 ROS_INFO("Status: %s", status.data.c_str());
		                 nav_status.publish(status);
			        COMPLETE = true;
			        KeyHandler::set_task_complete();
			        KeyHandler::reset_is_key_there();
				KeyHandler::reset_current_point();
				exit(0);
		   			
			   }
		}	   
			   
		else
		{
		        if (++g == 1 && u!=1)
		         {
		          status.data = "Started&" + FR.get_caller();
		          ROS_INFO("Status: %s", status.data.c_str());
		          nav_status.publish(status); 
		         }
		         else
		          {
		          if (u!=1) 
		          {
		           status.data = "Executing&" + FR.get_caller();
		           if (++h == 1) {ROS_INFO("Status: %s", status.data.c_str());}
		           nav_status.publish(status); 
		          }
		          }
			if((abs(CurrentPose->pose.position.x - point.data[0]) < 0.5) &&
			   (abs(CurrentPose->pose.position.y - point.data[1]) < 0.5))
			   {
			   	actionlib_msgs::GoalID current_goal_id;
			   	current_goal_id.id = "current_goal" + string(1,48+KeyHandler::get_current_point());
			   	goal_cancel.publish(current_goal_id);
				ROS_INFO("Moving To Way Point %d", (KeyHandler::get_current_point()+1));
				 
			   	if(POINTS-(KeyHandler::get_current_point())>1)
			   	{
			   	 	KeyHandler::inc_current_point();
			   	 	KeyHandler::set_ticket();
			   	}  		
		   			
			   }
		}
	}
}	

uint8_t Select::get_place_key()
{
	return FR.get_place_key();
}
		
void Select::publish_points()
{
	int current_point_temp = KeyHandler::get_current_point();
	point.set_data_size(7);
	int cnt = 7;
	while(cnt--) point.data[cnt] = FR.get_point_variable(current_point_temp, cnt);
	
	geometry_msgs::PoseStamped GoalPose;
	move_base_msgs::MoveBaseActionGoal Goal_Pose;
		
	GoalPose.pose.position.x = point.data[0];
	GoalPose.pose.position.y = point.data[1];
	GoalPose.pose.position.z = point.data[2];
		
	GoalPose.pose.orientation.x = point.data[3];
	GoalPose.pose.orientation.y = point.data[4];
	GoalPose.pose.orientation.z = point.data[5];
	GoalPose.pose.orientation.w = point.data[6];
		
	Goal_Pose.header.seq = GoalPose.header.seq = 1;
	Goal_Pose.header.frame_id = GoalPose.header.frame_id = "/map";
	Goal_Pose.goal.target_pose = GoalPose;
	Goal_Pose.goal_id.id = "current_goal" + string(1,48+KeyHandler::get_current_point());
	point_selector.publish(Goal_Pose);	
	KeyHandler::reset_ticket();
}
