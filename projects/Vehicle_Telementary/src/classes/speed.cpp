#include <iostream>
#include "../headers/speed.hpp"


SpeedSensor::SpeedSensor(int start, int end) : Sensor(start, end) {}
SpeedSensor::SpeedSensor(){} // as the drived class constructs the base class so, 
                // we will need a default constructor for the drived and base classes

void SpeedSensor::printValue() const  {
    std::cout << " Speed: " << getValue() << "km/h\t\t";
}

void breaks(SpeedSensor& ss){
    while(ss.getValue() > ss.getUpperBound()*0.8){
        std::cout << "\n[ALERT] Speed decreased to: " << ss.getValue() << "km/h" << std::endl;
        ss.setValue(ss.getValue()-1); 
    }     
}