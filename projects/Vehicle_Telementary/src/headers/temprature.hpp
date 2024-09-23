#ifndef TEMPRATURE_SENSOR_H
#define TEMPRATURE_SENSOR_H

#include "sensor.hpp"

class TempratureSensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

private:

public:
    TempratureSensor(int start, int end);
    TempratureSensor();
    // void setRandomValue(int start, int end); // optional to change
    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // TEMPRATURE_SENSOR_H