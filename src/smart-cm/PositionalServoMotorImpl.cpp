#include "PositionalServoMotorImpl.h"
#include "Arduino.h"

PositionalServoMotorImpl::PositionalServoMotorImpl(int pin, int numOfPositions){
  this->pin = pin; 
  this->currentPosition = 0; 
  this->motor.write(this->convertPosition(0));
  this->target = 0;
  this->numOfPositions = numOfPositions,
  this->step = 180 / (this->numOfPositions - 1); // 180 / number of steps
  this->on();
} 

void PositionalServoMotorImpl::on(){
  motor.attach(pin);    
}

int PositionalServoMotorImpl::getCurrentPosition(){
  return this->currentPosition / step;
}

void PositionalServoMotorImpl::off(){
  motor.detach();    
}

void PositionalServoMotorImpl::incrementTarget(){
  if(this->target <= 180-step){
     this->target += step;
  }
}

void PositionalServoMotorImpl::decrementTarget(){
  if(this->currentPosition >= step) {
     this->target -= step;
  }
}

void PositionalServoMotorImpl::stepForwardTarget(){
  if(this->currentPosition == this->target){
    return;
  }
  if(this->currentPosition > this->target){
    this->currentPosition -= step;
  }
  else{
    this->currentPosition += step;
  }
  this->motor.write(this->convertPosition(this->currentPosition));
}

void PositionalServoMotorImpl::alignTarget(){
  this->target = this->currentPosition;
}

int PositionalServoMotorImpl::getNumOfPositions(){
  return this->numOfPositions;
}

int PositionalServoMotorImpl::getStepValue(){
  return this->step;
}

int PositionalServoMotorImpl::convertPosition(int position){
  return position*10 + 544;
};
