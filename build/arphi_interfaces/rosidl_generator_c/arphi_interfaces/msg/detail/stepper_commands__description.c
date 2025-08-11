// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

#include "arphi_interfaces/msg/detail/stepper_commands__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_arphi_interfaces
const rosidl_type_hash_t *
arphi_interfaces__msg__StepperCommands__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0xff, 0x12, 0x6f, 0xe0, 0xd3, 0xca, 0xd8,
      0xc4, 0xd3, 0x70, 0x1e, 0x33, 0x6c, 0xd5, 0xf5,
      0x1e, 0x31, 0x7d, 0xfe, 0x43, 0xcf, 0xec, 0xae,
      0xa1, 0xda, 0x0b, 0x1e, 0x9c, 0xe9, 0xba, 0xd4,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char arphi_interfaces__msg__StepperCommands__TYPE_NAME[] = "arphi_interfaces/msg/StepperCommands";

// Define type names, field names, and default values
static char arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds1[] = "ds1";
static char arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds2[] = "ds2";
static char arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds3[] = "ds3";

static rosidl_runtime_c__type_description__Field arphi_interfaces__msg__StepperCommands__FIELDS[] = {
  {
    {arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds1, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds2, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {arphi_interfaces__msg__StepperCommands__FIELD_NAME__ds3, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
arphi_interfaces__msg__StepperCommands__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {arphi_interfaces__msg__StepperCommands__TYPE_NAME, 36, 36},
      {arphi_interfaces__msg__StepperCommands__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 ds1\n"
  "int32 ds2\n"
  "int32 ds3";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
arphi_interfaces__msg__StepperCommands__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {arphi_interfaces__msg__StepperCommands__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
arphi_interfaces__msg__StepperCommands__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *arphi_interfaces__msg__StepperCommands__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
