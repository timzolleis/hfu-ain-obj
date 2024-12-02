cmake_minimum_required(VERSION 3.29)
project(hfu_ain_obj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(GLOB task05_city task05/city/*)
file(GLOB position shared/position/*)
file(GLOB city shared/city/*)

# Task 01
add_executable(task01_task01 task01/task01.cpp)
add_executable(task01_task02 task01/task02.cpp)
add_executable(task01_task03 task01/task03.cpp)


#Task 02
add_executable(task02_task01 task02/task01.cpp)
add_executable(task02_task02 task02/task02.cpp)
add_executable(task02_task03 task02/task03.cpp)

#Task 03

file(GLOB task03_position task03/position/*.cpp task03/position/*.h)

add_executable(task03_task01 task03/task01.cpp)
add_executable(task03_task02 task03/task02.cpp)
add_executable(task03_task03 task03/task03.cpp ${task03_position})
add_executable(task03_task04 task03/task04.cpp ${task03_position})

file(GLOB task04_city task04/city/*.cpp task04/city/*.h)


#Task04
add_executable(task04_task01 task04/task01.cpp ${task04_city} ${position})


#Task05
add_executable(task05_task01 task05/task01.cpp ${task05_city} ${position})
add_executable(task05_task04 task05/task04.cpp ${task05_city} ${position})

#Task06
add_executable(task06_task01 task06/task01.cpp ${city} ${position})

#Task07
add_executable(task07_task01 task07/task01.cpp ${city} ${position})
add_executable(task07_task02 task07/task02.cpp ${city} ${position})


#Task08
file(GLOB task08_city task08/city/*.cpp task08/city/*.h)

add_executable(task08_task01 task08/task01.cpp ${task08_city} ${position})
add_executable(task08_task02 task08/task02.cpp ${task08_city} ${position})