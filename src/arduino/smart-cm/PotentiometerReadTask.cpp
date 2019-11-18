#include "PotentiometerReadTask.h"

PotentiometerReadTask::PotentiometerReadTask(Potentiometer* potentiometer){
  this->potentiometer = potentiometer;   
}

void PotentiometerReadTask::init(int period){
  Task::init(period);
}

void PotentiometerReadTask::tick(){
  Command command;
  switch(this->potentiometer->getValue()){
    case 0 ... 255:
      command = Command::SPEED_ULTRASLOW;
    case 256 ... 511:
      command = Command::SPEED_SLOW;
    case 512 ... 767:
      command = Command::SPEED_NORMAL;
    case 768 ... 1023:
      command = Command::SPEED_FAST;
  }
  SmartRadar.enqueueCommand(command);
}
