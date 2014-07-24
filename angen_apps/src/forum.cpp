#include "ros/ros.h"
#include "gazebo_msgs/GetLinkState.h"

using namespace std;

int main(int argc, char** argv)
{
ros::init(argc, argv, "forum");
ros::NodeHandle n;
ros::service::waitForService("gazebo/get_link_state");
ros::ServiceClient gls_client = n.serviceClient<gazebo_msgs::GetLinkState>("gazebo/get_link_state");
gazebo_msgs::GetLinkState gls_request;
if (gls_client.exists()) 
{ ROS_INFO("link state exists"); gls_request.request.link_name = string("right_hand"); gls_request.request.reference_frame=string("world"); gls_client.call(gls_request); } 
else 
{ ROS_INFO("Something went wrong"); }
return 0;
}
