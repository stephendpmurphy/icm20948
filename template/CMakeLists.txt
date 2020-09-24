# Set min req version of Cmake
cmake_minimum_required(VERSION 3.10)

# Set project name
project(ICM20948_Example_Main)

# Set our lib include directories
include_directories(../inc)

# Create the executable
add_executable(icm20948 main.c)

# Link against our icm20948 lib
TARGET_LINK_LIBRARIES(icm20948 "${CMAKE_SOURCE_DIR}/../lib/lib_icm20948.a")