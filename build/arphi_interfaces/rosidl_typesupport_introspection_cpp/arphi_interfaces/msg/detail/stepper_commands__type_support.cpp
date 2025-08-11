// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "arphi_interfaces/msg/detail/stepper_commands__functions.h"
#include "arphi_interfaces/msg/detail/stepper_commands__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace arphi_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StepperCommands_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) arphi_interfaces::msg::StepperCommands(_init);
}

void StepperCommands_fini_function(void * message_memory)
{
  auto typed_message = static_cast<arphi_interfaces::msg::StepperCommands *>(message_memory);
  typed_message->~StepperCommands();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StepperCommands_message_member_array[3] = {
  {
    "ds1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arphi_interfaces::msg::StepperCommands, ds1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ds2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arphi_interfaces::msg::StepperCommands, ds2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ds3",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(arphi_interfaces::msg::StepperCommands, ds3),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StepperCommands_message_members = {
  "arphi_interfaces::msg",  // message namespace
  "StepperCommands",  // message name
  3,  // number of fields
  sizeof(arphi_interfaces::msg::StepperCommands),
  false,  // has_any_key_member_
  StepperCommands_message_member_array,  // message members
  StepperCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  StepperCommands_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StepperCommands_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StepperCommands_message_members,
  get_message_typesupport_handle_function,
  &arphi_interfaces__msg__StepperCommands__get_type_hash,
  &arphi_interfaces__msg__StepperCommands__get_type_description,
  &arphi_interfaces__msg__StepperCommands__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace arphi_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<arphi_interfaces::msg::StepperCommands>()
{
  return &::arphi_interfaces::msg::rosidl_typesupport_introspection_cpp::StepperCommands_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, arphi_interfaces, msg, StepperCommands)() {
  return &::arphi_interfaces::msg::rosidl_typesupport_introspection_cpp::StepperCommands_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
