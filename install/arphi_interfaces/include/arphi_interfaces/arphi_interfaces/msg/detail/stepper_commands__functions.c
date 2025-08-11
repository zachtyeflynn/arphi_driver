// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from arphi_interfaces:msg/StepperCommands.idl
// generated code does not contain a copyright notice
#include "arphi_interfaces/msg/detail/stepper_commands__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
arphi_interfaces__msg__StepperCommands__init(arphi_interfaces__msg__StepperCommands * msg)
{
  if (!msg) {
    return false;
  }
  // ds1
  // ds2
  // ds3
  return true;
}

void
arphi_interfaces__msg__StepperCommands__fini(arphi_interfaces__msg__StepperCommands * msg)
{
  if (!msg) {
    return;
  }
  // ds1
  // ds2
  // ds3
}

bool
arphi_interfaces__msg__StepperCommands__are_equal(const arphi_interfaces__msg__StepperCommands * lhs, const arphi_interfaces__msg__StepperCommands * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ds1
  if (lhs->ds1 != rhs->ds1) {
    return false;
  }
  // ds2
  if (lhs->ds2 != rhs->ds2) {
    return false;
  }
  // ds3
  if (lhs->ds3 != rhs->ds3) {
    return false;
  }
  return true;
}

bool
arphi_interfaces__msg__StepperCommands__copy(
  const arphi_interfaces__msg__StepperCommands * input,
  arphi_interfaces__msg__StepperCommands * output)
{
  if (!input || !output) {
    return false;
  }
  // ds1
  output->ds1 = input->ds1;
  // ds2
  output->ds2 = input->ds2;
  // ds3
  output->ds3 = input->ds3;
  return true;
}

arphi_interfaces__msg__StepperCommands *
arphi_interfaces__msg__StepperCommands__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arphi_interfaces__msg__StepperCommands * msg = (arphi_interfaces__msg__StepperCommands *)allocator.allocate(sizeof(arphi_interfaces__msg__StepperCommands), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(arphi_interfaces__msg__StepperCommands));
  bool success = arphi_interfaces__msg__StepperCommands__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
arphi_interfaces__msg__StepperCommands__destroy(arphi_interfaces__msg__StepperCommands * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    arphi_interfaces__msg__StepperCommands__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
arphi_interfaces__msg__StepperCommands__Sequence__init(arphi_interfaces__msg__StepperCommands__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arphi_interfaces__msg__StepperCommands * data = NULL;

  if (size) {
    data = (arphi_interfaces__msg__StepperCommands *)allocator.zero_allocate(size, sizeof(arphi_interfaces__msg__StepperCommands), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = arphi_interfaces__msg__StepperCommands__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        arphi_interfaces__msg__StepperCommands__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
arphi_interfaces__msg__StepperCommands__Sequence__fini(arphi_interfaces__msg__StepperCommands__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      arphi_interfaces__msg__StepperCommands__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

arphi_interfaces__msg__StepperCommands__Sequence *
arphi_interfaces__msg__StepperCommands__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  arphi_interfaces__msg__StepperCommands__Sequence * array = (arphi_interfaces__msg__StepperCommands__Sequence *)allocator.allocate(sizeof(arphi_interfaces__msg__StepperCommands__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = arphi_interfaces__msg__StepperCommands__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
arphi_interfaces__msg__StepperCommands__Sequence__destroy(arphi_interfaces__msg__StepperCommands__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    arphi_interfaces__msg__StepperCommands__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
arphi_interfaces__msg__StepperCommands__Sequence__are_equal(const arphi_interfaces__msg__StepperCommands__Sequence * lhs, const arphi_interfaces__msg__StepperCommands__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!arphi_interfaces__msg__StepperCommands__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
arphi_interfaces__msg__StepperCommands__Sequence__copy(
  const arphi_interfaces__msg__StepperCommands__Sequence * input,
  arphi_interfaces__msg__StepperCommands__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(arphi_interfaces__msg__StepperCommands);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    arphi_interfaces__msg__StepperCommands * data =
      (arphi_interfaces__msg__StepperCommands *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!arphi_interfaces__msg__StepperCommands__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          arphi_interfaces__msg__StepperCommands__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!arphi_interfaces__msg__StepperCommands__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
