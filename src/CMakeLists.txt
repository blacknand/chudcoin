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

# find_package(OpenSSL REQUIRED OPENSSL_CRYPTO_LIBRARY OPENSSL_SSL_LIBRARY)
# target_link_libraries(chudcoin OpenSSL::SSL OpenSSL::Crypto)

add_executable(chud_coin
                block.cpp
                main.cpp
                utc_data.cpp)

find_package(OpenSSL REQUIRED)
target_include_directories(chud_coin PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(chud_coin PRIVATE OpenSSL::SSL OpenSSL::Crypto)
