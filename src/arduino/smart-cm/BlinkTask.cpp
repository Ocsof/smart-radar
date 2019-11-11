#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin){
  this->pin = pin;   
}

void BlinkTask::init(int period){
  Task::init(period);
  this->led = new Led(pin);  
}

void BlinkTask::tick(){
  if(radar->getLastMeasure() != 0){
    led->switchOn();
  }else{
    led->switchOff();
  }
}
