# set the project name and version
cmake_minimum_required(VERSION 3.16.3)
project(BalancedTrees)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define output dirs
set(CMAKE_BINARY_DIR bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ./lib)

# Compile libraries
include_directories(${CMAKE_SOURCE_DIR}/include/headers)
link_directories(${CMAKE_SOURCE_DIR}/lib)
aux_source_directory(./src SOURCES)
add_library(core SHARED ${SOURCES})

# Compile example files
file( GLOB EXAMPLES ./examples/*.cpp )
foreach( EXAMPLE ${EXAMPLES} )
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable( ${EXAMPLE_NAME} ${EXAMPLE} )
    target_link_libraries(${EXAMPLE_NAME} core)
endforeach()





