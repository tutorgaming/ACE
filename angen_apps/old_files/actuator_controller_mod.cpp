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
#include "ros/param.h"
#include <map>
#include <utility>


//SPECIFY THE STACK PATH HERE
std::string stack_path = std::string("/home/crichton/ros_workspace/angen_cognitive_environment");

std::string actuator_status_door = std::string("ace_actuator_status/door/");
std::string actuator_status_light = std::string("ace_actuator_status/light/");
std::string actuator_status_window = std::string("ace_actuator_status/window/");

using namespace std;

#define DOOR 1
#define LIGHT 2
#define WINDOW 3

#define ON 4
#define OFF 5
#define OPEN 6
#define CLOSE 7

#define ENTRANCE 8
#define WORKROOM 9
#define KITCHEN 10
#define BEDROOM 11
#define BATHROOM 12
#define CLOSET 13
#define LIVINGROOM 14
#define BALCONY 15

#define ROOM_1 16
#define ROOM_2 17
#define ROOM_3 18
#define ROOM_4 19
#define ROOM_5 20
#define ROOM_6 21
#define ROOM_7 22

#define WINDOW_LENGTH_WORKROOM 1.0
#define WINDOW_LENGTH_KITCHEN 2
#define WINDOW_LENGTH_BEDROOM 1.2
#define WINDOW_LENGTH_LIVNGROOM 2.2

#define DOOR_LENGTH_CLOSET 0.6
#define DOOR_LENGTH_OTHERS 1

class actuator_controller
 {
   private:
    std::set<std::string> _modelsList;
        
   public:
    void light_on(std::string , std:: string);
    void light_off(std::string );
    void door_open(std::string , float );
    void door_close(std::string , float ); 
    void window_open(std::string , int );  
    void window_close(std::string , int );
    void clear_effort(std::string , int );
    void clear_effort1(std::string );
 };
  
void actuator_controller::light_on(std::string xml_filename, std::string model_name1)
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
	
	if(spawnModelClient.call(spawnModel))
	 {
	   std::cout << "Switched ON the light" << std::endl;
	   actuator_controller::_modelsList.insert(spawnModel.request.model_name);
	 }
	else
	{
	 std::cout << "Problem with switching the light ON" << std::endl;
	}
     }
     
void actuator_controller::light_off(std::string model_name1)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/delete_model");
       ros::ServiceClient deleteModelClient = nh.serviceClient<gazebo::DeleteModel>("gazebo/delete_model");
       gazebo::DeleteModel deleteModel;
       deleteModel.request.model_name = model_name1;
       
       if(deleteModelClient.call(deleteModel))
        {
         std::cout << "Switched OFF the light"<< model_name1 << std::endl;
        }
       else
        {
         std::cout << "Problem with switching the light OFF" << model_name1 << std::endl;
        }
     }

void actuator_controller::door_open(std::string model_name1, float dur)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/apply_joint_effort");
       ros::ServiceClient dooropenClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
       gazebo::ApplyJointEffort dooropen;
       dooropen.request.joint_name = model_name1;
       dooropen.request.effort = 1;
       dooropen.request.duration = ros::Duration(2,0);
       dooropen.request.start_time = ros::Time(0,10000);
       dooropenClient.call(dooropen);
       //if((model_name1.compare("link_joint_c"))) 
       ros::Duration(dur).sleep();
       //else {ros::Duration(dur2).sleep(); ROS_INFO("DEBUG");}
       dooropen.request.effort = -1;
       dooropen.request.duration = ros::Duration(2,0);
       dooropen.request.start_time = ros::Time(0,10000);
       if(dooropenClient.call(dooropen))
        {
         std::cout << "Door is open "<< model_name1 << std::endl;
        }
       else
        {
         std::cout << "Problem with door opening" << model_name1 << std::endl;
        }
      }


void actuator_controller::door_close(std::string model_name1, float dur)
     {
       ros::NodeHandle nh("");
       ros::service::waitForService("gazebo/apply_joint_effort");
       ros::ServiceClient doorcloseClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
       gazebo::ApplyJointEffort doorclose;
       doorclose.request.joint_name = model_name1;
       doorclose.request.effort = -1;
       doorclose.request.duration = ros::Duration(1000000000,0);
       doorclose.request.start_time = ros::Time(0,10000000000);
       //doorcloseClient.call(doorclose);
       //if((model_name1.compare("link_joint_c"))) 
       //ros::Duration(dur).sleep();
       //else {ros::Duration(dur2).sleep(); ROS_INFO("DEBUG");}
       //doorclose.request.effort = 1;
       //doorclose.request.duration = ros::Duration(0.05,0);
       //doorclose.request.start_time = ros::Time(0,10000);
       //doorcloseClient.call(doorclose);
       //ros::Duration(dur).sleep();
       //doorclose.request.effort = -1;
       //doorclose.request.duration = ros::Duration(2,0);
       //doorclose.request.start_time = ros::Time(0,10000);
       if(doorcloseClient.call(doorclose))
        {
         std::cout<< "Door is closed "<< model_name1 << std::endl;
        }
       else
        {
         std::cout << "Problem with door closing" << model_name1 << std::endl;
        }
      }
      
void actuator_controller::window_open(std::string model_name1, int a)
     {
       //std::cout<<a<<endl;
       //std::cout<<model_name1;        
       std::string temp_name;
       //int e = n;
       for(int n=1; n<=a; n++)
       {
        temp_name = model_name1 + std::string(1, 48 + n);
        //std::cout<<temp_name;   
        ros::NodeHandle nh("");
        ros::service::waitForService("gazebo/apply_joint_effort");       
        ros::ServiceClient windowopenClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");      
        gazebo::ApplyJointEffort windowopen;          
        windowopen.request.joint_name = temp_name;      
        windowopen.request.effort = 0.6;
        windowopen.request.duration = ros::Duration(1000000000,0);
        windowopen.request.start_time = ros::Time(0,10000000000);
        if(windowopenClient.call(windowopen))
        {
         std::cout << "Window pane "<<n<<" is open"<< std::endl;
        }
        else
        {
         std::cout << "Problem with opening window pane "<<n<< std::endl;
        }
       }   
      }
      
void actuator_controller::window_close(std::string model_name1, int a)
     {
        std::string temp_name;
        //n=n+1;
        for(int n=1; n<=a; n++)
        {
         temp_name = model_name1 + std::string(1, 48 + n);
         //std::cout<<temp_name;   
         ros::NodeHandle nh("");
         ros::service::waitForService("gazebo/apply_joint_effort");
         ros::ServiceClient windowcloseClient = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
         gazebo::ApplyJointEffort windowclose;     
         windowclose.request.joint_name = temp_name;
         windowclose.request.effort = -1;
         windowclose.request.duration = ros::Duration(1000000000,0);
         windowclose.request.start_time = ros::Time(0,10000000000);  
         if(windowcloseClient.call(windowclose)&&n!=0)
         {
          std::cout << "Window pane "<<n<<" is closed"<< std::endl;
         }
         else
         {
          std::cout << "Problem with closing window pane "<<n<< std::endl;
         }
        }
      }

void actuator_controller::clear_effort(std::string model_name1, int a)
{  
       for(int n=1; n<=a; n++)
       {
        //ROS_INFO("CALLED");
        std::string temp_name;
        temp_name = model_name1 + std::string(1, 48 + n);
        //std::cout<<temp_name;
        ros::NodeHandle nh("");
        ros::service::waitForService("gazebo/clear_joint_forces");
        ros::ServiceClient clearforcesClient = nh.serviceClient<gazebo_msgs::JointRequest>("gazebo/clear_joint_forces");
        gazebo_msgs::JointRequest clearforces;
        clearforces.request.joint_name = temp_name;
        clearforcesClient.call(clearforces);
       }
}        

void actuator_controller::clear_effort1(std::string model_name1)
{  
       
        //ROS_INFO("CALLED");
        std::string temp_name;
        temp_name = model_name1;
        //std::cout<<temp_name;
        ros::NodeHandle nh("");
        ros::service::waitForService("gazebo/clear_joint_forces");
        ros::ServiceClient clearforcesClient = nh.serviceClient<gazebo_msgs::JointRequest>("gazebo/clear_joint_forces");
        gazebo_msgs::JointRequest clearforces;
        clearforces.request.joint_name = temp_name;
        clearforcesClient.call(clearforces);
      
}        
	
int main(int argc, char **argv)
 {
   ros::init(argc, argv, "actuator_controller"); 
   
   actuator_controller ac;
   
   ros::NodeHandle ph;
   
   float dur1 = ((5*DOOR_LENGTH_OTHERS)-0.3);
   float dur2 = ((5*DOOR_LENGTH_CLOSET)-0.3);

   int nowp1 = (WINDOW_LENGTH_WORKROOM/2)*10;
   int nowp2 = (WINDOW_LENGTH_KITCHEN/2)*10;
   int nowp3 = (WINDOW_LENGTH_BEDROOM/2)*10;
   int nowp4 = (WINDOW_LENGTH_LIVNGROOM/2)*10;
   
   std::string file, light_name, object, actd, actl, actw, door_name, act_comp, window_name, room_name=argv[3], status=argv[2], actuator1=argv[1];
   int f = 0; float dura = 0;
   
   map<string, int> actuator;
   
   actuator["door"] = 1;
   actuator["light"] = 2;
   actuator["window"] = 3;
   actuator["on"] = 4;
   actuator["off"] = 5;
   actuator["open"] = 6;
   actuator["close"] = 7;
   actuator["entrance"] = 8;
   actuator["workroom"] = 9;
   actuator["kitchen"] = 10;
   actuator["bedroom"] = 11;
   actuator["bathroom"] = 12;
   actuator["closet"] = 13;
   actuator["livingroom"] = 14;
   actuator["balcony"] = 15;
   actuator["room1"] = 16;
   actuator["room2"] = 17;
   actuator["room3"] = 18;
   actuator["room4"] = 19;
   actuator["room5"] = 20;
   actuator["room6"] = 21;
   actuator["room7"] = 22;
      
   switch(actuator[room_name])
    {
      case LIVINGROOM:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_livingroom.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       actw = std::string(actuator_status_window) + std::string(argv[3]);
       light_name = std::string("bulb_lr");
       object = std::string("light_lr");
       door_name = std::string("link_joint_lr");
       window_name = std::string("wlink_joint_lr");
       f = nowp4;
       dura = dur1;
       break;
      case WORKROOM:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_workroom.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       actw = std::string(actuator_status_window) + std::string(argv[3]);
       light_name = std::string("bulb_wr");
       object = std::string("light_wr");
       door_name = std::string("link_joint_wr");
       window_name = std::string("wlink_joint_wr");
       f = nowp1;
       dura = dur1;
       break;
      case KITCHEN:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_kitchen.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       actw = std::string(actuator_status_window) + std::string(argv[3]);
       light_name = std::string("bulb_k");
       object = std::string("light_k");
       door_name = std::string("link_joint_k");
       window_name = std::string("wlink_joint_k");
       f = nowp2;
       dura = dur1;
       break;
      case BEDROOM:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_bedroom.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       actw = std::string(actuator_status_window) + std::string(argv[3]);
       light_name = std::string("bulb_ber");
       object = std::string("light_ber");
       door_name = std::string("link_joint_ber");
       window_name = std::string("wlink_joint_ber");
       f = nowp3;
       dura = dur1;
       break;
      case BATHROOM:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_bathroom.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       light_name = std::string("bulb_bar");
       object = std::string("light_bar");
       door_name = std::string("link_joint_bar");
       dura = dur1;
       break;
      case CLOSET:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_closet.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       light_name = std::string("bulb_c");
       object = std::string("light_c");
       door_name = std::string("link_joint_c");
       dura = dur2;
       break;
      case BALCONY:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_balcony.urdf");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       actl = std::string(actuator_status_light) + std::string(argv[3]);
       light_name = std::string("bulb_bac");
       object = std::string("light_bac");
       door_name = std::string("link_joint_bac");
       window_name = std::string("wlink_joint_bac");
       dura = dur1;
       break;
      case ENTRANCE:
       door_name = std::string("link_joint_e");
       actd = std::string(actuator_status_door) + std::string(argv[3]);
       dura = dur1;
       break;
      case ROOM_1:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room1.urdf");
       light_name = std::string("bulb_r1");
       object = std::string("light_r1");
       door_name = std::string("link_joint_r1");
       dura = dur1;
       break;
      case ROOM_2:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room2.urdf");
       light_name = std::string("bulb_r2");
       object = std::string("light_r2");
       door_name = std::string("link_joint_r2");
       dura = dur1;
       break;
      case ROOM_3:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room3.urdf");
       light_name = std::string("bulb_r3");
       object = std::string("light_r3");
       door_name = std::string("link_joint_r3");
       dura = dur1;
       break;
      case ROOM_4:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room4.urdf");
       light_name = std::string("bulb_r4");
       object = std::string("light_r4");
       door_name = std::string("link_joint_r4");
       dura = dur1;
       break;
      case ROOM_5:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room5.urdf");
       light_name = std::string("bulb_r5");
       object = std::string("light_r5");
       door_name = std::string("link_joint_r5");
       dura = dur1;
       break;
      case ROOM_6:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room6.urdf");
       light_name = std::string("bulb_r6");
       object = std::string("light_r6");
       door_name = std::string("link_joint_r6");
       dura = dur1;
       break;
      case ROOM_7:
       file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_room7.urdf");
       light_name = std::string("bulb_r7");
       object = std::string("light_r7");
       door_name = std::string("link_joint_r7");
       dura = dur1;
       break;      
      default:
       break;
   }
   
   switch(actuator[status])
   {
    case ON:
        ros::param::get(std::string(actl), act_comp);
        if(act_comp.compare("offf") == 0)
         {
           ac.light_on(file, light_name);
           ros::param::set(std::string(actl), "onn");
         }
        else
         ROS_ERROR("LOL :-D, Someone is trying to switch ON a light that is already ON"); 
     break;
    case OFF:
     ros::param::get(std::string(actl), act_comp);
     if(act_comp.compare("onn") == 0)
      {
       ac.light_off(light_name);
       ac.light_off(object);
       ros::param::set(std::string(actl), "offf");
      }
     else
      ROS_ERROR("LOL :-D, Someone is trying to switch OFF a light that is already OFF");  
     break;
    case OPEN:
       if (actuator[actuator1] == 1)
           {
            ros::param::get(std::string(actd), act_comp);
            if(act_comp.compare("close") == 0)
             {
              ac.clear_effort1(door_name);
              ac.door_open(door_name,dura);
              ros::param::set(std::string(actd), "open");
             }
            else
             ROS_ERROR("LOL :-D, Someone is trying to open a door that is already opened");   
           }
       else
           {
            ros::param::get(std::string(actw), act_comp);
            if(act_comp.compare("close") == 0)
             {
              ac.clear_effort(window_name,f);
              ac.window_open(window_name, f);
              ros::param::set(std::string(actw), "open");
             }
            else
             ROS_ERROR("LOL :-D, Someone is trying to open a window that is already opened");
           }
     break; 
    case CLOSE:
      if (actuator[actuator1] == 1)
        {   
           ros::param::get(std::string(actd), act_comp);
           if(act_comp.compare("open") == 0)
            {
             ac.clear_effort1(door_name);
             ac.door_close(door_name,dura);
             ros::param::set(std::string(actd), "close");
            }
           else
             ROS_ERROR("LOL :-D, Someone is trying to close a door that is already closed"); 
        }      
       else
           {
            ros::param::get(std::string(actw), act_comp);
            if(act_comp.compare("open") == 0)
            {
             ac.clear_effort(window_name,f);
             ac.window_close(window_name,f);
             ros::param::set(std::string(actw), "close");
            }
            else
             ROS_ERROR("LOL :-D, Someone is trying to close a window that is already closed");
     break;
    default:
       break;
   } 
   
   usleep(1000000);
   return 0;
 }
} 

