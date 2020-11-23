cmake_minimum_required(VERSION 3.17)
project(ants)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/*)

add_executable(ants src/*)

set_target_properties(ants PROPERTIES LINKER_PROPERTIES CXX)