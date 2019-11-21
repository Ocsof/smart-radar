#include "ButtonCheckTask.h"

ButtonCheckTask::ButtonCheckTask(Button* button, Command command){
  this->button = button;  
  this->command = command;  
}

void ButtonCheckTask::init(int period){
  Task::init(period); 
}

void ButtonCheckTask::tick(){
  if(this->button->isPressed()){
    SmartRadar.enqueueCommand(this->command);
  }
}
