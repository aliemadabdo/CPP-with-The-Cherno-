#ifndef CAR_H
#define CAR_H   

#include <iostream>

#include "speed.hpp"
#include "radar.hpp"
#include "engineTemp.hpp"
#include "batteryLevel.hpp"
#include "batteryTemp.hpp"

enum index{
    speedSensor=0, radarSensor, tempSensor, batteryLvl, batteryTemp
};

class Car{
private:

    std::vector<std::unique_ptr<Sensor>>* sensors;

public:
    Car(std::vector<std::unique_ptr<Sensor>>& sens);
    ~Car();
    
    void generateRandomVal();
    void showData();
    void diagnostics();
    void adaptiveCruiseControl();
};

#endif