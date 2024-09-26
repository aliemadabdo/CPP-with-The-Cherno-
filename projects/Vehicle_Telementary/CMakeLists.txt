# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(vehicle_telementary)

# Set the C++ standard to C++11 (or 14/17/20 as needed)
set(CMAKE_CXX_STANDARD 11)

# Specify the executable target and its source files
add_executable(vehicle_telementary
    src/main.cpp
    src/classes/sensors/speed.cpp
    src/classes/sensors/radar.cpp
    src/classes/sensors/engineTemp.cpp
    src/classes/sensors/batteryTemp.cpp
    src/classes/sensors/batteryLevel.cpp
    src/classes/sensor.cpp
    src/classes/logger.cpp
    src/classes/car.cpp
)

# Include directories if you have any header files located elsewhere
# include_directories(classes)
