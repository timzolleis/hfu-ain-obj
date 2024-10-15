cmake_minimum_required(VERSION 3.29)
project(hfu_ain_obj)

set(CMAKE_CXX_STANDARD 20)


add_executable(task01_task01 task01/task01.cpp)
add_executable(task01_task02 task01/task02.cpp)
add_executable(task01_task03 task01/task03.cpp)

add_executable(task02_task01 task02/task01.cpp)
add_executable(task02_task02 task02/task02.cpp  task02/task01.cpp)
add_executable(task02_task03 task02/task03.cpp)
