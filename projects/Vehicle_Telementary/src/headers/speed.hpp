#ifndef SPEED_SENSOR_H
#define SPEED_SENSOR_H

#include "sensor.hpp"

class SpeedSensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

private:

public:
    SpeedSensor(int start, int end);
    SpeedSensor();
    // void setRandomValue(int start, int end); // optional to change
    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // SPEED_SENSOR_H