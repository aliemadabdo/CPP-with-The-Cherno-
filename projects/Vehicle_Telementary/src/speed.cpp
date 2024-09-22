#include <iostream>
#include "speed.hpp"

void SpeedSensor::printValue() const {
    std::cout << " Speed: " << getValue() << std::endl;
}