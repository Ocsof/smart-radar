#ifndef __BUTTONCHECKTASK__
#define __BUTTONCHECKTASK__

#include "Task.h"
#include "Led.h"

class ButtonCheckTask: public Task {

  int pin;
  Button* button;

public:

  ButtonCheckTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
