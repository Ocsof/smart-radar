#include "DistanceMeasurementTask.h"

DistanceMeasurementTask::DistanceMeasurementTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->sonar = SmartRadar->getSonar();   
}

void DistanceMeasurementTask::init(int period){
  Task::init(period); 
}

void DistanceMeasurementTask::tick(){
  /*Adjust the period of this task according to selected speed*/
  this->init(static_cast<int>(SmartRadar->getSpeed()));
  if(this->sonar->isEnabled()){
    SmartRadar->addMeasurement(this->sonar->getDistance());
  }
}
