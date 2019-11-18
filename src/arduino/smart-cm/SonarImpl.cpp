#include "SonarImpl.h"
#include "Arduino.h"

SonarImpl::SonarImpl(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->enabled = true;
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

int SonarImpl::getDistance(){
    /* invio impulso */
    digitalWrite(this->trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin,LOW);
    
    /* ricevi l’eco */
    float tUS = pulseIn(this->echoPin, HIGH, this->timeout);
    float t = tUS / 1000.0 / 1000.0 / 2;
    this->distance = t * this->vs;
    return this->distance;
}

void SonarImpl::setEnabled(bool enabled){
    this->enabled = enabled;
}

bool SonarImpl::isEnabled(){
    return this->enabled;
};