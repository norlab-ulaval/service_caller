cmake_minimum_required(VERSION 3.8)
project(service_caller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)

include_directories(
	include
)

add_library(service_caller
    src/ServiceCaller.cpp
)

ament_target_dependencies(service_caller
    rclcpp
    std_srvs
)

install(DIRECTORY include
    DESTINATION include/${PROJECT_NAME}
)
install(TARGETS service_caller
    EXPORT export_service_caller
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

ament_export_include_directories("include/${PROJECT_NAME}/include")
ament_export_libraries(service_caller)
ament_export_dependencies(rclcpp std_srvs)

ament_package()
