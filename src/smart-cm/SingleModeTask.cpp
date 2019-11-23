#include "SingleModeTask.h"
#include <avr/sleep.h>

#define RESETTING_PERIOD 50


SingleModeTask::SingleModeTask(Radar* SmartRadar){
  this->SmartRadar = SmartRadar;
  this->servo = SmartRadar->getServoMotor();
  this->resetting = true;
}

void SingleModeTask::init(int period){
  Task::init(period); 
}

void SingleModeTask::tick(){     //primo taskmode schedulato
  if(SmartRadar->getMode() == Mode::SINGLE){
    if(this->resetting){
      this->init(RESETTING_PERIOD);
      SmartRadar->getSonar()->setEnabled(false);
      if(this->servo->getCurrentPosition() != 0){
        this->servo->decrementTarget();
        this->servo->stepForwardTarget();
      }else{
        this->resetting = false;
        Serial.println("------------RESET COMPLETATO---------------");
        SmartRadar->getSonar()->setEnabled(true);
      }
    }else{
      this->init(static_cast<int>(SmartRadar->getSpeed()));
      do{ 
      }while(SmartRadar->dequeueCommand() != Command::NO_COMMAND);
      if(this->servo->getCurrentPosition() != this->servo->getNumOfPositions() - 1){
        this->servo->incrementTarget();
        this->servo->stepForwardTarget();
      }else{
        attachInterrupt(digitalPinToInterrupt(2), wakeUp, RISING);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
        sleep_enable();
        sleep_mode();  
        detachInterrupt(2);
        sleep_disable();
      }
    }
  }else{
    this->resetting = true;
    SmartRadar->getSonar()->setEnabled(true);
  }
}

void SingleModeTask::wakeUp(){}
