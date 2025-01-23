cmake_minimum_required(VERSION 3.13)

# Set the project name
project(genesis_coin)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler flags
if(MSVC)
    # MSVC specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /W3")
else()
    # GCC/Clang specific flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")
endif()

add_executable(genesis_coin
                block.cpp
                main.cpp
                utc_data.cpp)

find_package(OpenSSL REQUIRED)
target_include_directories(genesis_coin PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(genesis_coin PRIVATE OpenSSL::SSL OpenSSL::Crypto)
