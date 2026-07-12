#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/cal.hpp"

#include <chrono>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("calculator_client");

    node->declare_parameter("a", 0);
    node->declare_parameter("b", 0);
    node->declare_parameter("c", 0);
    node->declare_parameter("operation", "add");

    auto request =
        std::make_shared<tutorial_interfaces::srv::Cal::Request>();

    request->a =
        node->get_parameter("a").as_int();

    request->b =
        node->get_parameter("b").as_int();

    request->c =
        node->get_parameter("c").as_int();

    request->operation =
        node->get_parameter("operation").as_string();

    auto client =
        node->create_client<tutorial_interfaces::srv::Cal>("calculator");

    while (!client->wait_for_service(1s))
    {
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(
                node->get_logger(),
                "Interrupted while waiting for service.");

            return 0;
        }

        RCLCPP_INFO(
            node->get_logger(),
            "Waiting for calculator service...");
    }

    auto future = client->async_send_request(request);

    if (rclcpp::spin_until_future_complete(node, future) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        auto response = future.get();

        RCLCPP_INFO(
            node->get_logger(),
            "Result = %ld",
            response->result);

        RCLCPP_INFO(
            node->get_logger(),
            "Message = %s",
            response->message.c_str());
    }
    else
    {
        RCLCPP_ERROR(
            node->get_logger(),
            "Failed to call calculator service.");
    }

    rclcpp::shutdown();

    return 0;
}
