#include "SingleModeTask.h"

#define RESETTING_PERIOD 100


SingleModeTask::SingleModeTask(){
  this->servo = SmartRadar.getServoMotor();
  this->resetting = true;
}

void SingleModeTask::init(int period){
  Task::init(period); 
}

void SingleModeTask::tick(){     //primo taskmode schedulato
  if(SmartRadar.getMode() == Mode::SINGLE){
    if(this->resetting){
      this->init(RESETTING_PERIOD);
      SmartRadar.getSonar()->setEnabled(false);
      if(this->servo->getCurrentPosition() != 0){
        this->servo->decrementTarget();
        this->servo->stepForwardTarget();
      }else{
        this->resetting = false;
        SmartRadar.getSonar()->setEnabled(true);
      }
    }else{
      this->init(static_cast<int>(SmartRadar.getSpeed()));
      do{ 
      }while(SmartRadar.dequeueCommand() != Command::NO_COMMAND);
      if(!this->servo->getCurrentPosition() == this->servo->getNumOfPositions()){
        this->servo->incrementTarget();
        this->servo->stepForwardTarget();
      }      //quando finisce dovrebbe andare in idle, TODO
    }
  }else{
    this->resetting = true;
    SmartRadar.getSonar()->setEnabled(true);
  }
}
