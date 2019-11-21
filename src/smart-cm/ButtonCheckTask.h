#ifndef __BUTTONCHECKTASK__
#define __BUTTONCHECKTASK__

#include "Task.h"
#include "Radar.h"

class ButtonCheckTask: public Task {

  Command command;
  Button* button;
  Radar* SmartRadar;

public:

  ButtonCheckTask(Radar* SmartRadar ,Button* button, Command command);  
  void init(int period);  
  void tick();
};

#endif
