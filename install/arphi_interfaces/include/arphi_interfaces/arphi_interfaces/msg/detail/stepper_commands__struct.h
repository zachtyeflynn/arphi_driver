// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arphi_interfaces/msg/stepper_commands.h"


#ifndef ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_H_
#define ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/StepperCommands in the package arphi_interfaces.
typedef struct arphi_interfaces__msg__StepperCommands
{
  int32_t ds1;
  int32_t ds2;
  int32_t ds3;
} arphi_interfaces__msg__StepperCommands;

// Struct for a sequence of arphi_interfaces__msg__StepperCommands.
typedef struct arphi_interfaces__msg__StepperCommands__Sequence
{
  arphi_interfaces__msg__StepperCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} arphi_interfaces__msg__StepperCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_H_
