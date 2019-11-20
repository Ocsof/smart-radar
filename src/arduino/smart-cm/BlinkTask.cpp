#include "BlinkTask.h"

BlinkTask::BlinkTask(){
  this->alarmLed = SmartRadar.getAlarmLed();   
  this->detectionLed = SmartRadar.getDetectionLed();
}


void BlinkTask::init(int period){
  Task::init(period); 
}

void BlinkTask::tick(){
  if(SmartRadar.getMode() == Mode::SINGLE){
    if(SmartRadar.getLastMeasurement() != 0){
      detectionLed->switchOn();
    }else{
      detectionLed->switchOff();
    }
  }
  if(SmartRadar.getMode() == Mode::MANUAL){
      detectionLed->switchOff();
      alarmLed->switchOff();
  }
  if(SmartRadar.getMode() == Mode::AUTO){
    if(SmartRadar.isAlarmActive()){
      if(alarmLed->isOn()){
        alarmLed->switchOff();
      }else{
        alarmLed->switchOn();
      }
    }else{
      alarmLed->switchOff();
    }
  }
}
