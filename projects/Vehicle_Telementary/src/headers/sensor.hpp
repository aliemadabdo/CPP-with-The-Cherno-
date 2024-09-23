#ifndef SENSOR_H
#define SENSOR_H

class Sensor{ // Abstract class
private:
    int value;
    int lowerBound = 0, upperBound = 100;

    // Logger log;
    // Diagnostics diagnos;
    
public:
    Sensor(int start, int end);
    Sensor(){}
    
    virtual void setRandomValue();
    int getValue() const;
    virtual void printValue() const = 0; // pure virtual fn so its an abstract class

};

#endif // SENSOR_H