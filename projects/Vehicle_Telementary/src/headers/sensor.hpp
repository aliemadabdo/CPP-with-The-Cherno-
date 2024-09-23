#ifndef SENSOR_H
#define SENSOR_H

class Sensor{ // Abstract class
private:
    int value;
    int lowerBound = 0, upperBound = 100;

    // Logger log;
    // Diagnostics diagnos;
    
protected:
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