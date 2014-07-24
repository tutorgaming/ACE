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

#define POINTS 1
#define TOTAL_GOALS 7

static bool COMPLETE = false;

	
using namespace ros;
using namespace std;

class KeyHandler
{
	ros::Subscriber key_getter;
	ros::Subscriber caller;
	
	ros::NodeHandle nodeh;
	uint8_t place_key;
	std::string callerr;
	int s;
	int count1;
	ifstream a_file;
		
	static int current_point;
	static bool is_key_there;
	static bool ticket;
	static bool task_complete;
	
	struct dictionary
	{
		float a[POINTS][7];
		char key;
				
	}dict[TOTAL_GOALS];
	
 public:	
 	KeyHandler()
 	{
 		key_getter = nodeh.subscribe("room_key", 1, &KeyHandler::callback, this);
 		caller = nodeh.subscribe<std_msgs::String>("caller",1, &KeyHandler::callerback, this);
 		place_key = 'h';
 	} 
 	
 	uint8_t get_place_key() { return place_key; }
 	
 	static void set_is_key_there() { is_key_there = true; }
 	static void reset_is_key_there() { is_key_there = false; }
 	static bool get_is_key_there() { return KeyHandler::is_key_there; }
 	
 	static void inc_current_point() { KeyHandler::current_point++; }
 	static void reset_current_point() { KeyHandler::current_point = 0; }	
 	static int get_current_point() { return KeyHandler::current_point; }
 	
 	static void set_ticket() { ticket = true; }
 	static void reset_ticket() { ticket = false; }
 	static bool get_ticket() { return KeyHandler::ticket; }
 		
 	static void set_task_complete() { task_complete = true; }
 	static void reset_task_complete() { task_complete = false; }
 	static bool get_task_complete() { return KeyHandler::task_complete; }
	 	
 	float get_point_variable(int c, int b);
 	std::string get_caller() { return callerr; }
 	
 	void callback(const std_msgs::UInt8::ConstPtr&);
 	void callerback(const std_msgs::String::ConstPtr&);
 	
 	void extract()
 	{
 		std::string filename = "goals.inputfile";
 		a_file.open(filename.c_str());
 		if(!a_file.is_open())
 		{ 
 			ROS_ERROR("ERROR OPENING FILE",  filename.c_str());
 			getchar();
	 		exit(0);
	 	}	 	
	 	
	 	for(int goal = 0; goal < TOTAL_GOALS; goal++)
	 	{
	 		a_file>>dict[goal].key;
	 	
 			for(count1=0;count1<POINTS; count1++)
 			{
				a_file>>(s);
				for(int i =0; i<7; i++)			
				a_file>>dict[goal].a[count1][i];	
			}
		}	
	}	
};

int KeyHandler::current_point = 0;
bool KeyHandler::is_key_there = false;
bool KeyHandler::ticket = false;
bool KeyHandler::task_complete = true;

float KeyHandler::get_point_variable(int c, int b)
{
 	return dict[place_key-97].a[c][b];
}

void KeyHandler::callback(const std_msgs::UInt8::ConstPtr& key)
{
	if(KeyHandler::task_complete)
	{
		KeyHandler::is_key_there = true;	
		KeyHandler::ticket = true;
		KeyHandler::reset_current_point();
		KeyHandler::task_complete = false;
		place_key = key->data;  
		ROS_INFO("Key obtained: %c", place_key);
	}	
} 

void KeyHandler::callerback(const std_msgs::String::ConstPtr& caller)
{
 callerr = std::string(caller->data.c_str());
 ROS_INFO("Action Initiated by: %s", caller->data.c_str());
}
