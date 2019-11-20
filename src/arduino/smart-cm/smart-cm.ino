#include "Scheduler.h"
#include "BlinkTask.h"
#include "Radar.h"

//Scheduler sched;

PositionalServoMotor* servo;
bool flag;
void setup(){
  Serial.begin(9600); 
  servo = new PositionalServoMotorImpl(6, 16);
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
  if(flag){
    servo->incrementTarget();
  }else{
    servo->decrementTarget();
  }
  servo->stepForwardTarget();
  Serial.println(servo->getCurrentPosition());
  if(servo->getCurrentPosition() == 15 || servo->getCurrentPosition() == 0){
    flag = !flag;
  }
  delay(200);
  
}
