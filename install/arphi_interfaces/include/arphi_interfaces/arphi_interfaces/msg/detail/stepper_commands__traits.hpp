// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arphi_interfaces/msg/stepper_commands.hpp"


#ifndef ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__TRAITS_HPP_
#define ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "arphi_interfaces/msg/detail/stepper_commands__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace arphi_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StepperCommands & msg,
  std::ostream & out)
{
  out << "{";
  // member: ds1
  {
    out << "ds1: ";
    rosidl_generator_traits::value_to_yaml(msg.ds1, out);
    out << ", ";
  }

  // member: ds2
  {
    out << "ds2: ";
    rosidl_generator_traits::value_to_yaml(msg.ds2, out);
    out << ", ";
  }

  // member: ds3
  {
    out << "ds3: ";
    rosidl_generator_traits::value_to_yaml(msg.ds3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StepperCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ds1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ds1: ";
    rosidl_generator_traits::value_to_yaml(msg.ds1, out);
    out << "\n";
  }

  // member: ds2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ds2: ";
    rosidl_generator_traits::value_to_yaml(msg.ds2, out);
    out << "\n";
  }

  // member: ds3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ds3: ";
    rosidl_generator_traits::value_to_yaml(msg.ds3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StepperCommands & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace arphi_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use arphi_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const arphi_interfaces::msg::StepperCommands & msg,
  std::ostream & out, size_t indentation = 0)
{
  arphi_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use arphi_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const arphi_interfaces::msg::StepperCommands & msg)
{
  return arphi_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<arphi_interfaces::msg::StepperCommands>()
{
  return "arphi_interfaces::msg::StepperCommands";
}

template<>
inline const char * name<arphi_interfaces::msg::StepperCommands>()
{
  return "arphi_interfaces/msg/StepperCommands";
}

template<>
struct has_fixed_size<arphi_interfaces::msg::StepperCommands>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<arphi_interfaces::msg::StepperCommands>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<arphi_interfaces::msg::StepperCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__TRAITS_HPP_
