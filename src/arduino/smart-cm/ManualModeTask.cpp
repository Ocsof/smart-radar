#include "ManualModeTask.h"


ManualModeTask::ManualModeTask(){
  
}

void ManualModeTask::init(int period){
  Task::init(period); 
}

void ManualModeTask::tick(){
  if(Radar.getMode() == Mode::MANUAL){
    this->init(static_cast<int>Radar.getSpeed());
    do{
        Command command = Radar.dequeue();
        if(command == Command::MOVE_LEFT){
          Radar.getServo()->decrementTarget();
        }
        if(command == Command::MOVE_RIGHT){
          Radar.getServo()->incrementTarget();
        }
      }while(command != Command::NO_COMMAND);
    
    Radar.getServo()->stepForwardTarget();
  }
}


