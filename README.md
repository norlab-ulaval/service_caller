# service_caller
Library that allows synchronous ROS2 service calls in c++.

# Usage
```c++
#include "service_caller/ServiceCaller.h"

std::shared_ptr<std_srvs::srv::Empty::Request> request = std::make_shared<std_srvs::srv::Empty::Request>();
std_srvs::srv::Empty::Response response = rclcpp::call_service<std_srvs::srv::Empty>("service", request);
```

# Extending the library
Currently, only std_srvs/Empty services are supported, but new service types can easily be added.
To add a new service type, simply add a new template specialization at the end of src/ServiceCaller.cpp as follows:
```c++
template
SERVICE_RESPONSE_TYPE rclcpp::call_service<SERVICE_TYPE>(const std::string& serviceName, std::shared_ptr<SERVICE_REQUEST_TYPE> req);
```
