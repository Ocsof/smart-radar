#include "Scheduler.h"
#include "BlinkTask.h"

//Scheduler sched;

void setup(){
  Serial.begin(9600); 
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
  
  //sched.schedule();
}

