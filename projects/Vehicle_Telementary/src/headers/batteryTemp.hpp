#ifndef BATTERY_TEMP_H
#define BATTERY_TEMP_H

#include "sensor.hpp"

class BatteryTempSensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

public:
    BatteryTempSensor();

    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // BATTERY_TEMP_SENSOR_H