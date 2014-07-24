#include "angen_apps/angen_actuator_controls.h"
#include "angen_apps/angen_status_space.h"
#include "angen_apps/AngenActuatorsStatus.h"
#include <map>
#include <utility>

//SPECIFY THE STACK PATH HERE
std::string stack_path = std::string("/home/haller/ros_workspace/angen_cognitive_environment");

using namespace std;
using namespace actuator_controls;

#define DOOR 1
#define LIGHT 2
#define WINDOW 3
#define ON 4
#define OFF 5
#define OPEN 6
#define CLOSE 7

AngenStatusSpace st;

bool status_manager(angen_apps::AngenActuatorsStatus::Request &req, angen_apps::AngenActuatorsStatus::Response &res)
{
   AngenActuatorControls ac;
     
   string RoomName = req.room_name;
   string ActuatorName = req.actuator_name;
   string Status = req.status;
   
   map<string, int> actuator;   
   actuator["door"] = 1;
   actuator["light"] = 2;
   actuator["window"] = 3;
   actuator["on"] = 4;
   actuator["off"] = 5;
   actuator["open"] = 6;
   actuator["close"] = 7;
   
 
   string bulb_name = std::string("bulb_")+std::string(RoomName);
   string light_name = std::string("light_")+std::string(RoomName);
   string file = std::string(stack_path) + std::string("/angen_gazebo/urdf/actuators/lights/light_") + std::string(RoomName) + std::string(".urdf");
   string door_name = std::string(RoomName) + string("_door_joint");  
   string window_name = std::string(RoomName) + std::string("_window_joint");
   float force_duration = 5;
   
   switch(actuator[Status])
   {
    case ON:
     if(!(st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("off"))) 
      {
       ac.light_on(file, bulb_name);
       st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
      } 
     else
      ROS_ERROR("Light is either ON already or some input error");
     break;
    case OFF:
     if(!(st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("on")))
     {
      ac.light_off(bulb_name);
      ac.light_off(light_name);
      st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
     }
     else
      ROS_ERROR("Light is either OFF already or some input error");
     break;
    case OPEN:
       if (actuator[ActuatorName] == 1)
           {
            if(!(st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("close")))
             {
              ac.door_open(door_name,force_duration);
              st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
             } 
            else
             ROS_ERROR("Door is either OPEN already or some input error"); 
           }
       else
           {
            if(!(st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("close")))
            {
             ac.clear_effort(window_name);
             ac.window_open(window_name);
             st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
            }
            else
             ROS_ERROR("Window is either OPEN already or some input error"); 
           }     
     break; 
    case CLOSE:
      if (actuator[ActuatorName] == 1)
         if((!st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("open")))
           {
            ac.door_close(door_name,force_duration);
            st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
           } 
         else
           ROS_ERROR("Door is either CLOSED already or some input error");   
       else
           {
            if(!(st.get_actuator_status(std::string(RoomName), std::string(ActuatorName)).compare("open")))
             { 
              ac.clear_effort(window_name);
              ac.window_close(window_name);
              st.set_actuator_status(std::string(RoomName), std::string(ActuatorName), std::string(Status));
             }
            else
              ROS_ERROR("Window is either CLOSED already or some input error");    
           } 
     break;
    default:
       break;
   } 
 usleep(1000000);
  return true;
}  
   	
int main(int argc, char **argv)
{
   ros::init(argc, argv, "actuator_controller_server");
   ros::NodeHandle n;
   ros::ServiceServer status_service = n.advertiseService("status_manager", status_manager);
   ros::spin();
   return 0;    
 }
