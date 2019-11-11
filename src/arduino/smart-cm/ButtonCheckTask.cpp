#include "ButtonCheckTask.h"

ButtonCheckTask::ButtonCheckTask(int pin){
  this->pin = pin;    
}
  
void ButtonCheckTask::init(int period){
  Task::init(period);
  button = new Button(pin);  
}
  
void BlinkTask::tick(){
  if(button->isPressed){
   
  }
}
