#include "Scheduler.h"
#include "BlinkTask.h"
#include "Radar.h"

//Scheduler sched;


Radar* SmartRadar;
bool flag;
PositionalServoMotor* servo;
void setup(){
  Serial.begin(9600); 
  SmartRadar = new Radar();
  servo = SmartRadar->getServoMotor();
  flag = true;
/*
  Serial.begin(9600);
  sched.init(100);
 
  Task* t0 = new BlinkTask(13);
  t0->init(100);

  Task* t1 = new PrintTask();
  t1->init(1000);
  
  sched.addTask(t0);
  sched.addTask(t1);
   */
}

void loop(){
  Serial.println(SmartRadar->getLastMeasurement());
  Serial.println(servo->getCurrentPosition());
  servo->incrementTarget();
  servo->stepForwardTarget();
  delay(500);
}
