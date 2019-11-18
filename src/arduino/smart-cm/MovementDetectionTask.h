#ifndef __MOVEMENTDETECTIONTASK__
#define __MOVEMENTDETECTIONTASK__

#include "Task.h"
#include "Radar.h"

class MovementDetectionTask: public Task {

  PIR* pir;

public:
  MovementDetectionTask(PIR* pir);  
  void init(int period);  
  void tick();
};

#endif
