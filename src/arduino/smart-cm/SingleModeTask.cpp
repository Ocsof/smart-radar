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

/*Among every mode-task, this should be the first one scheduled*/
void SingleModeTask::tick(){     
  if(SmartRadar->getMode() == Mode::SINGLE){
    if(this->resetting){
      /*The goal is to minimize the time taken to reset the servo to position 0°. So we set the smallest period possible (the base period of the scheduler)*/
      this->init(RESETTING_PERIOD);
      /*While the servo is going back to 0° we don't want the sonar to produce measurements*/
      SmartRadar->getSonar()->setEnabled(false);
      /*When we reach position 0° we set 'resetting' to false*/
      if(this->servo->getCurrentPosition() != 0){
        this->servo->decrementTarget();
        this->servo->stepForwardTarget();
      }else{
        this->resetting = false;
        SmartRadar->getSonar()->setEnabled(true);
      }
    }else{
      /*Adjust the period of this task according to selected speed*/
      this->init(static_cast<int>(SmartRadar->getSpeed()));
      /*Consume every left/right command the sonar receives while in this mode*/
      do{ 
      }while(SmartRadar->dequeueCommand() != Command::NO_COMMAND);
      /*Sweep until the servo reach the last position*/
      if(this->servo->getCurrentPosition() != this->servo->getNumOfPositions() - 1){
        this->servo->incrementTarget();
        this->servo->stepForwardTarget();
      }else{
        /*If the pir is not detecting movement, enter sleep mode to save energy*/
        if(!SmartRadar->getPir()->detected()){
          attachInterrupt(digitalPinToInterrupt(2), [](){}, RISING);
          set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
          sleep_enable();
          sleep_mode();  
          detachInterrupt(2);
          sleep_disable();
          this->resetting = true;
        }
      }
    }
  }else{
    this->resetting = true;
    SmartRadar->getSonar()->setEnabled(true);
  }
}
