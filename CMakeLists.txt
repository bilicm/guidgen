project(guidgen)
cmake_minimum_required(VERSION 3.0)

if (UNIX)
	add_definitions(-DLIBUUID)
endif (UNIX)

if (WIN32)
	add_definitions(-DGUID)
endif (WIN32)

add_library(guidgen guidgen.cpp)
add_executable(example example.cpp)

set_target_properties(guidgen PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(example guidgen uuid)
