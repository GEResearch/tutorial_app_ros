cmake_minimum_required(VERSION 2.8.3)
project(tutorialapp)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
)

### Compile
include_directories(
  ${catkin_INCLUDE_DIRS}
)

### Install 
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)

### Test
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)

  add_rostest_gtest(test_app launch/test_app.launch src/tests/test_app.cpp)
  target_link_libraries(test_app ${catkin_LIBRARIES})
endif()



