cmake_minimum_required(VERSION 3.23)
project(song)

set(CMAKE_CXX_STANDARD 20)

add_executable(song main.cpp Song.cpp Song.h SongUserInterface.cpp SongUserInterface.h)
