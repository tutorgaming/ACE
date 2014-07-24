#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include <iostream>
#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#define initialpx 0.723
#define initialpy -1.200
#define initialqz -0.855
#define initialqw 0.519

#define get_readypx 0.897
#define get_readypy 0.239
#define get_readyqz -0.109
#define get_readyqw 0.994

using namespace std;
using namespace ros;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
	init(argc,argv,"getup");
	NodeHandle g;

	/* Setting iniatial pose*/
	Publisher initial_pose;
	initial_pose = g.advertise<geometry_msgs/PoseWithCovarianceStamped>("initialpose", 1);
	geometry_msgs::PoseWithCovarianceStamped initial;

	initial.pose.pose.position.x = initialpx;
	initial.pose.pose.position.y = initialpy;
	initial.pose.pose.position.z = 0.0;
	initial.pose.pose.orientation.x = 0.0;
	initial.pose.pose.orientation.y = 0.0;
	initial.pose.pose.orientation.z = initialqz;
	initial.pose.pose.orientation.w = initialqw;
		
	initial.header.seq = 1;
	initial.header.frame_id = "/map";
	initial.header.time = ros::Time::now();

	initial_pose.publish(initial);

	
	/* Localizing */
	Publisher initial_localise;
	initial_localie = g.advertise<geometry_msgs/Twist>("cmd_vel", 1);
	geometry_msgs::Twist localize;
	ros::Rate rate(2);
	
	int j = 7;
	while(j--)
	{
		for (int i = 0; i<10000; i++)
		{
			cmd.linear.x = (j == 0 ? -1 : 0)
			if(j!=0)
			cmd.angular.z = (j%2 == 0 ? 1 : -1);
			initial_localise.publish(localize);
			rate.sleep();
		}
	}

	/*Getting ready for the work*/
	MoveBaseClient get_ready("move_base", true);
	move_base_msgs::MoveBaseGoal ready;
	
        ready.target_pose.header.frame_id = "map";
 	ready.target_pose.header.stamp = ros::Time::now();

	ready.target_pose.pose.position.x = get_readypx;
	ready.target_pose.pose.position.y = get_readypy;
        ready.target_pose.pose.orientation.z =get_readyqz;
	ready.target_pose.pose.orientation.w =get_readyqw;

	get_ready.sendGoal(ready);
	get_ready.waitForResult();

	
	if(get_ready.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    		ROS_INFO("I am up and ready for commands");
  	 else
    		ROS_ERROR("Some problem occured during startup");
	
	return 0;

}
	
	
	
	
	
	
	

