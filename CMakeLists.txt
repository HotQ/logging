cmake_minimum_required (VERSION 2.8)

project (logginglib)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-Wall")

aux_source_directory(./source DIR_SRCS)
include_directories(./include)

SET(LIBRARY_OUTPUT_PATH ./shared)
ADD_LIBRARY(logging STATIC ${DIR_SRCS})

