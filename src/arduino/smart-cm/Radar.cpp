#include "Radar.h"

/****** dare i numeri dei piiiiiiin ***/
#define DETECTION_LED_PIN 6
#define ALARM_LED_PIN 5
#define BUTTONS_PIN 2
#define BUTTONM_PIN 3
#define BUTTONA_PIN 4
#define POTENTIOMETER_PIN 15
#define SONAR_TRIG_PIN 10 //da metter giusto
#define SONAR_ECHO_PIN 11 //da metter giusto
#define PIR_PIN 12 //da metter giusto
#define SERVO_MOTOR_PIN 13 //da metter giusto


Radar *Radar::SINGLETON = 0;

Radar *Radar::getInstance(void) {
    if(SINGLETON == 0){
      SINGLETON = new Radar();
    }
    return SINGLETON;
}

// Default constructor
Radar::Radar(){
  this->detectionLed = new Led(DETECTION_LED_PIN); 
  this->alarmLed = new Led(ALARM_LED_PIN);
  this->buttonS = new ButtonImpl(BUTTONS_PIN); 
  this->buttonM = new ButtonImpl(BUTTONM_PIN);
  this->buttonA = new ButtonImpl(BUTTONA_PIN);
  this->potentiometer = new PotentiometerImpl(POTENTIOMETER_PIN);
//  this->sonar = new SonarImpl(SONAR_TRIG_PIN, SONAR_ECHO_PIN);
//  this->pir = new PirImpl(PIR_PIN);
//  this->servoMotor = new PositionalServoMotorImpl(SERVO_MOTOR_PIN, this->numOfPositions);
//  this->commandQueue = new Queue<Command>();
//  this->lastMeasurement = 0;
//  this->currentMode = Mode::MANUAL;
//  this->currentSpeed = Speed::FAST;
}


Led* Radar::getDetectionLed(){
  return this->detectionLed;   
}

Led* Radar::getAlarmLed(){
  return this->alarmLed;   
}

Button* Radar::getButtonS(){
    return this->buttonA;
}

Button* Radar::getButtonM(){
    return this->buttonM;
}

Button* Radar::getButtonA(){
    return this->buttonA;
}

Potentiometer* Radar::getPotentiometer(){
    return this->potentiometer;
}

Sonar* Radar::getSonar(){
    return this->sonar;
}

Pir* Radar::getPir(){
    return this->pir;
}

PositionalServoMotor* Radar::getServoMotor(){
    return this->servoMotor;
}

Mode Radar::getMode(){
    return this->currentMode;
}

Speed Radar::getSpeed(){
    return this->currentSpeed;
}

void Radar::enqueueCommand(Command serialCommand){
    switch(serialCommand){
      case Command::SPEED_ULTRASLOW:  
            this->currentSpeed = Speed::ULTRASLOW; 
            break;
      case Command::SPEED_SLOW:       
            this->currentSpeed = Speed::SLOW; 
            break;
      case Command::SPEED_NORMAL:     
            this->currentSpeed = Speed::NORMAL; 
            break;
      case Command::SPEED_FAST:       
            this->currentSpeed = Speed::FAST; 
            break;
      case Command::MODE_MANUAL:      
            this->currentMode = Mode::MANUAL; 
            break;
      case Command::MODE_SINGLE:      
            this->currentMode = Mode::SINGLE; 
            break;
      case Command::MODE_AUTO:        
            this->currentMode = Mode::AUTO; 
            break;
      default:  
            this->commandQueue->put(serialCommand);
    } 
}

Command Radar::dequeueCommand(){
    if(this->commandQueue->empty()) {
        return Command::NO_COMMAND;
    }
    return this->commandQueue->get();
}

void Radar::setAlarm(bool alarm){
    this->isAlarmed = alarm; 
}

bool Radar::isAlarmActive(){
    return this->isAlarmed;
}

void Radar::addMeasurement(int currentMeasurement){
    this->lastMeasurement = currentMeasurement;
}

int Radar::getLastMeasurement(){
    return this->lastMeasurement;
}

// Creating an "alias" to the singleton instance of this class so as to easily access it from the Arduino code
Radar SmartRadar = *Radar::getInstance();
