#include <iostream>
#include "../../headers/speed.hpp"
#include "../../headers/logger.hpp"

/*Sensor Range*/
constexpr int backSpeed = -50; // 50 km/h backward
constexpr int forwardSpeed = 100; // 100 km/h forward
constexpr float forwardSpeedAlert = 0.8f; // 80km/h
constexpr float backSpeedAlert = 0.9f; // -45 km/h

SpeedSensor::SpeedSensor() : Sensor(backSpeed, forwardSpeed, forwardSpeedAlert, backSpeedAlert) {
    Logger::getInstance()->info("That's all about speed sensor\n",0000);
}
                 // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void SpeedSensor::printValue() const  {
    std::cout << " Speed: " << getValue() << "km/h\t\t";
}

SpeedSensor::~SpeedSensor(){}

void applyBrakes(Sensor* ss){
    while(ss->isAlert()){ 
        int val = ss->getValue();
        if (val > 0){
            ss->setValue(val-1); 
            Logger::getInstance()->alert("BREAKS!! Speed decreased to (km/h): ", val-1);
        }
        else{
            ss->setValue(val+1); 
            Logger::getInstance()->alert("BREAKS!! Speed decreased to (km/h): ", val+1); // -ve
        }
    }     
}