#include "BlinkTask.h"

BlinkTask::BlinkTask(Led* led){
  this->led = led;   
}


void BlinkTask::init(int period){
  Task::init(period); 
}

void BlinkTask::tick(){
  if(Radar.getMode() == Mode::SINGLE){
    if(radar->getLastMeasure() != 0){
      led->switchOn();
    }else{
      led->switchOff();
    }
  }
  if(Radar.getMode() == Mode::MANUAL){
      led->switchOff();
  }
  if(Radar.getMode() == Mode::AUTO){
    if(Radar.isAlarmActive()){
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
