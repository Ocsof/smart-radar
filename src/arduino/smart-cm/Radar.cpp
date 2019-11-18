#include "Radar.h"

/****** dare i numeri dei piiiiiiin ***/
#define LED_PIN 5
#define BUTTONS_PIN 6
#define BUTTONM_PIN 7
#define BUTTONA_PIN 8
#define POTENTIOMETER_PIN 9
#define SONAR_TRIG_PIN 10
#define SONAR_ECHO_PIN 11
#define PIR_PIN 2
#define SERVO_MOTOR_PIN 13


Radar *Radar::SINGLETON {};

Radar *Radar::getInstance(void) {
    return SINGLETON;
}

// Default constructor
Radar::Radar(void){
  this->led = new Led(LED_PIN); 
  this->buttonS = new ButtonImpl(BUTTONS_PIN); 
  this->buttonM = new ButtonImpl(BUTTONM_PIN);
  this->buttonA = new ButtonImpl(BUTTONA_PIN);
  this->potentiometer = new PotentiometerImpl(POTENTIOMETER_PIN);
  this->sonar = new SonarImpl(SONAR_TRIG_PIN, SONAR_ECHO_PIN);
  this->pir = new PirImpl(PIR_PIN);
  this->servoMotor = new PositionalServoMotorImpl(SERVO_MOTOR_PIN);
  this->commandQueue = new Queue<Command>();
}


Light* Radar::getLed(){
  return this->led;   
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

void Radar::enqueueCommand(Command serialCommand){
    this->commandQueue->push(serialCommand);
}

Command Radar::dequeueCommand(){
    return this->commandQueue->pop();
}

// Creating an "alias" to the singleton instance of this class so as to easily access it from the Arduino code
Radar SmartRadar = *Radar::getInstance();
