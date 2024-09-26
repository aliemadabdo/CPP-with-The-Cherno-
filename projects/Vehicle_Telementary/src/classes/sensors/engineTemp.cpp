#include <iostream>
#include "../../headers/engineTemp.hpp"


constexpr int minEngineTemp = 195; // 220°C is the upper recommended engine temprature
constexpr int maxEngineTemp = 220; // 195°C is the lower recommended engine temprature
constexpr float engineTempAlert = 1; 

TempratureSensor::TempratureSensor() : Sensor(minEngineTemp, maxEngineTemp, engineTempAlert, engineTempAlert) {}
                // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void TempratureSensor::printValue() const  {
    std::cout << " Engine temp: " << getValue() << "*C\t"; // \u00B0 represents the Unicode character for the degree symbol (°).
}