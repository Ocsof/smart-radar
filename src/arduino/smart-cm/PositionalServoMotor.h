#ifndef __POSITIONALSERVOMOTOR__
#define __POSITIONALSERVOMOTOR__


class PositionalServoMotor{

public:
  virtual void on() = 0;
  virtual int getCurrentAngle() = 0;
  virtual void off() = 0;
  virtual void incrementTarget() = 0;
  virtual void decrementTarget() = 0;
  virtual void stepForwardTarget() = 0;
  virtual void alignTarget() = 0;
};

#endif