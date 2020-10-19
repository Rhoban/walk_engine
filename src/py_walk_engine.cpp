#include <iostream>
#include "py_walk_engine.h"

PyWalkEngine::PyWalkEngine(std::string urdfFile) : WalkEngine()
{
  model = new HumanoidModel(urdfFile);
  initByModel(*model);
  reset();
}

std::map<std::string, double> PyWalkEngine::getAngles(double timeSinceLastStep)
{
  return computeAngles(*model, timeSinceLastStep);
}
