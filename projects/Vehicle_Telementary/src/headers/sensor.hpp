#ifndef SENSOR_H
#define SENSOR_H

#include "logger.hpp"

class Sensor{ // Abstract class
private:
    int value;
    int lowerBound = 0, upperBound = 100;

    // Diagnostics diagnos;
    
protected:
    // Logger log(logLevel data_2); // this breaks the second rule of SOLID principles ?

    /*Dependency Injection*/ 
    // Logger* log; // Logger should be passed through the constructor to follow SOLID principles


    void setValue(int val);
    int getUpperBound();
    int getLowerBound();

public:
    Sensor(int start, int end);
    Sensor(){}

    int getValue() const;    
    virtual void setRandomValue();
    virtual void printValue() const = 0; // pure virtual fn so its an abstract class

};

#endif // SENSOR_H