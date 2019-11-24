#ifndef __SINGLEMODETASK__
#define __SINGLEMODETASK__

#include "Task.h"
#include "Radar.h"

class SingleModeTask: public Task {
  Radar* SmartRadar;
  PositionalServoMotor* servo;
  bool resetting; /*true = resetting, false = sweeping*/

public:
  SingleModeTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
