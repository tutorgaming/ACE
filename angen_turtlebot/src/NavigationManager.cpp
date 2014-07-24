

#include <cstdio>
#include "tf/transform_listener.h"
#include "tf/transform_datatypes.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"

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

#include "angen_turtlebot/navigaton_status.h"


//#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
//#include "angen_turtlebot/navigaton_status.h"
//#include "angen_turtlebot/navigation_command.h"

#include <sstream>
#include <string>


using namespace std;

//#include "AngenLocationManager.cpp"
#include "KeyManager.cpp"

class NavigationManager{

	private:

//		bool isGoalAchieved(geometry_msgs::PoseStamped a, geometry_msgs::PoseStamped b){
//			return (abs(a.pose.position.x-b.pose.position.x)<0.5 &&
//					abs(a.pose.position.y-b.pose.position.y)<0.5);
//		}

		// publishes the current state of the task + the requester of task execution
		void publishStatus(string status, string requester){
			angen_turtlebot::navigaton_status s;
			s.status=status;
			s.caller=requester;
			this->navigationStatusPublisher.publish(s);
		}

		// publishes the goal pose
		void sendGoal(){
			cout << "ENTERED" << endl;
//			move_base_msgs::MoveBaseActionGoal goal;
//			goal.header.seq = pose.header.seq = 1;
//			goal.header.frame_id = pose.header.frame_id = "/map";
//			goal.goal.target_pose = pose;
//			goal.goal_id.id = "";//"current_goal" + string(1,48+KeyHa
//			this->goalPublisher.publish(goal);
//			cout << "GOAL PUBLISHING" << endl;
			geometry_msgs::PoseStamped pose;
			goal.header.stamp=ros::Time::now();
			goal.goal.target_pose.header.stamp=ros::Time::now();


			pose.pose.position.x = this->currentGoal->pose.position.x;
			pose.pose.position.y = this->currentGoal->pose.position.y;;
			pose.pose.position.z = this->currentGoal->pose.position.z;;

			pose.pose.orientation.x = this->currentGoal->pose.orientation.x;;
			pose.pose.orientation.y = this->currentGoal->pose.orientation.y;;
			pose.pose.orientation.z = this->currentGoal->pose.orientation.z;;
			pose.pose.orientation.w = this->currentGoal->pose.orientation.w;;

						goal.header.seq = pose.header.seq = 1;
						goal.header.frame_id = pose.header.frame_id = "/map";
						goal.goal.target_pose = pose;
						goal.goal_id.id = "";//"current_goal" + st
						cout << "QUA" << endl;
						for(int i=0;i<5;i++){
							this->goalPublisher.publish(goal);
						}

//			goalMsg.header.seq = pose.header.seq = 1;
//			goalMsg.header.frame_id = pose.header.frame_id = "/map";
//			goalMsg.goal.target_pose = pose;
//			goalMsg.goal_id.id = "";//"current_goal" + string(1,48+KeyHa
//			this->goalPublisher.publish(goalMsg);
			cout << "GOAL PUBLISHING" << endl;

			sleep(1);
		}


	public:

		KeyManager 		*locationManager;

		ros::Publisher	goalPublisher;		//**
//		ros::Publisher	goalAbortingPublisher;
		ros::Publisher	navigationStatusPublisher; //**

		ros::Subscriber currentPoseListener;
//		ros::Subscriber abortNavigationListener;

//		ros::Subscriber locationSubscriber;
//		ros::Subscriber requesterSubscriber;



		ros::Subscriber navigationRequestListener;	//** it is a listener in the main
		ros::Subscriber rosNavStatus;

		move_base_msgs::MoveBaseActionGoal goal;
		bool flagToPublish;





		bool						navigationExecuting;
		geometry_msgs::PoseStamped *currentGoal;
		string 						currentLocation;
		string 						requester;


		// suffix is not necessary: it is entailed in the ns
		NavigationManager(string inputFile,ros::NodeHandle& nh){

			this->locationManager		=	new KeyManager(inputFile, nh);

			goalPublisher				=	nh.advertise<move_base_msgs::MoveBaseActionGoal>("move_base/goal", 1);
          	navigationStatusPublisher	=	nh.advertise<angen_turtlebot::navigaton_status>("nav_status",1);

          	navigationRequestListener=
          			nh.subscribe("navigation_request", 10, &NavigationManager::navigationRequestCallback, this);
          	rosNavStatus 				=
          			nh.subscribe<std_msgs::UInt8>("abort_signal",1, &NavigationManager::abortCall, this);
          	currentPoseListener 		=
          			nh.subscribe<geometry_msgs::PoseStamped>("current_pose",1,&NavigationManager::poseCallback, this);
          	this->navigationExecuting	=	false;
          	this->currentGoal			= 	NULL;
          	this->flagToPublish=false;
		}

		void poseCallback(const geometry_msgs::PoseStamped::ConstPtr& currentPose){


//			cout << "RECEIVING POSE " << currentPose->pose << endl;

			if(currentGoal==NULL){cout << "poseCallback GOAL NULL" << endl; return;}
			cout << "CURRENT ERROR: " << endl;
			cout << "===========================" << endl;
			cout << abs(currentPose->pose.position.x-this->currentGoal->pose.position.x) << " ";
			cout << abs(currentPose->pose.position.y-this->currentGoal->pose.position.y) << endl;
			cout << "===========================" << endl;
			if(this->currentGoal!=NULL){
				if(	abs(currentPose->pose.position.x-this->currentGoal->pose.position.x)<0.5 &&
						abs(currentPose->pose.position.y-this->currentGoal->pose.position.y)<0.5){
					this->publishStatus("Complete", this->requester);
					this->navigationExecuting	=	false;
				}
				else{this->publishStatus("Executing", this->requester);}
			}
		}

//		void locationCallback(const std_msgs::String::ConstPtr& key){
//
//			geometry_msgs::PoseStamped *paux=this->locationManager->getLocation(key->data);
//
//			if(this->navigationExecuting){
//				cout << "Received " << key->data << " BUT STILL EXECUTING " << this->currentGoal << endl;
//			}
//			else{
//				this->currentLocation=key->data;
//				this->navigationExecuting=true;
//				this->currentGoal	=	this->locationManager->getLocation(this->currentLocation);
//				this->goalPublisher.publish(*(this->currentGoal));
//			}
//			cout << "RECEIVED GOAL LOCATION: " << key->data << endl;
//		}


		void abortCall(const std_msgs::UInt8::ConstPtr& asignal){
			this->currentGoal=NULL;
			publishStatus("Aborting", this->requester);
		}

		void navigationRequestCallback(const angen_turtlebot::navigaton_status::ConstPtr& msg){

			cout << "REQUEST RECEIVED" << endl;
			if(this->navigationExecuting){cout << "Received " <<
				msg->status << " BUT STILL EXECUTING " << this->currentLocation << endl;}
			else{
				this->currentLocation=msg->status;
				this->requester=msg->caller;
				this->navigationExecuting=true;
				this->currentGoal	=	this->locationManager->getLocation(this->currentLocation);
				cout << "ABOUT TO PUBLISH" << endl;
				flagToPublish=true;
				cout << "REQUEST: " << this->currentLocation << " FROM " << this->requester << endl;
				if(this->currentGoal==NULL){cout << "LOCATION REQUESTED NOT FOUND" << endl;}
				else{
					cout <<"LOCATION REQUESTED: " << endl;
					cout << *(this->currentGoal) << endl;
				}
//				this->publishGoal(*(this->currentGoal));
			}
		}

		void publishGoal(){


			if(flagToPublish){
				geometry_msgs::PoseStamped m;
				cout << "INSIDE HERE" << endl;
				if(this->currentGoal==NULL){cout << "LOCATION NULL" << endl; return;}
//				this->sendGoal(m);
				this->sendGoal();
				flagToPublish=false;
			}

		}

//		void requesterCallback(const std_msgs::String::ConstPtr& requester){
//			this->requester= requester->data;
//			cout << "REQUESTER IDENTITY " << requester->data << endl;
//			ROS_INFO("Action Initiated by: %s", requester->data.c_str());
//		}




};
