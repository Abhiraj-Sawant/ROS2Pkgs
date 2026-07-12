cmake_minimum_required(VERSION 3.8)

project(tutorial_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# Dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


# Generate custom interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "msg/Sphere.msg"
  "srv/Cal.srv"
  DEPENDENCIES geometry_msgs
)


# Generated interface support
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)


########################
# Publisher Subscriber
########################

add_executable(talker src/publisher.cpp)

ament_target_dependencies(
  talker
  rclcpp
)

target_link_libraries(
  talker
  "${cpp_typesupport_target}"
)


add_executable(listener src/subscriber.cpp)

ament_target_dependencies(
  listener
  rclcpp
)

target_link_libraries(
  listener
  "${cpp_typesupport_target}"
)



########################
# Service Server
########################

add_executable(server src/server.cpp)

ament_target_dependencies(
  server
  rclcpp
)

target_link_libraries(
  server
  "${cpp_typesupport_target}"
)



########################
# Service Client
########################

add_executable(client src/client.cpp)

ament_target_dependencies(
  client
  rclcpp
)

target_link_libraries(
  client
  "${cpp_typesupport_target}"
)



# Install all executables

install(TARGETS
  talker
  listener
  server
  client
  DESTINATION lib/${PROJECT_NAME}
)


ament_export_dependencies(rosidl_default_runtime)


if(BUILD_TESTING)

  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_lint_auto_find_test_dependencies()

endif()


install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
