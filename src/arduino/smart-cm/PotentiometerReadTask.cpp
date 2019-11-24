#include "PotentiometerReadTask.h"

PotentiometerReadTask::PotentiometerReadTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->potentiometer = SmartRadar->getPotentiometer(); 
  this->lastCommand = Command::SPEED_FAST;  
}

void PotentiometerReadTask::init(int period){
  Task::init(period);
}

void PotentiometerReadTask::tick(){
  Command command;
  switch(this->potentiometer->getValue()){
    case 0 ... 255:
      command = Command::SPEED_ULTRASLOW;
      break;
    case 256 ... 511:
      command = Command::SPEED_SLOW;
      break;
    case 512 ... 767:
      command = Command::SPEED_NORMAL;
      break;
    case 768 ... 1023:
      command = Command::SPEED_FAST;
  }
  if(command != this->lastCommand){
    SmartRadar->enqueueCommand(command);
    this->lastCommand = command;
  }
}
