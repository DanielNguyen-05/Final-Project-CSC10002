cmake_minimum_required(VERSION 3.10...3.21)  # Specifies the minimum required version of CMake.

project(project VERSION 1.0)  # Sets the project name and version.

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/SourceCode/*.cpp")  # Specifies that all '.cpp' files in the 'SourceCode' directory should be included in the 'SOURCES' variable.

add_executable(project ${SOURCES})  # Specifies that an executable named 'project' should be created from the source files in 'SOURCES'.

#target_link_libraries(project mylibrary)  # Specifies that 'project' should be linked with 'mylibrary'.

install(TARGETS project DESTINATION bin)  # Specifies that 'project' should be installed to the 'bin' directory.