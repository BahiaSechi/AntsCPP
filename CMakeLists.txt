cmake_minimum_required(VERSION 3.17)
project(ants)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/ lib/SFML-2.5.1/include)

file(GLOB_RECURSE source_files src/*.cpp)

add_executable(ants ${source_files})

set_target_properties(ants PROPERTIES LINKER_PROPERTIES CXX)