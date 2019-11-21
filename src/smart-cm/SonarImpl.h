#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl: public Sonar {

    public:
        SonarImpl(int trigPin, int echoPin);
        int getDistance();
        bool isEnabled();
        void setEnabled(bool enabled);
    private:
        int trigPin;
        int echoPin;
        bool enabled;
         /* supponendo di eseguire il test in un ambiente a 20 °C */
        const float vs = 331.45 + 0.62*20; 
        float distance;
        const int timeout = 5000; /* 5 millisecondi */
};



#endif
