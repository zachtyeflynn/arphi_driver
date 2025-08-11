// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "arphi_interfaces/msg/stepper_commands.hpp"


#ifndef ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_HPP_
#define ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__arphi_interfaces__msg__StepperCommands __attribute__((deprecated))
#else
# define DEPRECATED__arphi_interfaces__msg__StepperCommands __declspec(deprecated)
#endif

namespace arphi_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StepperCommands_
{
  using Type = StepperCommands_<ContainerAllocator>;

  explicit StepperCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ds1 = 0l;
      this->ds2 = 0l;
      this->ds3 = 0l;
    }
  }

  explicit StepperCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ds1 = 0l;
      this->ds2 = 0l;
      this->ds3 = 0l;
    }
  }

  // field types and members
  using _ds1_type =
    int32_t;
  _ds1_type ds1;
  using _ds2_type =
    int32_t;
  _ds2_type ds2;
  using _ds3_type =
    int32_t;
  _ds3_type ds3;

  // setters for named parameter idiom
  Type & set__ds1(
    const int32_t & _arg)
  {
    this->ds1 = _arg;
    return *this;
  }
  Type & set__ds2(
    const int32_t & _arg)
  {
    this->ds2 = _arg;
    return *this;
  }
  Type & set__ds3(
    const int32_t & _arg)
  {
    this->ds3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    arphi_interfaces::msg::StepperCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const arphi_interfaces::msg::StepperCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      arphi_interfaces::msg::StepperCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      arphi_interfaces::msg::StepperCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__arphi_interfaces__msg__StepperCommands
    std::shared_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__arphi_interfaces__msg__StepperCommands
    std::shared_ptr<arphi_interfaces::msg::StepperCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StepperCommands_ & other) const
  {
    if (this->ds1 != other.ds1) {
      return false;
    }
    if (this->ds2 != other.ds2) {
      return false;
    }
    if (this->ds3 != other.ds3) {
      return false;
    }
    return true;
  }
  bool operator!=(const StepperCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StepperCommands_

// alias to use template instance with default allocator
using StepperCommands =
  arphi_interfaces::msg::StepperCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace arphi_interfaces

#endif  // ARPHI_INTERFACES__MSG__DETAIL__STEPPER_COMMANDS__STRUCT_HPP_
