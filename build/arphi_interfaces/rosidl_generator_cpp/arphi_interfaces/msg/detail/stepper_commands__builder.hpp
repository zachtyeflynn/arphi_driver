// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arphi_interfaces/msg/stepper_commands.hpp"


#ifndef ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__BUILDER_HPP_
#define ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "arphi_interfaces/msg/detail/stepper_commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace arphi_interfaces
{

namespace msg
{

namespace builder
{

class Init_StepperCommands_ds3
{
public:
  explicit Init_StepperCommands_ds3(::arphi_interfaces::msg::StepperCommands & msg)
  : msg_(msg)
  {}
  ::arphi_interfaces::msg::StepperCommands ds3(::arphi_interfaces::msg::StepperCommands::_ds3_type arg)
  {
    msg_.ds3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::arphi_interfaces::msg::StepperCommands msg_;
};

class Init_StepperCommands_ds2
{
public:
  explicit Init_StepperCommands_ds2(::arphi_interfaces::msg::StepperCommands & msg)
  : msg_(msg)
  {}
  Init_StepperCommands_ds3 ds2(::arphi_interfaces::msg::StepperCommands::_ds2_type arg)
  {
    msg_.ds2 = std::move(arg);
    return Init_StepperCommands_ds3(msg_);
  }

private:
  ::arphi_interfaces::msg::StepperCommands msg_;
};

class Init_StepperCommands_ds1
{
public:
  Init_StepperCommands_ds1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StepperCommands_ds2 ds1(::arphi_interfaces::msg::StepperCommands::_ds1_type arg)
  {
    msg_.ds1 = std::move(arg);
    return Init_StepperCommands_ds2(msg_);
  }

private:
  ::arphi_interfaces::msg::StepperCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::arphi_interfaces::msg::StepperCommands>()
{
  return arphi_interfaces::msg::builder::Init_StepperCommands_ds1();
}

}  // namespace arphi_interfaces

#endif  // ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__BUILDER_HPP_
