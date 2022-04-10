cmake_minimum_required(VERSION 3.10)

# Set the project name (and version?)
project(NetworkingSystem)

#find_package(OpenSSL REQUIRED)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Changes the binary, static lib, and libraries default paths of the CMake build, respectively
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)

INCLUDE_DIRECTORIES (include)

add_executable( test_main main.cpp )
#target_link_libraries( test_main PUBLIC logging OpenSSL::SSL)