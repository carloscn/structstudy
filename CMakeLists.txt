cmake_minimum_required(VERSION 3.12)
project(STRUCTOR)

set(CMAKE_CXX_STANDARD 14)

add_executable(STRUCTOR main.cpp DyArray.cpp DyArray.h LineStack.h ArrayStack.cpp ArrayStack.h Solution.cpp Solution.h LineQueue.h ArrayQueue.cpp ArrayQueue.h LoopQueue.cpp LoopQueue.h LinkedList.cpp LinkedList.h)