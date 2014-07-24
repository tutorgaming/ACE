#include "ros/ros.h"
#include "angen_apps/AngenActuatorsStatus.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
        ros::init(argc, argv, "actuator_controller");
        ros::NodeHandle n;
        ros::ServiceClient status_client = n.serviceClient<angen_apps::AngenActuatorsStatus>("status_manager");
        angen_apps::AngenActuatorsStatus aas;
        aas.request.room_name = std::string(argv[3]);        
        aas.request.actuator_name = std::string(argv[1]);
        aas.request.status = std::string(argv[2]);
        status_client.call(aas);
        return 0;
}
