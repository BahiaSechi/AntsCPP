cmake_minimum_required(VERSION 3.17)
project(ants)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/ lib/SFML-2.5.1/include tests/include)

file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE test_files tests/*.cpp)

add_executable(ants ${source_files})
add_executable(ants_test ${test_files} ${source_files})

target_compile_definitions(ants_test PUBLIC -DANTS_TEST)

set_target_properties(ants PROPERTIES LINKER_PROPERTIES CXX)