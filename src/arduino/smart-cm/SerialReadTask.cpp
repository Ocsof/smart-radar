#include "SerialReadTask.h"

SerialReadTask::SerialReadTask(int pin){
  Serial.begin(9600); 
}

void SerialReadTask::init(int period){
  Task::init(period); 
}

void SerialReadTask::tick(){
  if (Serial.available() > 0) {
    Radar.addCommand(static_cast<Command>(Integer.parseInt(Serial.read()));
  }
}
