#ifndef CAR_H
#define CAR_H   

#include <iostream>

#include "speed.hpp"
#include "radar.hpp"
#include "engineTemp.hpp"
#include "batteryLevel.hpp"
#include "batteryTemp.hpp"

class Car{
private:
    SpeedSensor* speedSensor;
    RadarSensor* radarSensor;
    TempratureSensor* tempSensor;
    BatteryLevelSensor* batteryLvl;
    BatteryTempSensor* batteryTemp;

public:
    Car(SpeedSensor& speedSensor, RadarSensor& radarSensor, TempratureSensor& tempSensor,
     BatteryLevelSensor& batteryLvl, BatteryTempSensor& batteryTemp);
    
    void generateRandomVal();
    void showData();
    void diagnostics();
    void adaptiveCruiseControl();
};

#endif