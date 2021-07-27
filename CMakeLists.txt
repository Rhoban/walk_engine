cmake_minimum_required(VERSION 3.16.3)
project(walk_engine)

if(NOT TARGET pybind11::module)
  set(PYBIND11_PYTHON_VERSION 3.6)
  add_subdirectory(pybind11)
endif()

set (ALL_SOURCES
  src/walk_engine.cpp
  src/py_walk_engine.cpp
)

add_library(walk_engine_lib ${ALL_SOURCES})
target_link_libraries(walk_engine_lib PUBLIC
    robot_model
    rhoban_utils
    eigen
    pthread dl
    stdc++fs
)
target_include_directories(walk_engine_lib PUBLIC include)

pybind11_add_module(walk_engine SHARED src/python.cpp)
target_link_libraries(walk_engine PUBLIC ${PYTHON_LIBRARY} pybind11::module walk_engine_lib)

