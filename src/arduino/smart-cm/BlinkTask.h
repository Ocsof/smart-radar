#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Radar.h"

class BlinkTask: public Task {

private:
  int pin;
  Led* led;

public:
  BlinkTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
