#ifndef __PIRIMPL__
#define __PIRIMPL__

#include "Pir.h"

class PirImpl: public Pir{
  
public:
    PirImpl(int pin);
    bool detected();
private:
    int pin;
};

#endif
