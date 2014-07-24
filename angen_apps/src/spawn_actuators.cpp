#include "ros/ros.h"
#include "ros/param.h"
#include <XmlRpcValue.h>
#include <tinyxml.h>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "gazebo/SpawnModel.h"
#include "ros/param.h"
#include "angen_apps/angen_actuator_controls.h"

using namespace std;
using namespace actuator_controls;

int main(int argc, char **argv)
{
  
        ros::init(argc, argv, "spawn_actuators");
        string afp; 
        double xwo, ywo;
        ros::param::get("actuator_files_path", afp);
        ros::NodeHandle nh;
                 
         // SET ACTUATOR PROPERTIES
        string actuator_file = afp + string("/") + string(argv[1]) + string("/")  + string(argv[1]) + string(".urdf.xacro");        
        TiXmlDocument xml_in(actuator_file);
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
	nh.param("/x_world_offset", xwo, 0.1);
	TiXmlElement* x_world_offset = docHandle.FirstChild( "robot" ).Child("property", 4).ToElement();	
	x_world_offset->SetAttribute("value", xwo);
	nh.param("/y_world_offset", ywo, 0.1);
	TiXmlElement* y_world_offset = docHandle.FirstChild( "robot" ).Child("property", 5).ToElement();	
	y_world_offset->SetAttribute("value", ywo);
	TiXmlElement* Lower_limit = docHandle.FirstChild( "robot" ).Child("property", 6).ToElement();
	Lower_limit->SetAttribute("value", argv[6]);
	TiXmlElement* Orientation = docHandle.FirstChild( "robot" ).Child("property", 7).ToElement();
	Orientation->SetAttribute("value", argv[7]);
	xml_in.SaveFile();	
	
	// SET TRANSMISSION CONTROLLER PROPERTIES
	string controller_file = afp + string("/") + string(argv[1]) +string("/")  + string(argv[1]) + string(".transmission.xacro");
        TiXmlDocument xml_in1(controller_file);
	xml_in1.LoadFile();
	TiXmlHandle docHandle1(&xml_in1);
	TiXmlElement* robot_name1 = docHandle1.FirstChild( "robot" ).Child("property", 0).ToElement();
	robot_name1->SetAttribute("value", string(argv[2]));
	xml_in1.SaveFile();	
	
	//SET JOINT PID CONTROLLER PROPERTIES
	string actuator_name = string(argv[2]) + string ("_") + string(argv[1]);
	string actuator_joint = string(argv[2]) + string ("_") + string(argv[1]) + string ("_joint");	
	ros::param::set(string(actuator_name + string("/type")), "robot_mechanism_controllers/JointPositionController");
	ros::param::set(string(actuator_name + string("/joint")), actuator_joint);
	ros::param::set(string(actuator_name + string("/pid/p")), 20);
	ros::param::set(string(actuator_name + string("/pid/i")), 0.1);
	ros::param::set(string(actuator_name + string("/pid/d")), 1);
	ros::param::set(string(actuator_name + string("/pid/i_clamp")), 1);
        
        // MAKE XACRO          
        string launch_command = string("roslaunch angen_gazebo ") + string(argv[1]) + string("_temp.launch");     
	system(launch_command.c_str());
	
	//SPAWN THE ACTUATOR
	string actuator_description = string("/") + string(argv[1]) + string("_description");
	string act_name = string(argv[2]) + string("_") + string(argv[1]) ;
	ros::service::waitForService("gazebo/spawn_urdf_model");
        gazebo::SpawnModel spawnModel;
        ros::ServiceClient spawnModelClient = nh.serviceClient<gazebo::SpawnModel>("gazebo/spawn_urdf_model");
	ros::param::get( actuator_description, spawnModel.request.model_xml);		
	spawnModel.request.model_name = act_name;
	spawnModelClient.call(spawnModel);
	
	return 0;
}
     
              
        //set_xacro_properties(actuator_file, controller_file, argv[1], argv[2], argv[3], argv[4], argv[5],argv[6]);
     //actuator_type = argv[1]; room_name = argv[2]; x_position = atof(argv[3]); y_position = atof(argv[4]); lower_limit = atof(argv[5]); orientation = atof(argv[6]);
        //cout<<x_position<<endl;        
        
     /*string actuator_type, room_name; float x_position, y_position, lower_limit, orientation;

void set_xacro_properties (string act_file, string cont_file)
{
        // SET ACTUATOR PROPERTIES
        TiXmlDocument xml_in(act_file);
	xml_in.LoadFile();
	TiXmlHandle docHandle(&xml_in);	
	TiXmlElement* Room_name = docHandle.FirstChild( "robot" ).Child("property", 0).ToElement();
	Room_name->SetAttribute("value", room_name);
	TiXmlElement* X_position = docHandle.FirstChild( "robot" ).Child("property", 1).ToElement();
	X_position->SetAttribute("value", x_position);
	TiXmlElement* Y_position = docHandle.FirstChild( "robot" ).Child("property", 2).ToElement();
	Y_position->SetAttribute("value", y_position);
	TiXmlElement* x_world_offset = docHandle.FirstChild( "robot" ).Child("property", 3).ToElement();	
	x_world_offset->SetAttribute("value", -5);
	TiXmlElement* y_world_offset = docHandle.FirstChild( "robot" ).Child("property", 4).ToElement();	
	y_world_offset->SetAttribute("value", -5);
	TiXmlElement* Lower_limit = docHandle.FirstChild( "robot" ).Child("property", 5).ToElement();
	cout<<lower_limit<<endl;
	Lower_limit->SetAttribute("value", lower_limit);
	TiXmlElement* Orientation = docHandle.FirstChild( "robot" ).Child("property", 6).ToElement();
	cout<<orientation<<endl;
	Orientation->SetAttribute("value", orientation);
	xml_in.SaveFile();
	
	// SET TRANSMISSION CONTROLLER PROPERTIES
        TiXmlDocument xml_in1(cont_file);
	xml_in1.LoadFile();
	TiXmlHandle docHandle1(&xml_in1);
	TiXmlElement* robot_name1 = docHandle.FirstChild( "robot" ).Child("property", 0).ToElement();
	robot_name1->SetAttribute("value", room_name);
	xml_in1.SaveFile();
	
	//SET JOINT PID CONTROLLER PROPERTIES
	string actuator_name = room_name + string ("_") + actuator_type;
	string actuator_joint = room_name + string ("_") + actuator_type + string ("_joint");	
	ros::param::set(string(actuator_name + string("/type")), "robot_mechanism_controllers/JointPositionController");
	ros::param::set(string(actuator_name + string("/joint")), actuator_joint);
	ros::param::set(string(actuator_name + string("/pid/p")), 20);
	ros::param::set(string(actuator_name + string("/pid/i")), 0.1);
	ros::param::set(string(actuator_name + string("/pid/d")), 1);
	ros::param::set(string(actuator_name + string("/pid/i_clamp")), 1);
	
}*/
       
        //if( !(actuator_type.compare("door"))) 
                //cout<<"actuator_type not supported. Use door/window";          
        //else 
        //ros::param::get("x_world_offset", xwo);
	//xwo = system("rosparam get /x_world_offset");
	//cout<<xwo<<endl;
	//cout<<atoi(xwo.c_str())<<endl;
	//int s = atoi(xwo.c_str());
	
	//ros::param::get("y_world_offset", ywo);
	//ywo = system("rosparam get /y_world_offset");
        /*if (argv[1].compare("door")               
        {
                actuator_file = afp + "/door/door.urdf.xacro";
                actuator_controller = afp + "/door/door.transmission.xacro";
                launch_command = string("roslaunch angen_gazebo
        }
        else if (argv[2].compare("window")
        {
                actuator_file = afp + "/window/window.urdf.xacro";
                actuator_controller = afp + "/window/window.transmission.xacro";
         }*/
	/*string model_xml;
	system("roslaunch angen_gazebo door_temp.launch");
	nh.getParam("/door_description", model_xml);	
	string door_name = string(argv[1]) + string("_door");
	
	ros::service::waitForService("gazebo/spawn_urdf_model");
	ros::ServiceClient spawnModelClient = nh.serviceClient<gazebo::SpawnModel>("gazebo/spawn_urdf_model");
	gazebo::SpawnModel spawnModel;
	spawnModel.request.model_name = std::string(argv[1]) + std::string("_door");
	nh.getParam("/door_description", spawnModel.request.model_xml);	
	cout<<spawnModel.request.model_xml;
	spawnModelClient.call(spawnModel);
	//if(spawnModelClient.call(spawnModel))
	 //cout<<"success";
	//else
	  //{cout<<"no success"; goto a;}
	
	//AngenActuatorControls ac;
	//ac.light_on(model_xml, door_name);
	ros::spin();*/  	
	
