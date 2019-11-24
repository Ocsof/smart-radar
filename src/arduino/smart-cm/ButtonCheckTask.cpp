#include "ButtonCheckTask.h"

ButtonCheckTask::ButtonCheckTask(Radar* SmartRadar, Button* button, Command command){
  this->SmartRadar = SmartRadar;
  this->button = button;  
  this->command = command;  
}

void ButtonCheckTask::init(int period){
  Task::init(period); 
}

void ButtonCheckTask::tick(){
  if(this->button->isPressed()){
    SmartRadar->enqueueCommand(this->command);
  }
}
