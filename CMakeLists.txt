cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Durak LANGUAGES CXX)

add_compile_options("-Wall" "-Wextra" "-Wpedantic")

# Require C++14
set(CMAKE_CXX_STANDARD           14)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS         OFF)

# Libraries
add_subdirectory(libutils)
add_subdirectory(libcards)

# Tests
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
enable_testing()
add_subdirectory(tests)

# Other targets
add_custom_target(graph
    "${CMAKE_COMMAND}" "--graphviz=${CMAKE_PROJECT_NAME}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
