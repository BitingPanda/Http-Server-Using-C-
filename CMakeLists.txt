cmake_minimum_required(VERSION 3.10)


project(http)


add_executable(http main.cpp)

if(WIN32)
  target_link_libraries(http wsock32 ws2_32)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
