# 1. 规定最低版本
cmake_minimum_required(VERSION 3.8)

# 2. 给这个小测试工程随便起个名字
project(simple_node_test)

# 3. 去系统里找 rclcpp (ROS 2 的 C++ 核心库)
find_package(rclcpp REQUIRED)

# 4. 把你的源码文件，编译成一个叫做 my_first_node 的可执行程序
add_executable(my_first_node ros2_cpp_node.cpp)

# 5. 把 rclcpp 库和你的程序强行绑定在一起
ament_target_dependencies(my_first_node rclcpp)