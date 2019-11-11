#ifndef __MOVEMENTDETECTIONTASK__
#define __MOVEMENTDETECTIONTASK__

#include "Task.h"
#include "Radar.h"

class MovementDetectionTask: public Task {

private:
  int pin;
  PIR* pir;

public:
  MovementDetectionTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
