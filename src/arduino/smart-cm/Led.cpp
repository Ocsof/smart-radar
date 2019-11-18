#include "Led.h"
#include "Arduino.h"

Led::Led(int pin){
  this->isLedOn = false;
  this->pin = pin;
  pinMode(pin,OUTPUT);
}

void Led::switchOn(){
  this->isLedOn = true;
  digitalWrite(pin,HIGH);
}

void Led::switchOff(){
  this->isLedOn = false;
  digitalWrite(pin,LOW);
}

bool Led::isOn(){
  return this->isLedOn;
};
