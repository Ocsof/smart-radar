#include "PositionalServoMotorImpl.h"
#include "Arduino.h"

PositionalServoMotorImpl::PositionalServoMotorImpl(int pin, int numOfPositions){
  this->pin = pin; 
  this->currentPosition = 0; 
  this->target = 0;
  this->numOfPositions = numOfPositions,
  this->step = 180 / (this->numOfPositions - 1); // 180 / number of steps
} 

void PositionalServoMotorImpl::on(){
  motor.attach(pin);    
}

int PositionalServoMotorImpl::getCurrentPosition(){
  return this->currentPosition;
}

void PositionalServoMotorImpl::off(){
  motor.detach();    
}

void PositionalServoMotorImpl::incrementTarget(){
  this->target += step;
}

void PositionalServoMotorImpl::decrementTarget(){
  this->target -= step;
}

void PositionalServoMotorImpl::stepForwardTarget(){
  if(this->currentPosition > this->target){
    this->currentPosition -= step;
  }
  else{
    this->currentPosition += step;
  }
}

void PositionalServoMotorImpl::alignTarget(){
  this->target = this->currentPosition;
}

int PositionalServoMotorImpl::getStepValue(){
  return this->step;
};


