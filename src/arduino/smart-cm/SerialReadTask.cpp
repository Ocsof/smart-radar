#include "SerialReadTask.h"

SerialReadTask::SerialReadTask(){
  
}

void SerialReadTask::init(int period){
  Task::init(period); 
}

void SerialReadTask::tick(){
  if (Serial.available() > 0) {
    SmartRadar.enqueueCommand(static_cast<Command>(Serial.read()));
  }
}
