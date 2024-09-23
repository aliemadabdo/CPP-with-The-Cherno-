#include <iostream>
#include "headers/radar.hpp"


RadarSensor::RadarSensor(int start, int end) : Sensor(start, end) {}
RadarSensor::RadarSensor(){} // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void RadarSensor::printValue() const  {
    std::cout << " Distance: " << getValue() << "m\t";
}