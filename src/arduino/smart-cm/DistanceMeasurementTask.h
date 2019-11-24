#ifndef __DISTANCEMEASUREMENTTASK__
#define __DISTANCEMEASUREMENTTASK__

#include "Task.h"
#include "Radar.h"

class DistanceMeasurementTask: public Task {

  Radar* SmartRadar;
  Sonar* sonar;

public:
  DistanceMeasurementTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
