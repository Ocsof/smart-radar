#include "PirImpl.h"
#include "Arduino.h"

PirImpl::PirImpl(int pin){
    this->pin = pin;
    pinMode(this->pin,INPUT);
}

bool PirImpl::detected(){
    int detected = digitalRead(pin);
    return detected == HIGH;
};
