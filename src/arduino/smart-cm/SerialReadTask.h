#ifndef __SERIALREADTASK__
#define __SERIALREADTASK__

#define MOVE_LEFT 1
#define MOVE_RIGHT 2
#define MODE_SINGLE 11
#define MODE_MANUAL 12
#define MODE_AUTO 13
#define SPEED_ULTRASLOW 21
#define SPEED_SLOW 22
#define SPEED_NORMAL 23
#define SPEED_FAST 24


#include "Task.h"
#include "Radar.h"

class SerialReadTask: public Task {

int data;

public:
  SerialReadTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
