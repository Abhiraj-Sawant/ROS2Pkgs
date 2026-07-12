#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/cal.hpp"

#include <memory>
#include <string>


void calculator(
  const std::shared_ptr<tutorial_interfaces::srv::Cal::Request> request,
  std::shared_ptr<tutorial_interfaces::srv::Cal::Response> response)
{

  RCLCPP_INFO(
    rclcpp::get_logger("rclcpp"),
    "Incoming request: a=%ld b=%ld c=%ld operation=%s",
    request->a,
    request->b,
    request->c,
    request->operation.c_str()
  );


  if (request->operation == "add")
  {
    response->result =
      request->a + request->b + request->c;

    response->success = true;
    response->message = "Addition successful";
  }


  else if (request->operation == "sub")
  {
    response->result =
      request->a - request->b - request->c;

    response->success = true;
    response->message = "Subtraction successful";
  }


  else if (request->operation == "mul")
  {
    response->result =
      request->a * request->b * request->c;

    response->success = true;
    response->message = "Multiplication successful";
  }


  else if (request->operation == "div")
  {
    if (request->b == 0 || request->c == 0)
    {
      response->result = 0;
      response->success = false;
      response->message = "Division by zero not allowed";
    }

    else
    {
      response->result =
        request->a / request->b / request->c;

      response->success = true;
      response->message = "Division successful";
    }
  }


  else
  {
    response->result = 0;
    response->success = false;
    response->message = "Invalid operation";
  }


  RCLCPP_INFO(
    rclcpp::get_logger("rclcpp"),
    "Sending response: %ld",
    response->result
  );

}



int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);


  auto node =
    rclcpp::Node::make_shared("calculator_server");


  auto service =
    node->create_service<tutorial_interfaces::srv::Cal>(
      "calculator",
      &calculator
    );


  RCLCPP_INFO(
    rclcpp::get_logger("rclcpp"),
    "Calculator service is ready..."
  );


  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}
