#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl: public Sonar {

    public:
        SonarImpl(int trigPin, int echoPin);
        int getDistance();
    private:
        int trigPin;
        int echoPin;
         /* supponendo di eseguire il test in un ambiente a 20 °C */
        const float vs = 331.45 + 0.62*20; 
        float distance;
};



#endif
