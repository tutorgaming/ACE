#include<iostream>
#include"ros/ros.h"
#include"ros/param.h"
#include <cstdio>
#include <XmlRpcValue.h>
#include <tinyxml.h>
#include "gazebo/SpawnModel.h"

using namespace std;

int main(int argc, char **argv)
{
        ros::init(argc, argv, "spawn_actuators");
        string efp; 
        double xwo, ywo, gbf;
        ros::param::get("elevator_file_path", efp);
        ros::NodeHandle nh;
        
        nh.param("/x_world_offset", xwo, 0.1);
        nh.param("/y_world_offset", ywo, 0.1);
        nh.param("/gap_between_floors", gbf, 0.2);
        cout<<float(gbf)<<endl;
        
        // SET ELEVATOR PROPERTIES
        string elevator_file = efp + string("/elevator.urdf.xacro");        
        TiXmlDocument xml_in(elevator_file);
	xml_in.LoadFile();
	TiXmlHandle docHandle(&xml_in);	
	TiXmlElement* X_position = docHandle.FirstChild( "robot" ).Child("property", 0).ToElement();
	X_position->SetAttribute("value", argv[1]);
	TiXmlElement* Y_position = docHandle.FirstChild( "robot" ).Child("property", 1).ToElement();
	Y_position->SetAttribute("value", argv[2]);
	TiXmlElement* x_world_offset = docHandle.FirstChild( "robot" ).Child("property", 2).ToElement();	
	x_world_offset->SetAttribute("value", xwo);
	TiXmlElement* y_world_offset = docHandle.FirstChild( "robot" ).Child("property", 3).ToElement();	
	y_world_offset->SetAttribute("value", ywo);
	TiXmlElement* gap_between_floors = docHandle.FirstChild( "robot" ).Child("property", 4).ToElement();
	gap_between_floors->SetAttribute("value", float(gbf));
	xml_in.SaveFile();
	
	//SET ELEVATOR ENCLOSURE PROPERTIES
	string elevator_enclosure_file = efp + string("/elevator_enclosure.urdf.xacro");        
        TiXmlDocument xml_in1(elevator_enclosure_file);
	xml_in1.LoadFile();
	TiXmlHandle docHandle1(&xml_in1);	
	TiXmlElement* X_position1 = docHandle1.FirstChild( "robot" ).Child("property", 0).ToElement();
	X_position1->SetAttribute("value", argv[1]);
	TiXmlElement* Y_position1 = docHandle1.FirstChild( "robot" ).Child("property", 1).ToElement();
	Y_position1->SetAttribute("value", argv[2]);
	TiXmlElement* x_world_offset1 = docHandle1.FirstChild( "robot" ).Child("property", 2).ToElement();	
	x_world_offset1->SetAttribute("value", xwo);
	TiXmlElement* y_world_offset1 = docHandle1.FirstChild( "robot" ).Child("property", 3).ToElement();	
	y_world_offset1->SetAttribute("value", ywo);
	TiXmlElement* gap_between_floors1 = docHandle1.FirstChild( "robot" ).Child("property", 4).ToElement();
	gap_between_floors1->SetAttribute("value", gbf);
	xml_in1.SaveFile();
	
	//MAKE ELEVATOR XACRO
	system("roslaunch angen_gazebo elevator_temp.launch");
	
	//MAKE ELEVATR ENCLOSURE XACRO
	system("roslaunch angen_gazebo elevator_enclosure_temp.launch");
	
        return 0;
}
