# appservices ROS package

An example of ROS package that is specific to this app. Therefore, it is not located in a separate repo as other ROS packages in this app

## `talker` ROS node API

`talker` ROS node  publishes test data periodically

### Published Topics:

Topic | Data type | Description
---- | ----- | -----
chatterRequest | [std_msgs/String](http://docs.ros.org/api/std_msgs/html/msg/String.html) | Publish content periodically into this entry point of the whole app

## `echo` ROS node API

`echo` ROS node simply redirects/echoes data from one topic to another 

### Subscribed Topics:

Topic | Data type | Description
---- | ----- | -----
chatterRequest | [std_msgs/String](http://docs.ros.org/api/std_msgs/html/msg/String.html) | Data to be redirected/echoed

### Published Topics:

Topic | Data type | Description
---- | ----- | -----
chatter | [std_msgs/String](http://docs.ros.org/api/std_msgs/html/msg/String.html) | Redirected/echoed data






