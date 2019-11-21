#ifndef __AUTOMODETASK__
#define __AUTOMODETASK__

#define D_NEAR 20
#define D_FAR 40

#include "Task.h"
#include "Radar.h"

class AutoModeTask: public Task {
  PositionalServoMotor* servo;
  bool direction;
  bool* nearObjects;

public:
  AutoModeTask();  
  void init(int period);  
  void tick();
};

#endif