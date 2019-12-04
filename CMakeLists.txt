cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project main.cpp scratch.cpp Player.cpp Player.h Playlist.cpp Playlist.h)
target_link_libraries(Project "/usr/lib/libSDL2.so")
target_link_libraries(Project "/usr/lib/libSDL2_mixer.so")
target_link_libraries(Project "/usr/lib/libmpg123.so")