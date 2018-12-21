cmake_minimum_required(VERSION 2.8.3)
project(appservices)

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

add_executable(echo src/echo.cpp)
target_link_libraries(echo ${catkin_LIBRARIES})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

### Install 
install(TARGETS echo talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)

### Test
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)

  add_rostest_gtest(test_echo launch/echo.launch src/tests/test_echo.cpp)
  target_link_libraries(test_echo ${catkin_LIBRARIES})

  add_rostest_gtest(test_talker launch/talker.launch src/tests/test_talker.cpp)
  target_link_libraries(test_talker ${catkin_LIBRARIES})
endif()



