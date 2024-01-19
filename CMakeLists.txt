cmake_minimum_required(VERSION 3.27)
project(Data_Structures_Algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Structures_Algorithms
        Doubly_Linked_List.cpp
        Doubly_Linked_List.h
        Queue.h
        Stack.h
        testbed.cpp
        Singly_Linked_List.h
        Singly_Linked_List.cpp
        ../../../../Queue.cpp)
