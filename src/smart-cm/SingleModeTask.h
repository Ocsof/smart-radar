#ifndef __SINGLEMODETASK__
#define __SINGLEMODETASK__

#include "Task.h"
#include "Radar.h"

class SingleModeTask: public Task {
  PositionalServoMotor* servo;
  bool resetting;

public:
  SingleModeTask();  
  void init(int period);  
  void tick();
};

#endif
