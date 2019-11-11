#include "ButtonCheckTask.h"

PotentiometerReadTask::PotentiometerReadTask(int pin){
  this->pin = pin;   
}

void PotentiometerReadTask::init(int period){
  Task::init(period);
  pot = new Potentiometer(pin);  
}

void PotentiometerReadTask::tick(){
  radar->setSpeed(this->selectSpeed);
}

Speed selectSpeed(){
  switch(this->pot->getValue()){
    case 0 ... 255:
      return ULTRASLOW;
    case 256 ... 511:
      return SLOW;
    case 512 ... 767:
      return NORMAL;
    case 768 ... 1023:
      return FAST;
  }
}
