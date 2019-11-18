#ifndef __RADAR__
#define __RADAR__

#include "Queue.h"
#include "Arduino.h"

#include "Led.h"
#include "ButtonImpl.h"
#include "PotentiometerImpl.h"
#include "SonarImpl.h"
#include "PirImpl.h"
#include "PositionalServoMotorImpl.h"

enum class Command {  MOVE_LEFT = 1, MOVE_RIGHT = 2, MODE_SINGLE = 11, MODE_MANUAL = 12,
                      MODE_AUTO = 13, SPEED_ULTRASLOW = 21, SPEED_SLOW = 22, 
                      SPEED_NORMAL = 23, SPEED_FAST = 24, NO_COMMAND = 0};

class Radar {

public:
  static Radar* getInstance();
  Light* getLed();
  Button* getButtonS();
  Button* getButtonM();
  Button* getButtonA();
  Potentiometer* getPotentiometer();
  Sonar* getSonar();
  Pir* getPir();
  PositionalServoMotor* getServoMotor();
  void enqueueCommand(Command serialCommand);
  Command dequeueCommand();
  

private:
  static Radar* SINGLETON;
  Radar(void);
  Light* led;
  Button* buttonS;
  Button* buttonM;
  Button* buttonA;
  Potentiometer* potentiometer;
  Sonar* sonar;
  Pir* pir;
  PositionalServoMotor* servoMotor;
  Queue<Command>* commandQueue;
};

//Global variable accessible from the Arduino code for facilitating the use of this timer library
extern Radar SmartRadar;

enum class Speed { ULTRASLOW, SLOW, NORMAL, SPEED };
enum class Mode { SINGLE, MANUAL, AUTO };

#endif