#include "SingleModeTask.h"

#define RESETTING_PERIOD 100


SingleModeTask::SingleModeTask(){
  this->resetting = true;
}

void SingleModeTask::init(int period){
  Task::init(period); 
}

void SingleModeTask::tick(){
  if(Radar.getMode() == Mode::SINGLE){
    if(this->resetting){
      this->init(RESETTING_PERIOD);
      Radar.getSonar().setEnabled(false);
      if(Radar.getServo()->isExtremeLeft()){
        Radar.getServo()->decrementTarget();
        Radar.getServo()->stepForwardTarget();
      }else{
        this->resetting = false;
        Radar.getSonar().setEnabled(true);
      }
    }else{
      this->init(static_cast<int>Radar.getSpeed());
      do{
        Radar.dequeue();
      }while(command != Command::NO_COMMAND);
      if(!Radar.getServo()->isExtremeRight()){
        Radar.getServo()->incrementTarget();
        Radar.getServo()->stepForwardTarget();
      }      
    }
  }else{
    this->resetting = true;
    Radar.getSonar().setEnabled(true);
  }
}

