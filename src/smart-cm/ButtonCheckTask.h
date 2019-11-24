#ifndef __BUTTONCHECKTASK__
#define __BUTTONCHECKTASK__

#include "Task.h"
#include "Radar.h"

/*This task sends the given command to the Radar when button is pressed. Small period is suggested to never miss a pression. 
  We verified that with our buttons any period < 90ms never results in missing pression events.*/
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
