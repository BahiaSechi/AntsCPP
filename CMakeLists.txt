cmake_minimum_required(VERSION 3.17)
project(ants)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS Wpedantic Wall)

if (UNIX)
    set (SFML_DIR "${PROJECT_SOURCE_DIR}/lib/SFML-2.5.1_linux/lib/cmake/SFML")
    SET(CMAKE_CXX_FLAGS -pthread)
endif (UNIX)
if (WIN32)
    set (SFML_DIR "${PROJECT_SOURCE_DIR}/lib/SFML-2.5.1_windows/lib/cmake/SFML")
endif (WIN32)

include_directories(include lib/SFML-2.5.1_linux/include tests/include)

find_package(SFML COMPONENTS graphics window system)

file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.cpp)
file(GLOB_RECURSE test_files tests/*.cpp)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(ants ${header_files} ${source_files})
add_executable(ants_test ${test_files} ${header_files} ${source_files})

target_link_libraries(ants sfml-window sfml-graphics)

target_compile_definitions(ants_test PUBLIC -DANTS_TEST)

set_target_properties(ants PROPERTIES LINKER_PROPERTIES CXX)