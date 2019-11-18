#include "PositionalServoMotorImpl.h"
#include "Arduino.h"

PositionalServoMotorImpl::PositionalServoMotorImpl(int pin){
  this->pin = pin; 
  this->currentAngle = 0; 
  this->target = 0;
  this->setAngle(this->currentAngle);
} 

void PositionalServoMotorImpl::on(){
  motor.attach(pin);    
}

void PositionalServoMotorImpl::setAngle(int angle){
  this->currentAngle = angle;
  motor.write(this->currentAngle);          
}

int PositionalServoMotorImpl::getCurrentAngle(){
  return this->currentAngle;
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
  if(this->currentAngle > this->target){
    this->currentAngle -= step;
  }
  else{
    this->currentAngle += step;
  }
}

void PositionalServoMotorImpl::alignTarget(){
  this->target = this->currentAngle;
};
