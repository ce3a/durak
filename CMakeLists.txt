cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Durak LANGUAGES CXX)

# Require C++14
set(CMAKE_CXX_STANDARD           14)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS         OFF)

# Libraries
add_subdirectory(libutils)
add_subdirectory(libcards)

# Executables
add_subdirectory(src)

# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab
