#include<iostream>
#include"ros/ros.h"
#include"ros/param.h"
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
        ros::init(argc, argv, "params");
        ros::NodeHandle nh;
        
        string gbf; double bar;
        nh.param("/gap_between_floors", bar, 0.1);
        cout<<bar;
        float f = atof(gbf.c_str());
        cout<<gbf<<endl;
        cout<<f<<endl;
        char g = system("rosparam get /gap_between_floors");
        cout<<g<<endl;
        return 0;
}
