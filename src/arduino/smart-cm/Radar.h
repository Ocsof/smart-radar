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
enum class Speed { ULTRASLOW = 520, SLOW = 390, NORMAL = 260, FAST = 130 };
enum class Mode { SINGLE, MANUAL, AUTO };

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
  Mode getMode();
  Speed getSpeed();
  void enqueueCommand(Command serialCommand);
  Command dequeueCommand();
  void setAlarm(bool alarm);
  bool isAlarmActive();
  void addMeasurement(int currentMeasurement);
  int getLastMeasurement();


  

private:
  static Radar* SINGLETON;
  Radar();
  Light* led;
  Button* buttonS;
  Button* buttonM;
  Button* buttonA;
  Potentiometer* potentiometer;
  Sonar* sonar;
  Pir* pir;
  PositionalServoMotor* servoMotor;
  Mode currentMode;
  Speed currentSpeed;
  Queue<Command>* commandQueue;
  bool isAlarmed;
  int lastMeasurement;
  const int numOfPositions = 16;  //numero di posizioni che puo' assumere il servo!!
};

//Global variable accessible from the Arduino code for facilitating the use of this timer library
extern Radar SmartRadar;



#endif
