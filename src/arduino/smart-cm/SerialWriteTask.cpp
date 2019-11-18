#include "SerialWriteTask.h"

SerialWriteTask::SerialWriteTask(int pin){
  Serial.begin(9600); 
}

void SerialWriteTask::init(int period){
  Task::init(period); 
}

void SerialWriteTask::tick(){
  int lastMeasurement = Radar.getLastMeasurement();
  Serial.print("Current position: ");
  Serial.print(Radar.getServo().getStepValue()*Radar.getServo().getCurrentPosition());
  if(lastMeasurement == 0){
    Serial.print(" ; No objects detected;\n");
  }else{
    Serial.print(" ; Object detected at distance: ");
    Serial.print(lastMeasurement);
    Serial.print(" m;\n");
  }
  if(Radar.isAlarmActive()){
    Serial.print("on\n");
  }else{
    Serial.print("off\n");
  }
  
  }
