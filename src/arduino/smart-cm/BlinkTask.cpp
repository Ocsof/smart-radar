#include "BlinkTask.h"

BlinkTask::BlinkTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->detectionLed = this->SmartRadar->getDetectionLed(); 
  this->alarmLed = this->SmartRadar->getAlarmLed();  
}


void BlinkTask::init(int period){
  Task::init(period); 
}

void BlinkTask::tick(){
  /*Detection led is active only in SINGLE mode*/
  if(SmartRadar->getMode() == Mode::SINGLE){
    if(SmartRadar->getLastMeasurement() != 0){
      this->detectionLed->switchOn();
    }else{
      this->detectionLed->switchOff();
    }
  }else{
    detectionLed->switchOff();
  }

  if(SmartRadar->isAlarmActive()){
    if(alarmLed->isOn()){
      alarmLed->switchOff();
    }else{
      alarmLed->switchOn();
    }
  }else{
    alarmLed->switchOff();
  }
}

