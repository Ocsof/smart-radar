#include "PotentiometerImpl.h"
#include "Arduino.h"

PotentiometerImpl::PotentiometerImpl(int analogInPin){
    this->analogInPin= analogInPin;
}

int PotentiometerImpl::getValue(){
    return analogRead(analogInPin);
}

