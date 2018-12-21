#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatterRequest", 1000);

  ros::Rate loop_rate(0.25); //publish something to chatterRequest topic every ~5 sec

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world";
    msg.data = ss.str();

    ROS_INFO("Talker said '%s' seq# %d", msg.data.c_str(),count);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
	
    ++count;
  }


  return 0;
}



