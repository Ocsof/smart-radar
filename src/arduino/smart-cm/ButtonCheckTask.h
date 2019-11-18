#ifndef __BUTTONCHECKTASK__
#define __BUTTONCHECKTASK__

#include "Task.h"
#include "Radar.h"

class ButtonCheckTask: public Task {

  Command command
  Button* button;

public:

  ButtonCheckTask(Button* button, Command command);  
  void init(int period);  
  void tick();
};

#endif
