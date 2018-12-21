# tutorialapp ROS package

Only function of this ROS package is to run integration tests for the whole application in the form of `test_app` ROS node

## `test_app` ROS node API

`test_app` ROS node  publishes test data into the entry topic of the whole app (see below) and then listens and verifies the result of the system
on the subscribed topic (see below)

### Published Topics:

Topic | Data type | Description
---- | ----- | -----
chatterRequest | [std_msgs/String](http://docs.ros.org/api/std_msgs/html/msg/String.html) | Publish test content into this entry point of the whole app

### Subscribed Topics:

Topic | Data type | Description
---- | ----- | -----
chatterResponse | [std_msgs/String](http://docs.ros.org/api/std_msgs/html/msg/String.html) | Resulting content of the whole app





