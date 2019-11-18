#ifndef __MANUALMODETASK__
#define __MANUALMODETASK__

#include "Task.h"
#include "Radar.h"

class ManualModeTask: public Task {


public:
  ManualModeTask();  
  void init(int period);  
  void tick();
};

#endif
