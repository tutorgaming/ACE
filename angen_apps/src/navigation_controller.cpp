#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include "std_msgs/UInt8.h"
#include "angen_turtlebot/navigaton_status.h"
//#include "angen_turtlebot/navigation_status.h"
#include "angen_turtlebot/navigation_command.h"


#include <map>
#include <utility>

using namespace std;

#define WORKROOM 6
#define KITCHEN 7
#define BEDROOM 8
#define BATHROOM 9
#define CLOSET 10
#define LIVINGROOM 11
#define BALCONY 12
	
int main(int argc, char **argv)
 {
   ros::init(argc, argv, "actuator_controller");
   ros::NodeHandle nodeh; 
   ros::Publisher roomkey;
   roomkey = nodeh.advertise<angen_turtlebot::navigation_command>("room_key", 2);
   angen_turtlebot::navigation_command key;
   std::string room_name = argv[2];
   int i=0;
   key.caller="";
   
   map<string, int> actuator;
   actuator["workroom"] = 6;
   actuator["kitchen"] = 7;
   actuator["bedroom"] = 8;
   actuator["bathroom"] = 9;
   actuator["closet"] = 10;
   actuator["livingroom"] = 11;
   actuator["balcony"] = 12;
   
   switch(actuator[argv[2]])
    {
      case LIVINGROOM:
       key.location = 'a';
       break;
      case WORKROOM:
       key.location= 'b';
       break;
      case KITCHEN:
       key.location= 'c';
       break;
      case BEDROOM:
       key.location= 'd';
       break;
      case BATHROOM:
       key.location= 'e';
       break;
      case CLOSET:
       key.location= 'f';
       break;
      case BALCONY:
       key.location= 'g';
       break;
      default:
       key.location= 'h';
       break;
     }
    while(ros::ok())
     {
      roomkey.publish(key);
      ros::spinOnce();
      sleep(1);
      if(i==4)
       exit(0);
      i++; 
     } 
    return 0;
 }  
