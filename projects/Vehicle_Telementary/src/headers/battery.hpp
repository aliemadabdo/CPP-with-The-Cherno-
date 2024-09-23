#ifndef BATTERY_SENSOR_H
#define BATTERY_SENSOR_H

#include "sensor.hpp"

class BatterySensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

private:
    int level;
public:
    BatterySensor(int start, int end);
    BatterySensor();
    // void setRandomValue(int start, int end); // optional to change
    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // BATTERY_SENSOR_H