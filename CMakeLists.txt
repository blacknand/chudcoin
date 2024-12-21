cmake_minimum_required(VERSION 3.13)

# Set the project name
project(chud_coin)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable
add_executable(chud_coin
                src/block.cpp
                src/main.cpp)