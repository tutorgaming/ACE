#include <cstdio>
#include "tf/transform_listener.h"
#include "tf/transform_datatypes.h"
 #include "ros/ros.h"
#include"geometry_msgs/PoseStamped.h"
//#include"KeyManager.h"

bool toLog;

class current_pose_publisher
{
public:

	tf::TransformListener tf;
	ros::NodeHandle nodehand;
	ros::Publisher CurrentPosePublisher;
  //constructor with name
  	current_pose_publisher()
  	{
		CurrentPosePublisher = nodehand.advertise<geometry_msgs::PoseStamped>("current_pose", 10);
  	};

  	~current_pose_publisher()
 	{

  	};

 private:

};


int main(int argc, char ** argv)
{
  //Initialize ROS
  ros::init(argc, argv, "current_pose_publisher", ros::init_options::AnonymousName);

  ros::NodeHandle nh;
  //Instantiate a local listener
  current_pose_publisher current_pose_publisher;

  //	parent frame: it will be the common frame for all the devices (RFID, Stargazer, Kinect)
  std::string source_frameid = std::string("/map");
  //	target frame: base_link is the one used to localize the robot by the kinect
  //	starGazer frame: starRobot
  //
  std::string target_frameid = std::string("base_link");


  if(argc>1){
	  if(strcmp(argv[1],"--log")==0){
		  toLog=true;
		  std::cout << "LOG" <<std::endl; getchar();
	  }
  }

  FILE *log_fd;

  if(toLog){
		log_fd=fopen("single_run.txt", "w+");
  }

  // Wait for up to one second for the first transforms to become avaiable. 
  current_pose_publisher.tf.waitForTransform(source_frameid, target_frameid, ros::Time(), ros::Duration(1.0));


  ros::Rate loop_rate(10);
  //Nothing needs to be done except wait for a quit
  //The callbacks withing the listener class
  //will take care of everything
  while(nh.ok())
    {
     a: 
     try
      {
        tf::StampedTransform global_pose;
        current_pose_publisher.tf.lookupTransform(source_frameid, target_frameid, ros::Time(), global_pose);

	/* GET THE ORIGIN AND ORIENTATION OF THE FRAME */	       
        tf::Quaternion q = global_pose.getRotation();
        tf::Vector3 v = global_pose.getOrigin();
        
        /* CREATE VARIABLES FOR PUBLISHING SINCE tf TYPE MESSAGES CANNOT BE EQUATED TO THE PoseStamped TYPE */
        geometry_msgs::Point RobotCurrentPose_P;
        geometry_msgs::Quaternion RobotCurrentPose_Q;
        
        /* CONVERSION */
        tf::pointTFToMsg(v, RobotCurrentPose_P);
        tf::quaternionTFToMsg(q, RobotCurrentPose_Q);
        
        geometry_msgs::PoseStamped RobotCurrentPose;
        
      	RobotCurrentPose.header.stamp = ros::Time();
      	RobotCurrentPose.header.frame_id= "/map";

        /* EQUATION */
        RobotCurrentPose.pose.position = RobotCurrentPose_P;
        RobotCurrentPose.pose.orientation = RobotCurrentPose_Q;
        
        /* DISPATCH */
        current_pose_publisher.CurrentPosePublisher.publish(RobotCurrentPose);
        

        if(toLog){

        	float x,y,z,a;
        	x=RobotCurrentPose.pose.position.x;
        	y=RobotCurrentPose.pose.position.y;
        	z=RobotCurrentPose.pose.position.z;
        	double yaw, pitch, roll;
        	tf::Matrix3x3(q).getEulerYPR(yaw,pitch,roll);
        	a=yaw;

        	char rstate[200];
        	sprintf(rstate,"%+.3f %+.3f %+.3f %.4f",x,y,z,a);
        	fprintf(log_fd, "%s\n", rstate);

        }
        std::cout << "CYCLE" << std::endl;

      }
      catch(tf::TransformException& ex)
      {
        std::cout << "Failure at "<< ros::Time::now() << std::endl;
//        std::cout << "Exception thrown:" << ex.what()<< std::endl;
        std::cout << "The current list of frames is:" <<std::endl;
//        std::cout << current_pose_publisher.tf.allFramesAsString()<<std::endl;
        goto a;  
      }
      loop_rate.sleep();
    }
  fclose(log_fd);
  return 0;
};

