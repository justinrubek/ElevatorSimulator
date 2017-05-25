cmake_minimum_required(VERSION 3.7)
project(Elevator__)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Request.cpp Request.h Person.cpp Person.h Floor.cpp Floor.h Direction.h Elevator.cpp Elevator.h ElevatorManager.cpp ElevatorManager.h Building.cpp Building.h conversion.h Requests.cpp Requests.h)
add_executable(Elevator__ ${SOURCE_FILES})