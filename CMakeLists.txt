# Standard Required
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Compiling Process info
project(Student-Management-System)
add_executable(Student-Management-System SMS.cpp )
install(TARGETS Student-Management-System RUNTIME DESTINATION bin)
