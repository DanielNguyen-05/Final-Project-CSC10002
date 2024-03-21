cmake_minimum_required(VERSION 3.1)

project(NameOfProject VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(NameOfProject main.cpp)
target_link_libraries(NameOfProject mylibrary)
install(TARGETS NameOfProject DESTINATION bin)

