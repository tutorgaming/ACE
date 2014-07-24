#include <cstdio>
#include "ros/ros.h"
#include <stdlib.h>
#include <sstream>

using namespace std;

int main(int argc, char ** argv)
{
        ros::init(argc, argv, "launch_actuators");
	ros::NodeHandle nh;
	
	
	cout<<"SPAWNING ACTUATORS!!"<<endl;
	cout<<"         SPAWNING DOORS!"<<endl;
	string launch_doors = string("xterm -e \"sh `rospack find angen_gazebo`/sh/launch_doors_\"") + string(argv[1])  + string("\".sh\"");
	system(launch_doors.c_str());		
	cout<<"         SPAWNING WINDOWS!"<<endl;
	string launch_windows = string("xterm -e \"sh `rospack find angen_gazebo`/sh/launch_windows_\"") + string(argv[1])  + string("\".sh\"");
	system(launch_windows.c_str());
		
	cout<<"SPAWNING SENSORS!!"<<endl;
	cout<<"         SPAWNING OPTICAL SENSORS FOR DOORS!"<<endl;
	string launch_opticalsensors = string("xterm -e \"sh `rospack find angen_gazebo`/sh/launch_opticalsensors_\"") + string(argv[1])  + string("\".sh\"");
	system(launch_opticalsensors.c_str());
	cout<<"         SPAWNING CAMERAS!"<<endl;
	string launch_cameras = string("xterm -e \"sh `rospack find angen_gazebo`/sh/launch_cameras_\"") + string(argv[1])  + string("\".sh\"");
	system(launch_cameras.c_str());
	//cout<<"         LAUNCHING CAMERA STATION!"<<endl;
	//string launch_camerastation = "xterm -e \"sh `rospack find angen_gazebo`/sh/launch_camerastation.sh\"";
	//system(launch_camerastation.c_str());
	return 0;
}	
	
