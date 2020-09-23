# Set min req version of Cmake
cmake_minimum_required(VERSION 3.10)

# Set project name
project(ICM20948_Driver_Lib)

# Set our lib include directories
include_directories(src inc)

# Set the lib output folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)

# Create or our static library
ADD_LIBRARY( _icm20948 STATIC src/icm20948.c src/icm20948.h )
