#include "ros/ros.h"
#include <iostream>
#include <math.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include <ros/callback_queue.h>
#include "gazebo_plugins/gazebo_ros_bumper.h"
#include <string>
#include "gazebo_msgs/ContactState.h"
#include "gazebo_msgs/ContactsState.h"
#include "angen_turtlebot/navigaton_status.h"
#include "angen_turtlebot/navigation_command.h"

#define TRESHOLD_FORCE 900

using namespace std;
class room_identifier
{
        ros::Subscriber bedroom_contact_subscriber;
        ros::Subscriber kitchen_contact_subscriber;
        ros::Subscriber workroom_contact_subscriber;
        ros::Subscriber entranceway_contact_subscriber;
        ros::Subscriber livingroom_contact_subscriber;
        ros::Publisher roomkey_publisher;
        
        ros::NodeHandle angen_contact_handle;
   
        angen_turtlebot::navigation_command key;
   public:
        room_identifier() 
        { 
          bedroom_contact_subscriber = angen_contact_handle.subscribe("/angen_contact/FCS/bedroom/state", 1000, &room_identifier::bedroom_contact_callback, this);
          kitchen_contact_subscriber = angen_contact_handle.subscribe("/angen_contact/FCS/kitchen/state", 1000, &room_identifier::kitchen_contact_callback, this);
          workroom_contact_subscriber = angen_contact_handle.subscribe("/angen_contact/FCS/workroom/state", 1000, &room_identifier::workroom_contact_callback, this); 
          entranceway_contact_subscriber = angen_contact_handle.subscribe("/angen_contact/FCS/entranceway/state", 1000, &room_identifier::workroom_contact_callback, this);
          livingroom_contact_subscriber = angen_contact_handle.subscribe("/angen_contact/FCS/livingroom/state", 1000, &room_identifier::workroom_contact_callback, this);
          roomkey_publisher = angen_contact_handle.advertise<angen_turtlebot::navigation_command>("room_key", 2);
        }
        void bedroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr&);
        void kitchen_contact_callback(const gazebo_msgs::ContactsState::ConstPtr&);
        void workroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr&);
        void entranceway_contact_callback(const gazebo_msgs::ContactsState::ConstPtr&);
        void livingroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr&);
        double impact_force_calculator(double, double, double);       
};

double room_identifier::impact_force_calculator(double force_x, double force_y, double force_z)
{
        double resultant_force = sqrt(pow(force_x,2)+ pow(force_y,2)+ pow(force_z,2));
        return resultant_force;
}
        
void room_identifier::bedroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr& DetectState)
{       
        double resultant_force = impact_force_calculator(DetectState->states[0].total_wrench.force.x, DetectState->states[0].total_wrench.force.y, DetectState->states[0].total_wrench.force.z);
        if(resultant_force > TRESHOLD_FORCE)
         {
           std::cout<<resultant_force<<endl;
           ROS_ERROR("A collision in bedroom!  Hey TB, attend to the situation!");
           key.location = 'd';
           roomkey_publisher.publish(key);
         } 
                             
}           	

void room_identifier::kitchen_contact_callback(const gazebo_msgs::ContactsState::ConstPtr& DetectState)
{       
        double resultant_force = impact_force_calculator(DetectState->states[0].total_wrench.force.x, DetectState->states[0].total_wrench.force.y, DetectState->states[0].total_wrench.force.z);
        if(resultant_force > TRESHOLD_FORCE)
         {
           std::cout<<resultant_force<<endl;
           ROS_ERROR("A collision in kitchen!  Hey TB, attend to the situation!");  
           key.location = 'c';
           roomkey_publisher.publish(key);
         }
} 

void room_identifier::workroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr& DetectState)
{       
        double resultant_force = impact_force_calculator(DetectState->states[0].total_wrench.force.x, DetectState->states[0].total_wrench.force.y, DetectState->states[0].total_wrench.force.z);
        if(resultant_force > TRESHOLD_FORCE)
         {
           std::cout<<resultant_force<<endl;
           ROS_ERROR("A collision in workroom!  Hey TB, attend to the situation!");  
           key.location = 'b';
           roomkey_publisher.publish(key);
         }
} 

void room_identifier::entranceway_contact_callback(const gazebo_msgs::ContactsState::ConstPtr& DetectState)
{       
        double resultant_force = impact_force_calculator(DetectState->states[0].total_wrench.force.x, DetectState->states[0].total_wrench.force.y, DetectState->states[0].total_wrench.force.z);
        if(resultant_force > TRESHOLD_FORCE)
         {
           std::cout<<resultant_force<<endl;
           ROS_ERROR("A collision in workroom!  Hey TB, attend to the situation!");  
           key.location = 'i';
           roomkey_publisher.publish(key);
         }
}

void room_identifier::livingroom_contact_callback(const gazebo_msgs::ContactsState::ConstPtr& DetectState)
{       
        double resultant_force = impact_force_calculator(DetectState->states[0].total_wrench.force.x, DetectState->states[0].total_wrench.force.y, DetectState->states[0].total_wrench.force.z);
        if(resultant_force > TRESHOLD_FORCE)
         {
           std::cout<<resultant_force<<endl;
           ROS_ERROR("A collision in workroom!  Hey TB, attend to the situation!");  
           key.location = 'a';
           roomkey_publisher.publish(key);
         }
}

int main(int argc, char **argv)
{
        ros::init(argc, argv, "contact_manager");
        room_identifier RID;
        ros::spin();
        return 0;
}
