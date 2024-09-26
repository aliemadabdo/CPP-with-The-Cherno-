#ifndef BATTERY_Level_H
#define BATTERY_Level_H

#include "sensor.hpp"

class BatteryLevelSensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

public:
    BatteryLevelSensor();

    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // BATTERY_Level_SENSOR_H