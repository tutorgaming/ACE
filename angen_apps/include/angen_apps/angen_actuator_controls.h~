#include "ros/ros.h"
#include "std_msgs/String.h"
#include "gazebo/SpawnModel.h"
#include "gazebo/DeleteModel.h"
#include "gazebo/ApplyJointEffort.h"
#include "gazebo_msgs/JointRequest.h"
#include <iostream>
#include <tinyxml.h>
#include <cstdlib>
#include <set>
#include <string>
#include "ros/duration.h"

using namespace std;
namespace actuator_controls{

class AngenActuatorControls
 {
   private:
    std::set<std::string> _modelsList;
        
   public:
    void light_on(std::string , std:: string);
    void light_off(std::string );
    void door_control(std::string , int );
    //void door_close(std::string , float ); 
    //void window_open(std::string );  
    //void window_close(std::string );
    void clear_effort(std::string);
    void elevator_control(float );
 };
  
void AngenActuatorControls::light_on(std::string xml_filename, std::string model_name1)
     {
        ros::NodeHandle nh("");
	ros::service::waitForService("gazebo/spawn_urdf_model");
	ros::ServiceClient spawnModelClient = nh.serviceClient<gazebo::SpawnModel>("gazebo/spawn_urdf_model");
	gazebo::SpawnModel spawnModel;
	spawnModel.request.model_name = model_name1;
	TiXmlDocument xml_in(xml_filename);
	xml_in.LoadFile();
	std::ostringstream stream;
	stream << xml_in;
	spawnModel.request.model_xml = stream.str();	
	spawnModelClient.call(spawnModel);
	std::cout<<"The light is ON"<<endl;
     }
     
void AngenActuatorControls::light_off(std::string model_name1)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/delete_model");
       ros::ServiceClient deleteModelClient = nh.serviceClient<gazebo::DeleteModel>("gazebo/delete_model");
       gazebo::DeleteModel deleteModel;
       deleteModel.request.model_name = model_name1;       
       deleteModelClient.call(deleteModel);
       std::cout<<"The light is OFF"<<endl;

     }

void AngenActuatorControls::door_control(std::string model_name1, int command)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/apply_joint_effort");
       ros::ServiceClient doorcontrolClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
       gazebo::ApplyJointEffort doorcontrol;
       doorcontrol.request.joint_name = model_name1;
       doorcontrol.request.effort =  command * -100;
       //cout<<doorcontrol.request.effort<<endl;
       doorcontrol.request.duration = ros::Duration(1000000000);
       doorcontrol.request.start_time = ros::Time(0,10000000000);
       doorcontrolClient.call(doorcontrol);
       //ros::Duration(2).sleep();
       //std::cout<<"The door is open"<<endl;
       //clear_effort(model_name1);       
      }


/*void AngenActuatorControls::door_close(std::string model_name1, float dur)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/apply_joint_effort");
       ros::ServiceClient doorcloseClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
       gazebo::ApplyJointEffort doorclose;
       doorclose.request.joint_name = model_name1;
       doorclose.request.effort = 30;
       doorclose.request.duration = ros::Duration(0.1);
       doorclose.request.start_time = ros::Time(0,1000);
       doorcloseClient.call(doorclose);
       //std::cout<<"The door is closed"<<endl;
       //clear_effort(model_name1);
      }*/
      
/*void AngenActuatorControls::window_open(std::string model_name1)
     {      
       std::string temp_name;
       for(int n=1; n<=11; n++)
       {
        temp_name = model_name1 + std::string(1, 48 + n);  
        ros::NodeHandle nh("");
        ros::service::waitForService("gazebo/apply_joint_effort");       
        ros::ServiceClient windowopenClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");      
        gazebo::ApplyJointEffort windowopen;          
        windowopen.request.joint_name = temp_name;      
        windowopen.request.effort = 0.6;
        windowopen.request.duration = ros::Duration(1000000000,0);
        windowopen.request.start_time = ros::Time(0,10000000000);
        windowopenClient.call(windowopen);
       }
       std::cout<<"The Window is open"<<endl;          
      }
      
void AngenActuatorControls::window_close(std::string model_name1 )
     {
        std::string temp_name;
        for(int n=1; n<=11; n++)
        {
         temp_name = model_name1 + std::string(1, 48 + n);  
         ros::NodeHandle nh("");
         ros::service::waitForService("gazebo/apply_joint_effort");
         ros::ServiceClient windowcloseClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
         gazebo::ApplyJointEffort windowclose;     
         windowclose.request.joint_name = temp_name;
         windowclose.request.effort = -1;
         windowclose.request.duration = ros::Duration(1000000000,0);
         windowclose.request.start_time = ros::Time(0,10000000000);  
         windowcloseClient.call(windowclose);
        }
        std::cout<<"The Window is closed"<<endl;
      }*/

void AngenActuatorControls::elevator_control(float level)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/apply_joint_effort");
       ros::ServiceClient elevatorcontrolClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
       gazebo::ApplyJointEffort elevatorcontrol;
       elevatorcontrol.request.joint_name = std::string("elevator_joint");
       elevatorcontrol.request.effort = level*0.5;
       elevatorcontrol.request.duration = ros::Duration(1000000000);
       elevatorcontrol.request.start_time = ros::Time(0,10000000000);
       //int y=4;
       //while(y--)
           elevatorcontrolClient.call(elevatorcontrol);
           //ros::Duration(.5).sleep();
       //std::cout<<"The door is open"<<endl;
       //clear_effort(std::string("elevator_joint"));       
      }
void AngenActuatorControls::clear_effort(std::string model_name1)
{  
       for(int n=1; n<=11; n++)
       {
        std::string temp_name;
        temp_name = model_name1 + std::string(1, 48 + n);
        ros::NodeHandle nh("");
        ros::service::waitForService("gazebo/clear_joint_forces");
        ros::ServiceClient clearforcesClient = nh.serviceClient<gazebo_msgs::JointRequest>("gazebo/clear_joint_forces");
        gazebo_msgs::JointRequest clearforces;
        clearforces.request.joint_name = temp_name;
        clearforcesClient.call(clearforces);
       }
} 
}
