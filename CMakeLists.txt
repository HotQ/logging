cmake_minimum_required (VERSION 2.8)

project (logging)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-Wall")

aux_source_directory(. DIR_SRCS)
include_directories(.)

add_executable(logging ${DIR_SRCS})

