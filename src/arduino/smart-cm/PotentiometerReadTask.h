#ifndef __POTENTIOMETERREADTASK__
#define __POTENTIOMETERREADTASK__

#include "Task.h"
#include "Radar.h"

class PotentiometerReadTask: public Task {
private:
  int pin;
  Potentiometer* pot;
  Speed selectSpeed();

public:
  PotentiometerReadTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
