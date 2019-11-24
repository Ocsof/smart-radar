#ifndef __SERIALREADTASK__
#define __SERIALREADTASK__


#include "Task.h"
#include "Radar.h"

class SerialReadTask: public Task {

Radar* SmartRadar;

public:
  SerialReadTask(Radar* SmartRadar);  
  void init(int period);  
  void tick();
};

#endif
