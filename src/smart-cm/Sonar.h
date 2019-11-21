#ifndef __SONAR__
#define __SONAR__

class Sonar{
public:
    virtual int getDistance() = 0;
    virtual bool isEnabled() = 0;
    virtual void setEnabled(bool enabled) = 0;
};

#endif