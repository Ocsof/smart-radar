#ifndef __POSITIONALSERVOMOTORIMPL__
#define __POSITIONALSERVOMOTORIMPL__

#include "PositionalServoMotor.h"
#include <arduino.h>
#include "ServoTimer2.h"

class PositionalServoMotorImpl: public PositionalServoMotor {

public:
  PositionalServoMotorImpl(int pin, int numOfPositions);
  void on();
  int getCurrentPosition();
  void off();
  void incrementTarget();
  void decrementTarget();
  void stepForwardTarget();
  void alignTarget();
  int getNumOfPositions();
  int getStepValue();

    
private:
  int pin; 
  int currentPosition;
  int target;
  int step;
  int numOfPositions;
  ServoTimer2 motor;
};

#endif
