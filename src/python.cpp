#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "py_walk_engine.h"

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(walk_engine, m)
{
  py::class_<PyWalkEngine>(m, "WalkEngine")
      .def(py::init<std::string>())
      .def("reset", &PyWalkEngine::newStep)
      .def("newStep", &PyWalkEngine::newStep)
      .def("getAngles", &PyWalkEngine::getAngles)
      .def("replan", &PyWalkEngine::replan)

      // Engine parameters
      .def_readwrite("trunkXOffset", &PyWalkEngine::trunkXOffset)
      .def_readwrite("trunkZOffset", &PyWalkEngine::trunkZOffset)
      .def_readwrite("footYOffset", &PyWalkEngine::footYOffset)
      .def_readwrite("riseGain", &PyWalkEngine::riseGain)
      .def_readwrite("riseDuration", &PyWalkEngine::riseDuration)
      .def_readwrite("frequency", &PyWalkEngine::frequency)
      .def_readwrite("swingGain", &PyWalkEngine::swingGain)
      .def_readwrite("swingPhase", &PyWalkEngine::swingPhase)
      .def_readwrite("trunkHeight", &PyWalkEngine::trunkHeight)
      .def_readwrite("footDistance", &PyWalkEngine::footDistance)
      .def_readwrite("footYOffsetPerStepSizeY", &PyWalkEngine::footYOffsetPerStepSizeY)
      .def_readwrite("trunkPitch", &PyWalkEngine::trunkPitch)
      .def_readwrite("stepDuration", &PyWalkEngine::stepDuration)

      // Walk control
      .def_readwrite("stepSizeX", &PyWalkEngine::stepSizeX)
      .def_readwrite("stepSizeY", &PyWalkEngine::stepSizeY)
      .def_readwrite("stepSizeYaw", &PyWalkEngine::stepSizeYaw)

      ;
}