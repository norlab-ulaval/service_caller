# service_caller
Library that allows synchronous ROS2 service calls in c++.

# Usage
```c++
#include "service_caller/ServiceCaller.hpp"

std::shared_ptr<std_srvs::srv::Empty::Request> request = std::make_shared<std_srvs::srv::Empty::Request>();
std_srvs::srv::Empty::Response response = rclcpp::call_service<std_srvs::srv::Empty>("service", request);
```
