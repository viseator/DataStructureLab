cmake_minimum_required(VERSION 3.8)
project(DataStructureLab)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES menu.cpp datastructure/linearlist.h datastructure/linkedlist_.h datastructure/linkedlist.c datastructure/linkedlist.h menu.h main.cpp main.h)
add_executable(DataStructureLab ${SOURCE_FILES})