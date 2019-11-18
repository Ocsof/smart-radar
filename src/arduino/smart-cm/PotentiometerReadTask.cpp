#include "PotentiometerReadTask.h"

PotentiometerReadTask::PotentiometerReadTask(Potentiometer* potentiometer){
  this->potentiomenter = potentiometer;   
}

void PotentiometerReadTask::init(int period){
  Task::init(period);
}

void PotentiometerReadTask::tick(){
  Radar.addCommand(this->selectSpeed);
}

Command selectSpeed(){
  switch(this->potentiometer->getValue()){
    case 0 ... 255:
      return SPEED_ULTRASLOW;
    case 256 ... 511:
      return SPEED_SLOW;
    case 512 ... 767:
      return SPEED_NORMAL;
    case 768 ... 1023:
      return SPEED_FAST;
  }
}
