#include "Scheduler.h"
#include "BlinkTask.h"
#include "ButtonCheckTask.h"
#include "DistanceMeasurementTask.h"
#include "AutoModeTask.h"
#include "SingleModeTask.h"
#include "ManualModeTask.h"
#include "SerialReadTask.h"
#include "SerialWriteTask.h"
#include "PotentiometerReadTask.h"

Scheduler sched;
Radar* SmartRadar;

void setup(){
  Serial.begin(9600); 
  SmartRadar = new Radar();
  sched.init(50);
 
  Task* t0 = new ButtonCheckTask(SmartRadar, SmartRadar->getButtonS(), Command::MODE_SINGLE);
  t0->init(50);

  Task* t1 = new ButtonCheckTask(SmartRadar, SmartRadar->getButtonM(), Command::MODE_MANUAL);
  t1->init(50);

  Task* t2 = new ButtonCheckTask(SmartRadar, SmartRadar->getButtonA(), Command::MODE_AUTO);
  t2->init(50);

  Task* t3 = new BlinkTask(SmartRadar);
  t3->init(50);

  Task* t4 = new DistanceMeasurementTask(SmartRadar);
  t4->init(150);

  Task* t5 = new PotentiometerReadTask(SmartRadar);
  t5->init(150);

  Task* t6 = new SerialWriteTask(SmartRadar);
  t6->init(150);

  Task* t7 = new SerialReadTask(SmartRadar);
  t7->init(50);

  Task* t8 = new SingleModeTask(SmartRadar);
  t8->init(150);

  Task* t9 = new ManualModeTask(SmartRadar);
  t9->init(150);

  Task* t10 = new AutoModeTask(SmartRadar);
  t10->init(150);
  
  sched.addTask(t0);
  sched.addTask(t1);
  sched.addTask(t2);
  sched.addTask(t3);
  sched.addTask(t4);
  sched.addTask(t5);
  sched.addTask(t6);
  sched.addTask(t7);
  sched.addTask(t8);
  sched.addTask(t9);
  sched.addTask(t10);
}

void loop(){
  sched.schedule();
}
