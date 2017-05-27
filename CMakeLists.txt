cmake_minimum_required(VERSION 3.7)
project(Elevator__)

set(CMAKE_CXX_STANDARD 14)

# SFML
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/share/SFML/cmake/Modules/")

# Get the SFML components
find_package(SFML COMPONENTS window system graphics audio network REQUIRED)
# Include SFML
include_directories(${SFML_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp Request.cpp Request.h Person.cpp Person.h Floor.cpp Floor.h Direction.h Elevator.cpp Elevator.h ElevatorManager.cpp ElevatorManager.h Building.cpp Building.h conversion.h)
add_executable(Elevator__ ${SOURCE_FILES})

# Link SFML library
target_link_libraries(Elevator__ ${SFML_LIBS})