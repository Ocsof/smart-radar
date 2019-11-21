#ifndef __POTENTIOMETERREADTASK__
#define __POTENTIOMETERREADTASK__

#include "Task.h"
#include "Radar.h"

class PotentiometerReadTask: public Task {

  Radar* SmartRadar;
  Potentiometer* potentiometer;

public:
  PotentiometerReadTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
