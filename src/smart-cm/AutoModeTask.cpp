#include "AutoModeTask.h"


AutoModeTask::AutoModeTask(){
  this->servo = SmartRadar.getServoMotor();
  this->direction = true;
  this->nearObjects = new bool[this->servo->getNumOfPositions()];
}

void AutoModeTask::init(int period){
  Task::init(period); 
}

void AutoModeTask::tick(){
  if(SmartRadar.getMode() == Mode::AUTO){
    this->nearObjects[this->servo->getCurrentPosition()] = SmartRadar.getLastMeasurement() >= D_NEAR && SmartRadar.getLastMeasurement() <= D_FAR;
    for(int i = 0; i<16; i++){
      if(this->nearObjects[i]){
        SmartRadar.setAlarm(true);
        break;
      }
      if(i == 15){
        SmartRadar.setAlarm(false);
      }
    }
    this->init(static_cast<int>(SmartRadar.getSpeed()));
    do{
    }while(SmartRadar.dequeueCommand() != Command::NO_COMMAND);
    if(this->servo->getCurrentPosition() == 0){
      this->direction = true;
    }
    if(this->servo->getCurrentPosition() == this->servo->getNumOfPositions()){
      this->direction = false;
    }
    if(this->direction){
      this->servo->incrementTarget();
    }else{
      this->servo->decrementTarget();
    }
    this->servo->stepForwardTarget();
  }
}


