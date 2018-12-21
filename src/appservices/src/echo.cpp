#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

ros::Publisher chatter_pub;
ros::Subscriber request_sub;

void chatterRequestCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Echo node  heard: '%s' so echoing to chatter topic...", msg->data.c_str());
  chatter_pub.publish(msg);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "echo");

  ros::NodeHandle n;

  request_sub = n.subscribe("chatterRequest", 1000, chatterRequestCallback);

  chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::spin();

  return 0;
}



