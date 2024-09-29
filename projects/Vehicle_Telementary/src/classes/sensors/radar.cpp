#include <iostream>
#include "../../headers/radar.hpp"
#include "../../headers/logger.hpp"

constexpr int maxDistance = 300; // 300 meter
constexpr int minDistance = 0; // 300 meter
constexpr float mindistanceAlertThreshold = 0.1; // 30 meter
constexpr float maxdistanceAlertThreshold = 1; // 300 meter

RadarSensor::RadarSensor() : Sensor(minDistance, maxDistance, maxdistanceAlertThreshold, mindistanceAlertThreshold) {
    Logger::getInstance()->info("That's all about radar sensor\n",0000);
}
                // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void RadarSensor::printValue() const  {
    std::cout << " Distance: " << getValue() << "m\t";
}

RadarSensor::~RadarSensor(){}
