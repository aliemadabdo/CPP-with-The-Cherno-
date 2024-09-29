#ifndef RADAR_SENSOR_H
#define RADAR_SENSOR_H

#include "sensor.hpp"

class RadarSensor : public Sensor {
// Default inheritance access: private if no modifier is specified.

private:

public:
    RadarSensor();
    ~RadarSensor();
    // void setRandomValue(int start, int end); // optional to change
    void printValue() const override;  // Override the pure virtual function from Sensor
    // the override key word is optional here
};

#endif // RADAR_SENSOR_H