# Standard Required
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Compiling Process info
project(CodeAlpha_to_do_list)
add_executable(CodeAlpha_to_do_list CodeAlpha_to_do_list.cpp )
install(TARGETS CodeAlpha_to_do_list RUNTIME DESTINATION bin)
