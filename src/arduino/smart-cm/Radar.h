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
enum class Speed { ULTRASLOW = 600, SLOW = 450, NORMAL = 300, FAST = 150 };
enum class Mode { SINGLE = 10, MANUAL = 20, AUTO = 30 };

class Radar {

public:
  //static Radar* getInstance();
  Led* getDetectionLed();
  Led* getAlarmLed();
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
  Radar();


  

private:
  //static Radar* SINGLETON;
  
  Led* detectionLed;
  Led* alarmLed;
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
//extern Radar SmartRadar;



#endif
