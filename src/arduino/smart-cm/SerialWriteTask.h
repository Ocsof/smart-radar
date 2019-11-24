#ifndef __SERIALWRITETASK__
#define __SERIALWRITETASK__

#include "Task.h"
#include "Radar.h"


class SerialWriteTask: public Task {

Radar* SmartRadar;

public:
  SerialWriteTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
