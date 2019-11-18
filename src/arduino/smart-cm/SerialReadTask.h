#ifndef __SERIALREADTASK__
#define __SERIALREADTASK__


#include "Task.h"
#include "Radar.h"

class SerialReadTask: public Task {

public:
  SerialReadTask();  
  void init(int period);  
  void tick();
};

#endif
