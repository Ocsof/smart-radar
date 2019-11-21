#ifndef __AUTOMODETASK__
#define __AUTOMODETASK__

#define D_NEAR 20
#define D_FAR 40

#include "Task.h"
#include "Radar.h"

class AutoModeTask: public Task {
  PositionalServoMotor* servo;
  Radar* SmartRadar;
  bool direction;
  bool* nearObjects;

public:
  AutoModeTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
