cmake_minimum_required(VERSION 3.13)

# Set the project name
project(chud_coin)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler flags
if(MSVC)
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /W3 /WX")
else()
    # GCC/Clang specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror")
endif()

# Add the executable
add_executable(chud_coin
                src/block.cpp
                src/main.cpp
                src/utc_data.cpp)