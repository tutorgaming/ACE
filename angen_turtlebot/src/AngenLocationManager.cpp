

#include <cstdio>
#include "tf/transform_listener.h"
#include "tf/transform_datatypes.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
//#include "KeyManager.cpp"
#include "NavigationManager.cpp"
#include <stdlib.h>


using namespace std;

int main(int argc, char ** argv){

	//Initialize ROS
	ros::init(argc, argv, "AngenLocationManager", ros::init_options::AnonymousName);
	ros::NodeHandle nh;

	cout << "NODE INIT" << endl;

//	KeyManager man("angen_topological.txt", nh);
//	if(argc<2){cout << "PLEASE PROVIDE THE SUFFIX FOR TOPICS' PUBLICATION. ABORTING..."; exit(0);}

	NavigationManager man("angen_topological.txt",  nh);
//	NavigationManager man("angen_topological.txt",  nh);


	ros::Publisher goalPublisher=	nh.advertise<move_base_msgs::MoveBaseActionGoal>("move_base/goal", 1);

	ros::Rate loop_rate(1);

	move_base_msgs::MoveBaseActionGoal goalMsg;


	while (nh.ok()){


//		if(man.currentGoal!=NULL){
//			man.goalPublisher.publish(*man.currentGoal);
//			cout << "PUBLISHING" << endl;
//		}
		//cout << "PUBLISHING" << endl;
		geometry_msgs::PoseStamped pose;
			move_base_msgs::MoveBaseActionGoal goal;

//			goal.header.stamp=ros::Time::now();
//			goal.goal.target_pose.header.stamp=ros::Time::now();
//
//
//			pose.pose.position.x = 0.0;
//			pose.pose.position.y = 1;
//			pose.pose.position.z = 2;
//
//			pose.pose.orientation.x = 0;
//			pose.pose.orientation.y = 0;
//			pose.pose.orientation.z = 0;
//			pose.pose.orientation.w = 1;
//
//			goal.header.seq = pose.header.seq = 1;
//			goal.header.frame_id = pose.header.frame_id = "/map";
//			goal.goal.target_pose = pose;
//			goal.goal_id.id = "";//"current_goal" + st
//
//			goalPublisher.publish(goal);

		man.publishGoal();
		ros::spinOnce ();
		loop_rate.sleep ();
	}

	return 0;
}
