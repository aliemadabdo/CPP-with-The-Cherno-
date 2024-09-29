#include <iostream>
#include <vector>
#include <memory>  // For std::unique_ptr

#include "headers/speed.hpp"
#include "headers/radar.hpp"
#include "headers/engineTemp.hpp"
#include "headers/batteryLevel.hpp"
#include "headers/batteryTemp.hpp"
#include "headers/car.hpp"
#include "headers/logger.hpp"

int main(){

    Logger::getInstance()->setLogLevel(debug_4);

    // the use of smart pointers to manage memory allocation and deletion
    std::vector<std::unique_ptr<Sensor>> sensors; 

    // In this case push back will not create a new copy in memory from the passes object
    sensors.push_back(std::make_unique<SpeedSensor>());
    sensors.push_back(std::make_unique<RadarSensor>());
    sensors.push_back(std::make_unique<TempratureSensor>());
    sensors.push_back(std::make_unique<BatteryLevelSensor>());
    sensors.push_back(std::make_unique<BatteryTempSensor>());
    
    for(const auto &s : sensors){
        std::cout << "Real Addresses: " << &s << std::endl;
    }

sensors[0].get()->setValue(5);
    std::cout << "sensors[0].get(): " << sensors[0].get()->getValue() << std::endl;
    std::cout << "sensors[0].get(): " << sensors[0]->getValue() << std::endl;
    // std::cout << "&sensors[0]: " << &sensors[0].get() << std::endl;
    std::cout << "&sensors: " << &sensors << std::endl;
    std::cout << "&sensors[0]: " << &sensors[0] << std::endl;


    Car car(sensors);
        
    Logger::getInstance()->debug("sensors vector of unique_ptrs to Sensor class size: ", sensors.size());    
    Logger::getInstance()->debug("unique_ptrs to radar class size: ", sizeof(sensors[index::radarSensor]));    
    Logger::getInstance()->debug("radar class size: ", sizeof(*sensors[index::radarSensor]));    
    Logger::getInstance()->debug("engine temprature Enum size: ", sizeof(tempSensor));    
    Logger::getInstance()->debug("car class size: ", sizeof(car));    
    
    int counter = 0;
    while(true){
        counter++;        
        Logger::getInstance()->analysis("Begin loop number ", counter);
        std::cout << "." << std::endl;
        car.generateRandomVal();
        std::cout << "." << std::endl;
        car.adaptiveCruiseControl();
        std::cout << "." << std::endl;
        car.showData();
        std::cout << "." << std::endl;
        car.diagnostics();
        std::cout << "." << std::endl;

        Logger::getInstance()->analysis("End loop number ", counter);
    }    

    Logger::getInstance()->~Logger();

}