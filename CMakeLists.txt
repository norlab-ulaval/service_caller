cmake_minimum_required(VERSION 3.8)
project(service_caller)

set(CMAKE_BUILD_TYPE "Release")

find_package(ament_cmake REQUIRED)

install(DIRECTORY include
    DESTINATION include/${PROJECT_NAME}
)

ament_export_include_directories("include/${PROJECT_NAME}/include")
ament_export_dependencies(rclcpp)

ament_package()
