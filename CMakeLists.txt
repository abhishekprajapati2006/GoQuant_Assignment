cmake_minimum_required(VERSION 3.10)

# Set the project name
project(GoQuantAssessment)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(GoQuantAssessment ${SOURCES})

# Link any required libraries (if applicable)
# target_link_libraries(GoQuantAssessment <library_name>)