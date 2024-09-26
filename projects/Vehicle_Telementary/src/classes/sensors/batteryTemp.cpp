#include <iostream>
#include "../../headers/batteryTemp.hpp"


constexpr int minBatteryTemp = -40; // -40°C 
constexpr int maxBatteryTemp = 55; // 55°C 

// Define thresholds for alerts
constexpr float batteryTempAlert = 0.9f;

BatteryTempSensor::BatteryTempSensor(): Sensor(minBatteryTemp, maxBatteryTemp, batteryTempAlert, batteryTempAlert){
    Logger::getInstance()->info("That's all about battery temprature sensor\n",0000);
}

void BatteryTempSensor::printValue() const  {
    std::cout << "Battery temp: " << getValue() << "`C\t";
}


/*Old implementation*/
// int BatterySensor::getTemp() const{
//     return temprature;
// }

// int BatterySensor::getLevel() const{
//     return level; 

//     // update: fixed
//     // we just used the value variable as its already allocated.
//     // I don't think that this is the best way to do that, just practicing
// }

