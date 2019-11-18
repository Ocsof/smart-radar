#ifndef __AUTOMODETASK__
#define __AUTOMODETASK__

#define D_NEAR 0.2
#define D_FAR 0.4

#include "Task.h"
#include "Radar.h"

class AutoModeTask: public Task {
  bool direction;
  bool* nearObjects;

public:
  AutoModeTask();  
  void init(int period);  
  void tick();
};

#endif
