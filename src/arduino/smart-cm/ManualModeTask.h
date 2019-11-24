#ifndef __MANUALMODETASK__
#define __MANUALMODETASK__

#include "Task.h"
#include "Radar.h"

class ManualModeTask: public Task {
  Radar* SmartRadar;
  PositionalServoMotor* servo;

public:
  ManualModeTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
