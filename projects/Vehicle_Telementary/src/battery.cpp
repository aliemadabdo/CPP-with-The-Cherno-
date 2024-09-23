#include <iostream>
#include "headers/battery.hpp"


BatterySensor::BatterySensor(int start, int end) : Sensor(start, end) {}
BatterySensor::BatterySensor(){} // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void BatterySensor::printValue() const  {
    std::cout << " Speed: " << getValue() << "km/h\t\t";
}