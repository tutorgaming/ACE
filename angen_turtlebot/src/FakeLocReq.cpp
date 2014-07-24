



#include <cstdio>
#include "tf/transform_listener.h"
#include "tf/transform_datatypes.h"
#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
//#include "KeyManager.cpp"
#include "NavigationManager.cpp"


using namespace std;

int main(int argc, char ** argv){

	//Initialize ROS
	ros::init(argc, argv, "GoalLauncher", ros::init_options::AnonymousName);
	ros::NodeHandle nh;

	cout << "NODE INIT" << endl;

	angen_turtlebot::navigaton_status	msg;
	geometry_msgs::PoseStamped			msg2;

	ros::Publisher	pub=
			nh.advertise<angen_turtlebot::navigaton_status>("/robot2/navigation_request",1);

	ros::Publisher	pub2=
			nh.advertise<move_base_msgs::MoveBaseActionGoal>("/robot2/move_base/goal", 1);

	//	KeyManager man("angen_topological.txt", nh);
	//	man.printLocations();

	if(argc<2){cout << "PLEASE PROVIDE LOCATION AS INPUT ARGUMENT" << endl; exit(0);}

	msg.status=argv[1];
	msg.caller="FAKE";
	ros::Rate loop_rate(1);

	msg2.header.stamp		= ros::Time::now();
	msg2.pose.position.x 	= 0;//pose[0];
	msg2.pose.position.y 	= 0;//pose[1];
	msg2.pose.position.z 	= 0;//pose[2];
	msg2.pose.orientation.x 	=0;// pose[3];
	msg2.pose.orientation.y 	= 0;//pose[4];
	msg2.pose.orientation.z 	= 0;//pose[5];
	msg2.pose.orientation.w 	= 0;//pose[6];

	msg2.header.seq 			= 1;
	msg2.header.frame_id		= "/map";
	msg2.header.frame_id 	= "";

	while (nh.ok()){


		pub.publish(msg);
		pub2.publish(msg2);
		getchar();
		ros::spinOnce ();
		loop_rate.sleep ();
	}

	return 0;
}
