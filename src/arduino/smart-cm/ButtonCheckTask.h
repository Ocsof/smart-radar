#ifndef __BUTTONCHECKTASK__
#define __BUTTONCHECKTASK__

#include "Task.h"
#include "Radar.h"

class ButtonCheckTask: public Task {

private:
  int pin;
  Mode mode;
  Button* button;

public:

  ButtonCheckTask(int pin, Mode mode);  
  void init(int period);  
  void tick();
};

#endif
