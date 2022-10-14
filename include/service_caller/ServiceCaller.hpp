#ifndef SERVICE_CALLER_SERVICECALLER_HPP
#define SERVICE_CALLER_SERVICECALLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <memory>

namespace rclcpp
{
    class ServiceCaller : public rclcpp::Node
    {
    public:
        ServiceCaller():
                rclcpp::Node("service_caller")
        {
        }
    };

    template<typename ServiceType>
    typename ServiceType::Response call_service(const std::string& serviceName, std::shared_ptr<typename ServiceType::Request> req)
    {
        std::shared_ptr<ServiceCaller> serviceCallerNode = std::make_shared<ServiceCaller>();
        typename rclcpp::Client<ServiceType>::SharedPtr client = serviceCallerNode->create_client<ServiceType>(serviceName);
        bool serviceExists = client->wait_for_service(std::chrono::seconds(5));
        if(!serviceExists)
        {
            throw std::runtime_error("Timeout on wait for requested service: " + serviceName);
        }
        rclcpp::detail::FutureAndRequestId future = client->async_send_request(req);
        rclcpp::spin_until_future_complete(serviceCallerNode, future);
        return *future.get();
    }
}

#endif
