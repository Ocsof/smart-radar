#ifndef __DISTANCEMEASUREMENTTASK__
#define __DISTANCEMEASUREMENTTASK__

#include "Task.h"
#include "Radar.h"

class DistanceMeasurementTask: public Task {

  Sonar* sonar;

public:
  DistanceMeasurementTask(Sonar* sonar);  
  void init(int period);  
  void tick();
};

#endif
