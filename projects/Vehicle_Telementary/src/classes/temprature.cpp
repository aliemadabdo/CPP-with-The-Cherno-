#include <iostream>
#include "../headers/temprature.hpp"


TempratureSensor::TempratureSensor(int start, int end) : Sensor(start, end) {}
TempratureSensor::TempratureSensor(){} // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void TempratureSensor::printValue() const  {
    std::cout << " Engine temp: " << getValue() << "*C\t"; // \u00B0 represents the Unicode character for the degree symbol (°).
}