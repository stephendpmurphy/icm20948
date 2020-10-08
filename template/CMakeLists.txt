# Set min req version of Cmake
cmake_minimum_required(VERSION 3.10)

# Set project name
project(ICM20948_Example_Main)

# Set our lib include directories
include_directories(../inc)

# Create the C Executable
add_executable(icm20948_c main.c)
# Link against our icm20948 lib
TARGET_LINK_LIBRARIES(icm20948_c "${CMAKE_SOURCE_DIR}/../lib/lib_icm20948.a")

# Create the C++ Executable
add_executable(icm20948_cpp main.cpp)
# Link against our icm20948 lib
TARGET_LINK_LIBRARIES(icm20948_cpp "${CMAKE_SOURCE_DIR}/../lib/lib_icm20948.a")