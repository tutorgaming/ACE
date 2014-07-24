#include "ros/ros.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"
#include "move_base_msgs/MoveBaseActionGoal.h"
#include <ros/callback_queue.h>
#include "angen_turtlebot/navigaton_status.h"
#include <sstream>
#include <string>
#include "angen_turtlebot/key_handler.h"
#include "angen_turtlebot/navigation_manager.h"



	
using namespace ros;
using namespace std;

int main(int argc, char **argv)
{
	int v=0;
	ros::init(argc, argv, "key_based_nav");
	Select sel;
	sel.extract();
	while(ros::ok() && !COMPLETE)
	{
		if(KeyHandler::get_is_key_there())
		{
			if(KeyHandler::get_ticket())
			{
				if(sel.get_place_key() == 'h')				
				{
                                        KeyHandler::reset_ticket();
                                        KeyHandler::reset_is_key_there();
                                        KeyHandler::set_task_complete();
                                }

				else sel.publish_points();
			}		
		}
		else
		     {if (v==5) ROS_INFO("Waiting for Room Key");
		     v++;}
		ros::getGlobalCallbackQueue()->callAvailable(ros::WallDuration(1.0));
			
	}	
	COMPLETE = false;
	KeyHandler::reset_is_key_there();
	KeyHandler::set_task_complete();
	KeyHandler::reset_ticket();
	ros::spin();
}
