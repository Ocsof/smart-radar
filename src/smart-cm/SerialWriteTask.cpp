#include "SerialWriteTask.h"

SerialWriteTask::SerialWriteTask(){

}

void SerialWriteTask::init(int period){
  Task::init(period); 
}

void SerialWriteTask::tick(){
  this->init(static_cast<int>(SmartRadar.getSpeed()));
  int lastMeasurement = SmartRadar.getLastMeasurement();
  Serial.print("Current position: ");
  Serial.print(SmartRadar.getServoMotor()->getStepValue() * SmartRadar.getServoMotor()->getCurrentPosition());
  if(lastMeasurement == 0){
    Serial.print(" ; No objects detected;\n");
  }else{
    Serial.print(" ; Object detected at distance: ");
    Serial.print(lastMeasurement);
    Serial.print(" m;\n");
  }
  if(SmartRadar.isAlarmActive()){
    Serial.print("on\n");
  }else{
    Serial.print("off\n");
  }
  
  }
