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
//#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
//#include "angen_turtlebot/navigaton_status.h"
//#include "angen_turtlebot/navigation_command.h"

#include <sstream>
#include <string>


using namespace std;




class KeyManager{

	private:


	public:
	string inputFile;
	map<string,geometry_msgs::PoseStamped> locations;







	KeyManager(){}

	KeyManager(string inputFile, 	ros::NodeHandle &nh){

		this->inputFile=inputFile;

		FILE* fp;
		char room[100];
		fp = fopen(this->inputFile.c_str(), "r+");
		float pose[7];
		if(fp==NULL){cout << "Errore apertura file: "<< this->inputFile << endl; exit(0);}


		cout << "PARSING INITIALIZATION" << endl;

		while(fscanf(fp, "%s\t%f %f %f %f %f %f %f\n", room,
				&(pose[0]),&(pose[1]),&(pose[2]),&(pose[3]),&(pose[4]),&(pose[5]),&(pose[6]))!=EOF){

			if(room[0]=='#'){continue;}
			geometry_msgs::PoseStamped msg;

			msg.header.stamp		= ros::Time::now();
			msg.pose.position.x 	= pose[0];
			msg.pose.position.y 	= pose[1];
			msg.pose.position.z 	= pose[2];
			msg.pose.orientation.x 	= pose[3];
			msg.pose.orientation.y 	= pose[4];
			msg.pose.orientation.z 	= pose[5];
			msg.pose.orientation.w 	= pose[6];

			msg.header.seq 			= 1;
			msg.header.frame_id		= "/map";
			msg.header.frame_id 	= "";
			this->locations.insert(std::make_pair(room,msg));
		}



//		this->requester		=	"NONE";
//
// 		this->locationSubscriber 	= nh.subscribe<std_msgs::String>("room_key", 1, &KeyManager::locationCallback, this);
// 		this->requesterSubscriber	= nh.subscribe<std_msgs::String>("requester",1, &KeyManager::requesterCallback, this);
 		cout << "PARSING COMPLETED" << endl;
 		this->printLocations();

	}


	geometry_msgs::PoseStamped* getLocation(string s){

		map<string,geometry_msgs::PoseStamped>::iterator it;

		it=this->locations.find(s);
		if(it==this->locations.end()){cout << "LOCATION NOT FOUND" << endl; return NULL;}
		else{return &(it->second);}
	}


	void printLocations(){

		map<string,geometry_msgs::PoseStamped>::iterator iter;
		  for( iter = this->locations.begin(); iter != this->locations.end(); iter++ ) {
		    cout << (string)iter->first << ":" << endl;
		    cout << iter->second<< endl;
		  }
	}

};



//int main(int argc, char ** argv){
//
//	//Initialize ROS
//	ros::init(argc, argv, "AngenLocationManager", ros::init_options::AnonymousName);
//	ros::NodeHandle nh;
//
//	KeyManager man("angen_topologica.txt", nh);
////	man.printLocations();
//
//	ros::Rate loop_rate(1);
//
//	while (nh.ok()){
//
//
//		ros::spinOnce ();
//		loop_rate.sleep ();
//	}
//
//	return 0;
//}
