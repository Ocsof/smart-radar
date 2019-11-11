#include "ButtonCheckTask.h"

ButtonCheckTask::ButtonCheckTask(int pin, Mode mode){
  this->pin = pin;  
  this->mode = mode;  
}

void ButtonCheckTask::init(int period){
  Task::init(period);
  this->button = new Button(pin);  
}

void ButtonCheckTask::tick(){
  if(button->isPressed){
    radar->setMode(this->mode);
  }
}
