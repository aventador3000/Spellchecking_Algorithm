cmake_minimum_required(VERSION 3.0)

project(SpellChecking CXX)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

# to enable c++11 in gcc (nullptr and so on) - strict mode, can lead to some issues with gtest
# use gnu++11 instead
set(CMAKE_CXX_FLAGS "   ${CMAKE_CXX_FLAGS} -std=gnu++11")

# need to define WINVER macros in order to work with OpenThread in MinGW correctly!
set(CMAKE_CXX_FLAGS "   ${CMAKE_CXX_FLAGS} -DWINVER=0x0500")

add_subdirectory(src)
#add_subdirectory(tests)