#ifndef SENSOR_H
#define SENSOR_H

#include "logger.hpp"

class Sensor{ // Abstract class
private:
    int value;
    int lowerBound, upperBound;
    float upperAlertThreshold, lowerAlertThreshold;

    // Diagnostics diagnos;
    
protected:
    // Logger log(logLevel data_2); // this breaks the second rule of SOLID principles

    /*Dependency Injection*/ 
    // Logger* log; // Logger should be passed through the constructor to follow SOLID principles


    void setValue(int val);
    // int getUpperBound();
    // int getLowerBound();

public:
    Sensor(int start, int end, float upperAlert, float lowerAlert);
    Sensor(){}

    int getValue() const;    
    virtual void setRandomValue();
    virtual void printValue() const = 0; // pure virtual fn so its an abstract class
    bool isAlert(); // this fn helps to keep the class solid by exposing terminals to check on the sensor state
                    // with no need for passing any values to non-child classes.

};

#endif // SENSOR_H