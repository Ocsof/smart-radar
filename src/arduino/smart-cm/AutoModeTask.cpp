#include "AutoModeTask.h"


AutoModeTask::AutoModeTask(){
  this->direction = true;
  this->nearObjects = new int[Radar.getServo()->getNumOfPositions()];
}

void AutoModeTask::init(int period){
  Task::init(period); 
}

void AutoModeTask::tick(){
  if(Radar.getMode() == Mode::AUTO){
    this->nearObjects[Radar.getServo()->getCurrentPosition()] = Radar.getLastMeasurement() >= D_NEAR && Radar.getLastMeasurement <= D_FAR;
    for(int i = 0; i<16; i++){
      if(this->nearObjects[i]){
        Radar.setAlarm(true);
        break;
      }
      if(i == 15){
        Radar.setAlarm(false);
      }
    }
    this->init(static_cast<int>Radar.getSpeed());
    do{
      Radar.dequeueCommand();
    }while(command != Command::NO_COMMAND);
    if(Radar.getServo()->isExtremeLeft == true){
      this->direction = true;
    }
    if(Radar.getServo()->isExtremeRight() == true){
      this->direction = false;
    }
    if(this->direction){
      Radar.getServo()->incrementTarget();
    }else{
      Radar.getServo()->decrementTarget();
    }
    Radar.getServo()->stepForwardTarget();
  }
}


