#include "BlinkTask.h"

BlinkTask::BlinkTask(Led* led){
  this->led = led;   
}


void BlinkTask::init(int period){
  Task::init(period); 
}

void BlinkTask::tick(){
  if(SmartRadar.getMode() == Mode::SINGLE){
    if(SmartRadar.getLastMeasurement() != 0){
      led->switchOn();
    }else{
      led->switchOff();
    }
  }
  if(SmartRadar.getMode() == Mode::MANUAL){
      led->switchOff();
  }
  if(SmartRadar.getMode() == Mode::AUTO){
    if(SmartRadar.isAlarmActive()){
      if(led->isOn()){
        led->switchOff();
      }else{
        led->switchOn();
      }
    }else{
      led->switchOff();
    }
  }
}
