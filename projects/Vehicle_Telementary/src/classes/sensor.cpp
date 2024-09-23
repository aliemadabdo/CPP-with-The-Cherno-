#include <cstdlib>  // For rand() and srand()

#include "../headers/sensor.hpp"

Sensor::Sensor(int start, int end) : lowerBound(start), upperBound(end){}

int Sensor::getValue() const {
    return value;
}

void Sensor::setRandomValue() {
    value = lowerBound + std::rand() % (upperBound - lowerBound + 1);
}

void Sensor::setValue(int val) {
    value = val;
}

int Sensor::getUpperBound(){
    return upperBound;
}

int Sensor::getLowerBound(){
    return lowerBound;
}
