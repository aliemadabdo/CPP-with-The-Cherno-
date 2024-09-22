#ifndef SENSOR_H
#define SENSOR_H

class Sensor{
private:
    float value;

    // Logger log;
    // Diagnostics diagnos;
    
protected:
    // visible for chiledrens 

    // Constructors
    Sensor();
    void generateRandomData(int start, int end);

public:

    float getValue() const ;
    virtual void printValue() const = 0; 
};

#endif // SENSOR_H