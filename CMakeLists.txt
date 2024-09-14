cmake_minimum_required(VERSION 3.29)
project(CO650_TASK2)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(CO650_TASK2_SERVER server.cpp src/Comms.cpp)
add_executable(CO650_TASK2_CLIENT client.cpp src/Comms.cpp)