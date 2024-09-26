#include <iostream>
#include "../../headers/batteryLevel.hpp"
#include "../../headers/logger.hpp"

 
constexpr int minBatteryLevel = 0; // 0% 
constexpr int maxBatteryLevel = 100; // 100%
constexpr float lowBatteryLevel = 0.2f; // 20%
constexpr float fullBatteryLevel = 1; // 100%

BatteryLevelSensor::BatteryLevelSensor(): Sensor(minBatteryLevel, maxBatteryLevel, fullBatteryLevel, lowBatteryLevel){
    Logger::getInstance()->info("That's all about battery level sensor\n",0000);
}

void BatteryLevelSensor::printValue() const  {
    std::cout << "Battery Level: " << getValue() << "`C\t";
}

