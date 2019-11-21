#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Radar.h"


class BlinkTask: public Task {
  Led* detectionLed;
  Led* alarmLed;
  Radar* SmartRadar;

public:
  BlinkTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
