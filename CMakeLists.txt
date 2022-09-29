cmake_minimum_required(VERSION 3.23)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedList main.cpp Node.cpp Node.h NodePointer.cpp NodePointer.h LinkedList.cpp LinkedList.h DoubleNodePointer.cpp DoubleNodePointer.h DoubleLinkedList.cpp DoubleLinkedList.h)
