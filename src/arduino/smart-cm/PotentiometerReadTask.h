#ifndef __POTENTIOMETERREADTASK__
#define __POTENTIOMETERREADTASK__

#include "Task.h"
#include "Radar.h"

class PotentiometerReadTask: public Task {
  
  Potentiometer* potentiometer;
  Command selectSpeed() = 0;

public:
  PotentiometerReadTask(Potentiometer* potentiometer);  
  void init(int period);  
  void tick();
};

#endif
