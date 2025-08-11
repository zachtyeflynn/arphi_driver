// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice
#ifndef ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "arphi_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "arphi_interfaces/msg/detail/stepper_commands__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
bool cdr_serialize_arphi_interfaces__msg__StepperCommands(
  const arphi_interfaces__msg__StepperCommands * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
bool cdr_deserialize_arphi_interfaces__msg__StepperCommands(
  eprosima::fastcdr::Cdr &,
  arphi_interfaces__msg__StepperCommands * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
size_t get_serialized_size_arphi_interfaces__msg__StepperCommands(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
size_t max_serialized_size_arphi_interfaces__msg__StepperCommands(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
bool cdr_serialize_key_arphi_interfaces__msg__StepperCommands(
  const arphi_interfaces__msg__StepperCommands * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
size_t get_serialized_size_key_arphi_interfaces__msg__StepperCommands(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
size_t max_serialized_size_key_arphi_interfaces__msg__StepperCommands(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_arphi_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, arphi_interfaces, msg, StepperCommands)();

#ifdef __cplusplus
}
#endif

#endif  // ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
