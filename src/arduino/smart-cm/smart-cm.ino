#include "Scheduler.h"
#include "BlinkTask.h"
#include "Radar.h"

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
  Serial.println(SmartRadar.getAlarmLed()->isOn());
   if(SmartRadar.getButtonA()->isPressed()){
    Serial.println("PRESSED");
    if(!SmartRadar.getAlarmLed()->isOn()){
      SmartRadar.getAlarmLed()->switchOn();
      delay(10);
    }else{
      SmartRadar.getAlarmLed()->switchOff();
      delay(10);
    }
   }
   delay(115);
}
