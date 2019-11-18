#include "ManualModeTask.h"


ManualModeTask::ManualModeTask(){
  this->servo = SmartRadar.getServoMotor();
}

void ManualModeTask::init(int period){
  Task::init(period); 
}

void ManualModeTask::tick(){
  if(SmartRadar.getMode() == Mode::MANUAL){
    this->init(static_cast<int>(SmartRadar.getSpeed()));
    do{
        Command command = SmartRadar.dequeueCommand();
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


