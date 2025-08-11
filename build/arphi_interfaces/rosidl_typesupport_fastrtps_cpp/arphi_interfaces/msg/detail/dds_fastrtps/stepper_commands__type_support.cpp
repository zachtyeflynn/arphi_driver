// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice
#include "arphi_interfaces/msg/detail/stepper_commands__rosidl_typesupport_fastrtps_cpp.hpp"
#include "arphi_interfaces/msg/detail/stepper_commands__functions.h"
#include "arphi_interfaces/msg/detail/stepper_commands__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace arphi_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
cdr_serialize(
  const arphi_interfaces::msg::StepperCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ds1
  cdr << ros_message.ds1;

  // Member: ds2
  cdr << ros_message.ds2;

  // Member: ds3
  cdr << ros_message.ds3;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  arphi_interfaces::msg::StepperCommands & ros_message)
{
  // Member: ds1
  cdr >> ros_message.ds1;

  // Member: ds2
  cdr >> ros_message.ds2;

  // Member: ds3
  cdr >> ros_message.ds3;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
get_serialized_size(
  const arphi_interfaces::msg::StepperCommands & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ds1
  {
    size_t item_size = sizeof(ros_message.ds1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: ds2
  {
    size_t item_size = sizeof(ros_message.ds2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: ds3
  {
    size_t item_size = sizeof(ros_message.ds3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
max_serialized_size_StepperCommands(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: ds1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: ds2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: ds3
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = arphi_interfaces::msg::StepperCommands;
    is_plain =
      (
      offsetof(DataType, ds3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
cdr_serialize_key(
  const arphi_interfaces::msg::StepperCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ds1
  cdr << ros_message.ds1;

  // Member: ds2
  cdr << ros_message.ds2;

  // Member: ds3
  cdr << ros_message.ds3;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
get_serialized_size_key(
  const arphi_interfaces::msg::StepperCommands & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ds1
  {
    size_t item_size = sizeof(ros_message.ds1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: ds2
  {
    size_t item_size = sizeof(ros_message.ds2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: ds3
  {
    size_t item_size = sizeof(ros_message.ds3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_arphi_interfaces
max_serialized_size_key_StepperCommands(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: ds1
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ds2
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: ds3
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = arphi_interfaces::msg::StepperCommands;
    is_plain =
      (
      offsetof(DataType, ds3) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _StepperCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const arphi_interfaces::msg::StepperCommands *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StepperCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<arphi_interfaces::msg::StepperCommands *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StepperCommands__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const arphi_interfaces::msg::StepperCommands *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StepperCommands__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_StepperCommands(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _StepperCommands__callbacks = {
  "arphi_interfaces::msg",
  "StepperCommands",
  _StepperCommands__cdr_serialize,
  _StepperCommands__cdr_deserialize,
  _StepperCommands__get_serialized_size,
  _StepperCommands__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _StepperCommands__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_StepperCommands__callbacks,
  get_message_typesupport_handle_function,
  &arphi_interfaces__msg__StepperCommands__get_type_hash,
  &arphi_interfaces__msg__StepperCommands__get_type_description,
  &arphi_interfaces__msg__StepperCommands__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace arphi_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_arphi_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<arphi_interfaces::msg::StepperCommands>()
{
  return &arphi_interfaces::msg::typesupport_fastrtps_cpp::_StepperCommands__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, arphi_interfaces, msg, StepperCommands)() {
  return &arphi_interfaces::msg::typesupport_fastrtps_cpp::_StepperCommands__handle;
}

#ifdef __cplusplus
}
#endif
