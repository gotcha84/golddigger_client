cmake_minimum_required(VERSION 2.8.3)
project(light_node)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package( CATKIN_DEPENDS message_runtime)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})



add_executable(light src/light.cpp)
add_dependencies(light light_node_gencpp)
target_link_libraries(light ${catkin_LIBRARIES})

add_message_files(
	FILES
	Light.msg
)


