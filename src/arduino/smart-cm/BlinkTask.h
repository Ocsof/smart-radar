#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Radar.h"


class BlinkTask: public Task {
  Led* alarmLed;
  Led* detectionLed;

public:
  BlinkTask();  
  void init(int period);  
  void tick();
};

#endif
