#include "PotentiometerImpl.h"
#include "Arduino.h"

PotentiometerImpl::PotentiometerImpl(int analogInPin){
    pinMode(analogInPin, INPUT);
    this->analogInPin= analogInPin;
}

int PotentiometerImpl::getValue(){
    return analogRead(analogInPin);
}
