# Standard Required
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Compiling Process info
project(Student_Management_System)
add_executable(Student_Management_System SMS.cpp )
install(TARGETS Student_Management_System RUNTIME DESTINATION bin)
