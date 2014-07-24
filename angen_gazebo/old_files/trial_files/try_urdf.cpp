#include <collada_urdf/collada_urdf.h>
#include "ros/ros.h"

using namespace std;
using namespace ros;
 
int main(int argc, char **argv)
{
        boost::shared_ptr<DAE> dom;
        if (!collada_urdf::colladaFromUrdfFile("/home/angenuser/floor.urdf", dom)) {
        ROS_ERROR("Failed to construct COLLADA DOM");
        return false;}
        collada_urdf::colladaToFile(dom, "floor.dae");
}
