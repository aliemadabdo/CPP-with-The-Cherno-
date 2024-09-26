#include <iostream>
#include "../../headers/speed.hpp"

/*Sensor Range*/
constexpr int backSpeed = -50; // 50 km/h backward
constexpr int forwardSpeed = 100; // 100 km/h forward
constexpr float forwardSpeedAlert = 0.8f; // 80km/h
constexpr float backSpeedAlert = 0.9f; // -45 km/h

SpeedSensor::SpeedSensor() : Sensor(backSpeed, forwardSpeed, forwardSpeedAlert, backSpeedAlert) {}
                 // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void SpeedSensor::printValue() const  {
    std::cout << " Speed: " << getValue() << "km/h\t\t";
}

void breaks(SpeedSensor& ss){
    while(ss.isAlert()){
        int val = ss.getValue();
        if (val > 0){
            ss.setValue(val-1); 
            std::cout << "\n[ALERT] Speed decreased to: " << val-1 << "km/h" << std::endl;
        }
        else{
            ss.setValue(val+1); 
            std::cout << "\n[ALERT] Speed increased to: " << val+1 << "km/h" << std::endl;
        }
    }     
}