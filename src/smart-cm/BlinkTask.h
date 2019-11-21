#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Radar.h"


class BlinkTask: public Task {
  Led* led;

public:
  BlinkTask(Led* led);  
  void init(int period);  
  void tick();
};

#endif
