#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gtest/gtest.h>

ros::Publisher request_pub;
ros::Subscriber response_sub;

int heardback = 0;
std::string rcvdMsg;

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Test node heard echoed value '%s' from 'chatter' topic", msg->data.c_str());
  heardback = 1;
  rcvdMsg =  msg->data.c_str();
}


TEST(TestSuite, echoTestCase1)
{
  std::string msgToVerify;
  msgToVerify = "Hello World!";

  //Publish test message
  ROS_INFO("Publishing test message '%s'...",msgToVerify.c_str());
  ros::Rate timer(1);
  std_msgs::String rosMsg;
  rosMsg.data = msgToVerify;
  request_pub.publish(rosMsg); timer.sleep();  //don't remove - this is workaround for ROS nuances 
  request_pub.publish(rosMsg);

  //Wait for the return mesage so we can verify below
  while (ros::ok() && !heardback) {
    ros::spinOnce(); 
    timer.sleep();
  }

  //Verify:
  //original message should not change because
  //it is simple echo without any transformation
  EXPECT_EQ(rcvdMsg,
            msgToVerify);  
}




int main(int argc, char **argv){

  //Create ROS node that performs testing activities (i.e. pub/sub)  
  ros::init(argc, argv, "test_echo");
  ros::NodeHandle n;
  request_pub  = n.advertise<std_msgs::String>("chatterRequest", 1000);
  response_sub = n.subscribe("chatter", 1000, chatterCallback);
    
  //Run all tests
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

