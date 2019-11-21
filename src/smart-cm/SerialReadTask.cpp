#include "SerialReadTask.h"

SerialReadTask::SerialReadTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
}

void SerialReadTask::init(int period){
  Task::init(period); 
}

void SerialReadTask::tick(){
  if (Serial.available() > 0) {
    SmartRadar->enqueueCommand(static_cast<Command>(Serial.read()));
  }
}
