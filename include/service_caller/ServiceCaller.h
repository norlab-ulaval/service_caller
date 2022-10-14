#ifndef SERVICE_CALLER_SERVICECALLER_H
#define SERVICE_CALLER_SERVICECALLER_H

#include <string>
#include <memory>

namespace rclcpp
{
    template<typename ServiceType>
    typename ServiceType::Response call_service(const std::string& serviceName, std::shared_ptr<typename ServiceType::Request> req);
}

#endif
