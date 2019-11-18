#ifndef __POSITIONALSERVOMOTORIMPL__
#define __POSITIONALSERVOMOTORIMPL__

#include "PositionalServoMotor.h"
#include <arduino.h>
#include "ServoTimer2.h"

class PositionalServoMotorImpl: public PositionalServoMotor {

public:
  PositionalServoMotorImpl(int pin);

  void on();
  int getCurrentAngle();
  void off();
  void incrementTarget();
  void decrementTarget();
  void stepForwardTarget();
  void alignTarget();
    
private:
  int pin; 
  int currentAngle;
  int target;
  const int step = 12;
  ServoTimer2 motor;
  void setAngle(int angle);
};

#endif
