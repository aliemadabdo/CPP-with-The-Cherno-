#include <cstdlib>  // For rand() and srand()

#include "../headers/sensor.hpp"



Sensor::Sensor(int start, int end, float upperAlert, float lowerAlert) 
: lowerBound(start), upperBound(end), upperAlertThreshold(upperAlert), lowerAlertThreshold(lowerAlert) {}

int Sensor::getValue() const {
    return value;
}

void Sensor::setRandomValue() {
    // log.data( 
        value = lowerBound + std::rand() % (upperBound - lowerBound + 1);
}

void Sensor::setValue(int val) {
    // log.data(
        value = val;
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

