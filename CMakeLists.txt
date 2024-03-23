cmake_minimum_required(VERSION 3.10)

project(http)

# Add main.cpp, server.h, and server.cpp to the executable
add_executable(http 
    main.cpp
    server.h
    server.cpp
    server_extra.cpp
)

if(WIN32)
    target_link_libraries(http Ws2_32.lib)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

