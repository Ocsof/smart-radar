#ifndef __POTENTIOMETERIMPL__
#define __POTENTIOMETERIMPL__

#include "Potentiometer.h"

class PotentiometerImpl: public Potentiometer{ 

public:
    PotentiometerImpl(int analogInPin);
    int getValue();
private:
    int analogInPin;    

};
#endif