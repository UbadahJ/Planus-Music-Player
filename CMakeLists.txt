cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp)
target_link_libraries(Project "/usr/lib/libao.so")
target_link_libraries(Project "/usr/lib/libmpg123.so")