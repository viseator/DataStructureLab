cmake_minimum_required(VERSION 3.8)
project(DataStructureLab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-static -static-libgcc -static-libstdc++")
set(CMAKE_C_FLAGS "-static -static-libgcc -static-libstdc++")

#set(SOURCE_FILES menu.cpp datastructure/linearlist.h datastructure/linkedlist.c datastructure/linkedlist.h menu.h main.cpp main.h datastructure/BinaryTree.c datastructure/BinaryTree.h tri_tree_menu.c tri_tree_menu.h)
set(SOURCE_FILES main.cpp main.h datastructure/BinaryTree.c datastructure/BinaryTree.h tri_tree_menu.c tri_tree_menu.h)
add_executable(DataStructureLab ${SOURCE_FILES})