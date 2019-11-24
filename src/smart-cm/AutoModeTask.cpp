#include "AutoModeTask.h"


AutoModeTask::AutoModeTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->servo = SmartRadar->getServoMotor();
  this->direction = true;
  this->nearObjects = new bool[this->servo->getNumOfPositions()];
}

void AutoModeTask::init(int period){
  Task::init(period); 
}

void AutoModeTask::tick(){
  if(SmartRadar->getMode() == Mode::AUTO){
    /*If at least in one of the positions were previously detected near objects, enter alarm mode. Otherwise exit alarm mode.*/
    this->nearObjects[this->servo->getCurrentPosition()] = SmartRadar->getLastMeasurement() <= D_FAR && SmartRadar->getLastMeasurement() != 0;
    for(int i = 0; i<16; i++){
      if(this->nearObjects[i]){
        SmartRadar->setAlarm(true);
        break;
      }
      if(i == 15){
        SmartRadar->setAlarm(false);
      }
    }
    /*Adjust the period of this task according to selected speed*/
    this->init(static_cast<int>(SmartRadar->getSpeed()));
    /*Consume every left/right command the sonar receives while in this mode*/
    do{
    }while(SmartRadar->dequeueCommand() != Command::NO_COMMAND);
    
    /*Move only if the last measurement was >= D_NEAR. Otherwise enter tracking mode (don't move)*/
    if(SmartRadar->getLastMeasurement() >= D_NEAR || SmartRadar->getLastMeasurement() == 0){
      /*If servo reached extreme left of the movement range set direction to right (true)*/
      if(this->servo->getCurrentPosition() == 0){
        this->direction = true;
      }
      /*If servo reached extreme right of the movement range set direction to left (false)*/
      if(this->servo->getCurrentPosition() == this->servo->getNumOfPositions() - 1){
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
}
