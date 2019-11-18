#ifndef __POSITIONALSERVOMOTOR__
#define __POSITIONALSERVOMOTOR__


class PositionalServoMotor{

public:
  virtual void on() = 0;
  virtual int getCurrentPosition() = 0;  // da 0 a 15
  virtual void off() = 0;
  virtual void incrementTarget() = 0;
  virtual void decrementTarget() = 0;
  virtual void stepForwardTarget() = 0;
  virtual void alignTarget() = 0;
  virtual int getNumOfPositions() = 0;
  virtual int getStepValue() = 0;
};

#endif