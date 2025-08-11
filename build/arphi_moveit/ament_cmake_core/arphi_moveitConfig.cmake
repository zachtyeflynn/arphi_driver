# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_arphi_moveit_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED arphi_moveit_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(arphi_moveit_FOUND FALSE)
  elseif(NOT arphi_moveit_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(arphi_moveit_FOUND FALSE)
  endif()
  return()
endif()
set(_arphi_moveit_CONFIG_INCLUDED TRUE)

# output package information
if(NOT arphi_moveit_FIND_QUIETLY)
  message(STATUS "Found arphi_moveit: 1.0.0 (${arphi_moveit_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'arphi_moveit' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT arphi_moveit_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(arphi_moveit_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${arphi_moveit_DIR}/${_extra}")
endforeach()
