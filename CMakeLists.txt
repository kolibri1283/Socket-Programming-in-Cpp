cmake_minimum_required(VERSION 3.10)
project(SocketProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files
include_directories(lib)

#add_subdirectory(googletest)
#include_directories(googletest/include)

# Client 
#add_executable(client_app client.cpp )

add_executable(main main.cpp )


# Server 
#add_executable(server_app server.cpp)
