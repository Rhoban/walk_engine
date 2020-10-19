#include <iostream>
#include "walk_engine.h"

using rhoban::HumanoidModel;
using rhoban::WalkEngine;

class PyWalkEngine : public WalkEngine
{
public:
  PyWalkEngine(std::string urdfFile);

  std::map<std::string, double> getAngles(double timeSinceLastStep);

protected:
  HumanoidModel* model;
};