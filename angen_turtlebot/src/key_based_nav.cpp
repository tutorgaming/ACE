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
#include "angen_turtlebot/navigation_command.h"

#include <sstream>
#include <string>
#define POINTS 1
#define TOTAL_GOALS 12


angen_turtlebot::navigaton_status message;
static bool COMPLETE = false;
int g=0,h=0,v=0, m=0;
	
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
	map<char, int> char2intLoc;


	
	struct dictionary
	{
		float a[POINTS][7];
		char key;
				
	}dict[TOTAL_GOALS];
	
 public:	


	void printSinglePoint(struct dictionary d){
		cout << "Key: " << d.key << " : " <<endl;
		for(int i=0; i< 7; i++){cout << " " << (float) d.a[0][i]<< " ";}
		cout << endl;
	}

	void printDictionary(){
		cout << "============================"<< endl;
		for(int i =0; i<TOTAL_GOALS;i++ ){
			printSinglePoint(dict[i]);
			}
		cout << "============================"<< endl;

	}



 	KeyHandler()
 	{
 		key_getter = nodeh.subscribe("room_key", 1, &KeyHandler::callback, this);
 		//caller = nodeh.subscribe<std_msgs::String>("caller",1, &KeyHandler::callerback, this);
 		place_key = 'h';
 		char2intLoc.insert(make_pair('a', 0));
 		char2intLoc.insert(make_pair('b', 1));
 		char2intLoc.insert(make_pair('c', 2));
 		char2intLoc.insert(make_pair('d', 3));
 		char2intLoc.insert(make_pair('e', 4));
 		char2intLoc.insert(make_pair('f', 5));
 		char2intLoc.insert(make_pair('g', 6));
 		char2intLoc.insert(make_pair('h', 7));
 		char2intLoc.insert(make_pair('i', 8));
 		char2intLoc.insert(make_pair('l', 9));
 		char2intLoc.insert(make_pair('m', 10));
 		char2intLoc.insert(make_pair('n', 11));


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
 	
 	void callback(const angen_turtlebot::navigation_command::ConstPtr& key);

 	//void callerback(const std_msgs::String::ConstPtr&);
 	
 	void extract()
 	{
 		std::string filename = "goals.inputfile";
 		a_file.open(filename.c_str());
 		if(!a_file.is_open())
 		{ 
 			printf("ERROR OPENING FILE... Please ensure that the file, \"%s\" is there in the directory from which you 'make' the package. Press a key to exit.",  filename.c_str());
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

float KeyHandler::get_point_variable(int c, int b)
{

	cout << "place key" << place_key<< endl;
	cout << "C "<< c << " B " << b <<"RESULT: " <<place_key-97  << endl;

	map<char, int>::iterator it=char2intLoc.find(place_key);

	cout << "with map" << it->second<< endl;
	printSinglePoint(dict[it->second]);
 	return dict[it->second].a[c][b];
}


int KeyHandler::current_point = 0;
bool KeyHandler::is_key_there = false;
bool KeyHandler::ticket = false;
bool KeyHandler::task_complete = true;


void KeyHandler::callback(const angen_turtlebot::navigation_command::ConstPtr& key)
{
	if(KeyHandler::task_complete)
	{
		KeyHandler::is_key_there = true;	
		KeyHandler::ticket = true;
		KeyHandler::reset_current_point();
		KeyHandler::task_complete = false;
		place_key = key->location;
		callerr= key->caller;
		ROS_INFO("Key obtained: %c", place_key);
	}	
} 

//void KeyHandler::callerback(const angen_turtlebot::navigation_command::ConstPtr& caller)
//{
// callerr = std::string(caller->data.c_str());
// ROS_INFO("Action Initiated by: %s", caller->data.c_str());
//}
/**************************************************************************************************************************************************************************/

class Select
{
	
	ros::Publisher point_selector;
	ros::Publisher goal_cancel;
	ros::Subscriber pose_confirm;
	ros::Publisher nav_status;
	ros::Subscriber abortc;
	
	ros::NodeHandle nodeh;
	std_msgs::Float64MultiArray point;
	angen_turtlebot::navigaton_status status;
	uint8_t u;
	
	//static bool hasreached;
	
  public:
	KeyHandler FR;

	uint8_t get_place_key();
        void extract() { FR.extract(); }
        void publish_points();
        void init_points();
        
        void callback(const geometry_msgs::PoseStamped::ConstPtr&);
        void abortcall(const std_msgs::UInt8::ConstPtr&);
        Select()
        {
        	u=0;
        	goal_cancel = nodeh.advertise<actionlib_msgs::GoalID>("move_base/cancel", 1);
          	point_selector = nodeh.advertise<move_base_msgs::MoveBaseActionGoal>("move_base/goal", 10);
          	nav_status = nodeh.advertise<angen_turtlebot::navigaton_status>("nav_status",1);

          	abortc = nodeh.subscribe<std_msgs::UInt8>("abort_signal",1, &Select::abortcall, this);
          	pose_confirm = nodeh.subscribe("current_pose", 10, &Select::callback, this);

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
			   	 status.status = "Aborting";
			   	 status.caller= FR.get_caller();
		                 if (++m == 1) {ROS_INFO("Status: %s, Caller %s\n", status.status.c_str(), status.caller.c_str());}
		                 nav_status.publish(status);
		                 ROS_INFO("Restarting Navigation");
		                 exit(0);
		                }
		                
	if(KeyHandler::get_is_key_there())
	{
		if((POINTS - KeyHandler::get_current_point()) == 1)
		{
			if((abs(CurrentPose->pose.position.x - point.data[0]) < 0.5) &&
			   (abs(CurrentPose->pose.position.y - point.data[1]) < 0.5) )
			   {
			   	actionlib_msgs::GoalID current_goal_id;
			   	current_goal_id.id = "current_goal" + string(1,48+KeyHandler::get_current_point());
			   	goal_cancel.publish(current_goal_id);
			   	 //status.data = "Complete&" + FR.get_caller();
			   	status.status ="Complete";
			   	status.caller = FR.get_caller();
			   			ROS_INFO("Status: %s, Caller %s\n", status.status.c_str(), status.caller.c_str());
		                 nav_status.publish(status);
			        COMPLETE = true;
			        KeyHandler::set_task_complete();
			        KeyHandler::reset_is_key_there();
				KeyHandler::reset_current_point();
				cout << "COMPLETE, HOPE IT RESTARTS" << endl;
				exit(0);
		   			
			   }
		}	   
			   
		else
		{
		        if (++g == 1 && u!=1)
		         {
		          status.status = "Started";
		          status.caller= FR.get_caller();
		          ROS_INFO("Status: %s, Caller %s\n", status.status.c_str(), status.caller.c_str());
		          nav_status.publish(status); 
		         }
		         else
		          {
		          if (u!=1) 
		          {
		           status.status = "Executing";
		           status.caller= FR.get_caller();
		           if (++h == 1) {ROS_INFO("Status: %s, Caller %s\n", status.status.c_str(), status.caller.c_str());}
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

	cout <<"PUBLISH POINT FUNCTION"<< endl;
	this->init_points();
	
	geometry_msgs::PoseStamped pose;
	move_base_msgs::MoveBaseActionGoal goal;

	goal.header.stamp=ros::Time::now();
	goal.goal.target_pose.header.stamp=ros::Time::now();

		
	pose.pose.position.x = point.data[0];
	pose.pose.position.y = point.data[1];
	pose.pose.position.z = point.data[2];
		
	pose.pose.orientation.x = point.data[3];
	pose.pose.orientation.y = point.data[4];
	pose.pose.orientation.z = point.data[5];
	pose.pose.orientation.w = point.data[6];
		
	goal.header.seq = pose.header.seq = 1;
	goal.header.frame_id = pose.header.frame_id = "/map";
	goal.goal.target_pose = pose;
	goal.goal_id.id = "";//"current_goal" + string(1,48+KeyHandler::get_current_point());
	for(int k=0;k<5;k++){
		//cout << "I AM NOT PUBLISHING, I HAVE COMMENTED THE CODE" << endl;
		point_selector.publish(goal);
		cout << "PUBLISHING" << endl;
	}
	KeyHandler::reset_ticket();
}    

void Select::init_points()
{
	int current_point_temp = KeyHandler::get_current_point();
	point.set_data_size(7);
	int cnt = 7;
	while(cnt--) point.data[cnt] = FR.get_point_variable(current_point_temp, cnt);
}

/*void Select::printWayPoints()
{
	int current_point_temp = KeyHandler::get_current_point();
	point.set_data_size(7);
	int cnt = 7;
	while(cnt--) point.data[cnt] = FR.get_point_variable(current_point_temp, cnt);
}*/

	 
int main(int argc, char **argv)
{
	ros::init(argc, argv, "key_based_nav");
	Select sel;
	sel.extract();

	sel.FR.printDictionary();




	while(ros::ok() && !COMPLETE)
	{
		if(KeyHandler::get_is_key_there())
		{
			if(KeyHandler::get_ticket())
			{
				if(sel.get_place_key() == 'h')				
				{
					KeyHandler::reset_ticket();
					KeyHandler::reset_is_key_there();
					KeyHandler::set_task_complete();
				}

				else sel.publish_points();
			}		
		}
		else
		{if (v==5) ROS_INFO("Waiting for Room Key");
		v++;}
		ros::getGlobalCallbackQueue()->callAvailable(ros::WallDuration(1.0));

	}	
	COMPLETE = false;
	KeyHandler::reset_is_key_there();
	KeyHandler::set_task_complete();
	KeyHandler::reset_ticket();
	ros::spin();
}
