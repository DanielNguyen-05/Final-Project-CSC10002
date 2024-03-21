cmake_minimum_required(VERSION 3.1)  # Specifies the minimum required version of CMake.

project(project VERSION 1.0)  # Sets the project name and version.

set(CMAKE_CXX_STANDARD 11)  # Sets the C++ standard to C++11.
set(CMAKE_CXX_STANDARD_REQUIRED True)  # Makes the above setting mandatory.

add_executable(project ${PROJECT_SOURCE_DIR}/SourceCode/main.cpp)  # Specifies that an executable named 'NameOfProject' should be created from 'main.cpp'.

#target_link_libraries(NameOfProject mylibrary)  # Specifies that 'NameOfProject' should be linked with 'mylibrary'.

install(TARGETS project DESTINATION bin)  # Specifies that 'NameOfProject' should be installed to the 'bin' directory.