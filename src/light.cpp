#include "ros/ros.h"
#include "std_msgs/Int64.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void lightCallback(const std_msgs::Int64 switch_in)
{
	//std_msgs::Int64 trueVal = 1;
	if(switch_in.data==1){
	system("sudo sh -c \"echo 1 > /sys/class/gpio/gpio206/value\"");
	} else if(switch_in.data==2){
        system("sudo sh -c \"echo 1 > /sys/class/gpio/gpio206/value\"");	
        system("sudo sh -c \"echo 1 > /sys/class/gpio/gpio6/value\"");

	} else {
	system("sudo sh -c \"echo 0 > /sys/class/gpio/gpio206/value\"");
        system("sudo sh -c \"echo 0 > /sys/class/gpio/gpio6/value\"");
	}
}

int main(int argc, char **argv)
{
 
  system("sudo sh -c \"echo 206 > /sys/class/gpio/export\"");
  system("sudo sh -c \"echo out > /sys/class/gpio/gpio206/direction\"");

  system("sudo sh -c \"echo 6 > /sys/class/gpio/export\"");

  system("sudo sh -c \"echo out > /sys/class/gpio/gpio6/direction\"");

  ros::init(argc, argv, "light");

  
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("light", 1, lightCallback);

 
  ros::spin();

  return 0;
}
