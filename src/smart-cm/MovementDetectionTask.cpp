#include "MovementDetectionTask.h"

MovementDetectionTask::MovementDetectionTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->pir = SmartRadar->getPir();   
}

void MovementDetectionTask::init(int period){
  Task::init(period); 
}

void MovementDetectionTask::tick(){
  //forse è meglio farlo con interrupt ed eliminare il task
}
