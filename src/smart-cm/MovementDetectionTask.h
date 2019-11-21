#ifndef __MOVEMENTDETECTIONTASK__
#define __MOVEMENTDETECTIONTASK__

#include "Task.h"
#include "Radar.h"

class MovementDetectionTask: public Task {

  Pir* pir;

public:
  MovementDetectionTask(Pir* pir);  
  void init(int period);  
  void tick();
};

#endif
