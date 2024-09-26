#include <cstdlib>  // For rand() and srand()

#include "../headers/sensor.hpp"

Sensor::Sensor(int start, int end, float upperAlert, float lowerAlert) 
: lowerBound(start), upperBound(end), upperAlertThreshold(upperAlert), lowerAlertThreshold(lowerAlert){
    Logger::getInstance()->info("Lower Bound: ", start);
    Logger::getInstance()->info("Upper Bound: ", end);
    Logger::getInstance()->info("Lower Bound alert at: ", lowerAlert);
    Logger::getInstance()->info("Upper Bound alert at: ", upperAlert);
}

int Sensor::getValue() const {
    return value;
}

void Sensor::setRandomValue() {
    value = lowerBound + std::rand() % (upperBound - lowerBound + 1);
    Logger::getInstance()->info("Value: ",value);
}

void Sensor::setValue(int val) {
    value = val;
    Logger::getInstance()->info("Speed while appling breaks: ",value);
}

bool Sensor::isAlert(){
    return ((value < lowerAlertThreshold*lowerBound) || (value > upperAlertThreshold*upperBound));
}

// int Sensor::getUpperBound(){
//     return upperBound;
// }

// int Sensor::getLowerBound(){
//     return lowerBound;
// }

