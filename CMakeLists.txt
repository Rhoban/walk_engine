cmake_minimum_required(VERSION 2.8)
project(walk_engine)

set(PYBIND11_PYTHON_VERSION 3.6)
add_subdirectory(pybind11)

find_package(catkin REQUIRED COMPONENTS
    robot_model
    rhoban_utils
    eigen
  )

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS robot_model rhoban_utils eigen
  )

#Enable C++17
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#Enable real warnings
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wpedantic")

#Enable Weird option linker
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -fPIC")

#Included internal Directories
include_directories (include ${catkin_INCLUDE_DIRS})

set (LINKED_LIBRARIES
    pthread dl
    stdc++fs
    ${catkin_LIBRARIES}
)

message(${LINKED_LIBRARIES})


set (ALL_SOURCES
  src/walk_engine.cpp
  src/py_walk_engine.cpp
)

add_library(walk_engine_lib ${ALL_SOURCES})
target_link_libraries(walk_engine_lib PUBLIC ${LINKED_LIBRARIES})

pybind11_add_module(walk_engine SHARED src/python.cpp)
target_link_libraries(walk_engine PUBLIC ${PYTHON_LIBRARY} pybind11::module walk_engine_lib)

