#include "ManualModeTask.h"


ManualModeTask::ManualModeTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->servo = SmartRadar->getServoMotor();
}

void ManualModeTask::init(int period){
  Task::init(period); 
}

void ManualModeTask::tick(){
  if(SmartRadar->getMode() == Mode::MANUAL){
    /*Adjust the period of this task according to selected speed*/
    this->init(static_cast<int>(SmartRadar->getSpeed()));
    /*Take actions according to commands received*/
    do{
        Command command = SmartRadar->dequeueCommand();
        if(command == Command::MOVE_LEFT){
          this->servo->decrementTarget();
        }
        if(command == Command::MOVE_RIGHT){
          this->servo->incrementTarget();
        }
        if(command == Command::NO_COMMAND){
          break;
        }
      }while(true);
    
    this->servo->stepForwardTarget();
  }
}
