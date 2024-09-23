#ifndef BATTERY_SENSOR_H
#define BATTERY_SENSOR_H

#include "sensor.hpp"

class BatterySensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

private:
    int temprature, tempLowerBound=-275 , tempUpperBound = 100;
public:
    BatterySensor(int minTemp, int maxTemp, int maxLevel);
    BatterySensor();

    int getTemp() const;
    int getLevel() const;

    void setRandomValue(); // optional to change
    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // BATTERY_SENSOR_H