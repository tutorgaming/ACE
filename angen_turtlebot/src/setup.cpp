#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include <iostream>
#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

//#define initialpx_r1 -0.104
//#define initialpy_r1 -0.122
//#define initialqz_r1 -0.086
//#define initialqw_r1 0.996

#define initialpx_r1 0.371
#define initialpy_r1 0.223
#define initialqz_r1 -0.086
#define initialqw_r1 0.996




//#define initialpx_r2 -7.279
//#define initialpy_r2 0.128
//#define initialqz_r2 -0.086
//#define initialqw_r2 0.996

#define initialpx_r2 0.006
#define initialpy_r2 -0.971
#define initialqz_r2 -0.086
#define initialqw_r2 0.996



using namespace std;
using namespace ros;

int main(int argc, char** argv)
{
	init(argc,argv,"setup");
	NodeHandle g;
        int i=4;
	/* Setting iniatial pose*/
	Publisher initial_pose_r1;
	initial_pose_r1 = g.advertise<geometry_msgs::PoseWithCovarianceStamped>("/robot1/initialpose", 1);
	geometry_msgs::PoseWithCovarianceStamped initial_r1;

	Publisher initial_pose_r2;
	initial_pose_r2 = g.advertise<geometry_msgs::PoseWithCovarianceStamped>("/robot2/initialpose", 1);
	geometry_msgs::PoseWithCovarianceStamped initial_r2;



        while(i--)
        {
	initial_r1.pose.pose.position.x = initialpx_r1;
	initial_r1.pose.pose.position.y = initialpy_r1;
	initial_r1.pose.pose.position.z = 0.0;
	initial_r1.pose.pose.orientation.x = 0.0;
	initial_r1.pose.pose.orientation.y = 0.0;
	initial_r1.pose.pose.orientation.z = initialqz_r1;
	initial_r1.pose.pose.orientation.w = initialqw_r1;

	initial_r2.pose.pose.position.x = initialpx_r2;
	initial_r2.pose.pose.position.y = initialpy_r2;
	initial_r2.pose.pose.position.z = 0.0;
	initial_r2.pose.pose.orientation.x = 0.0;
	initial_r2.pose.pose.orientation.y = 0.0;
	initial_r2.pose.pose.orientation.z = initialqz_r2;
	initial_r2.pose.pose.orientation.w = initialqw_r2;


	initial_r1.header.seq = 1;
	initial_r1.header.frame_id = "/map";

	initial_r2.header.seq = 1;
	initial_r2.header.frame_id = "/map";

	//initial.header.time = ros::Time::now();

	initial_pose_r1.publish(initial_r1);
	initial_pose_r2.publish(initial_r2);
        sleep(1);
        }
	return 0;

}
	
	
	
	
	
	
	

