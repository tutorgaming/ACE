#include "ros/ros.h"
#include "ros/param.h"
#include "gazebo/SpawnModel.h"
#include <XmlRpcValue.h>
#include <tinyxml.h>

using namespace std;

int main(int argc, char** argv)
{
        ros::init(argc, argv, "spawn_sensors");
        string sfp;
        ros::param::get("sensor_files_path", sfp);   
        ros::NodeHandle nh;   
        
        //SET XACRO PROPERTIES
        string sensor_file = sfp + string("/") + string(argv[1]) + string("/")  + string(argv[1]) + string(".urdf.xacro");        
        TiXmlDocument xml_in(sensor_file);
	xml_in.LoadFile();
	TiXmlHandle docHandle(&xml_in);	
	TiXmlElement* Room_name = docHandle.FirstChild( "robot" ).Child("property", 0).ToElement();
	Room_name->SetAttribute("value", string(argv[2]));
	TiXmlElement* X_position = docHandle.FirstChild( "robot" ).Child("property", 1).ToElement();
	X_position->SetAttribute("value", string(argv[3]));
	TiXmlElement* Y_position = docHandle.FirstChild( "robot" ).Child("property", 2).ToElement();
	Y_position->SetAttribute("value", argv[4]);
	TiXmlElement* Z_position = docHandle.FirstChild( "robot" ).Child("property", 3).ToElement();
	Z_position->SetAttribute("value", argv[5]);
	TiXmlElement* x_world_offset = docHandle.FirstChild( "robot" ).Child("property", 4).ToElement();	
	x_world_offset->SetAttribute("value", -5);
	TiXmlElement* y_world_offset = docHandle.FirstChild( "robot" ).Child("property", 5).ToElement();	
	y_world_offset->SetAttribute("value", -5);
	TiXmlElement* Yaw = docHandle.FirstChild( "robot" ).Child("property", 6).ToElement();
	Yaw->SetAttribute("value", argv[6]);	
	float roll, pitch; if(argc!=8) { roll = 0; pitch = 0;} else { roll = atof(argv[7]); pitch = atof(argv[8]);}
	TiXmlElement* Roll = docHandle.FirstChild( "robot" ).Child("property", 7).ToElement();
	Roll->SetAttribute("value", roll);
	TiXmlElement* Pitch = docHandle.FirstChild( "robot" ).Child("property", 8).ToElement();
	Pitch->SetAttribute("value", pitch);
	xml_in.SaveFile();	
	
	//MAKE XACRO
	string launch_command = string("roslaunch angen_gazebo ") + string(argv[1]) + string("_temp.launch");     
	system(launch_command.c_str());
	
	//SPAWN THE SENSOR
        string sensor_description = string("/") + string(argv[1]) + string("_description");
	string sen_name = string(argv[2]) + string("_") + string(argv[1]) ;
	gazebo::SpawnModel spawnModel;
	ros::param::get(sensor_description, spawnModel.request.model_xml);		
	spawnModel.request.model_name = sen_name;
	ros::service::waitForService("gazebo/spawn_urdf_model");        
        ros::ServiceClient spawnModelClient = nh.serviceClient<gazebo::SpawnModel>("gazebo/spawn_urdf_model");
	spawnModelClient.call(spawnModel);
	
	return 0;
}	
	
	
