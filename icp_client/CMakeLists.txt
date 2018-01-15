cmake_minimum_required(VERSION 3.8)
project(icp_client)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(icp_client ${SOURCE_FILES})