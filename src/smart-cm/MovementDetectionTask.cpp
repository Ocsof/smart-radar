#include "MovementDetectionTask.h"

MovementDetectionTask::MovementDetectionTask(Pir* pir){
  this->pir = pir;   
}

void MovementDetectionTask::init(int period){
  Task::init(period); 
}

void MovementDetectionTask::tick(){
  //forse è meglio farlo con interrupt ed eliminare il task
}
