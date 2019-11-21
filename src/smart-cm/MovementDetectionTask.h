#ifndef __MOVEMENTDETECTIONTASK__
#define __MOVEMENTDETECTIONTASK__

#include "Task.h"
#include "Radar.h"

class MovementDetectionTask: public Task {

  Radar* SmartRadar;
  Pir* pir;

public:
  MovementDetectionTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
