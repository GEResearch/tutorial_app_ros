#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gtest/gtest.h>

ros::Subscriber request_sub;

int heardback = 0;
std::string rcvdMsg;

void chatterRequestCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Test node heard '%s' from chatterRequest topic", msg->data.c_str());
  heardback = 1;
  rcvdMsg =  msg->data.c_str();
}


TEST(TestSuite, translatorTestCase1)
{
  std::string msgToVerify;
  msgToVerify = "hello world";   //This is what talker.cpp keeps saying

  ros::Rate timer(1);

  //Wait for the first message
  while (ros::ok() && !heardback) {
    ros::spinOnce(); 
    timer.sleep();
  }

  //Verify
  //It is supposed to be the same as talker.cpp keeps saying
  EXPECT_EQ(rcvdMsg,
            msgToVerify); 
}




int main(int argc, char **argv){

  //Create ROS node that performs testing activities (i.e. pub/sub)  
  ros::init(argc, argv, "test_talker");
  ros::NodeHandle n;
  request_sub = n.subscribe("chatterRequest", 1000, chatterRequestCallback);
    
  //Run all tests
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

