#include "DistanceMeasurementTask.h"

DistanceMeasurementTask::DistanceMeasurementTask(Sonar* sonar){
  this->sonar = sonar;   
}

void DistanceMeasurementTask::init(int period){
  Task::init(period); 
}

void DistanceMeasurementTask::tick(){
  this->init(static_cast<int>Radar.getSpeed());
  if(this->sonar->isEnabled()){
    Radar.addMeasurement(this->sonar->getDistance());
  }
}
