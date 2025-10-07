cmake_minimum_required(VERSION 3.10)
project(SocketProgramming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Threads REQUIRED)

# Header files - Updated to include folder instead of lib
include_directories(include)

# Enable multithreading support
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

# Main executable with threading support
add_executable(main main.cpp)

# Link threading library
target_link_libraries(main PRIVATE Threads::Threads)

# Windows specific socket library linking
if(WIN32)
    target_link_libraries(main PRIVATE ws2_32 wsock32)
endif()

# Set compiler flags for threading
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(main PRIVATE -pthread)
endif()

