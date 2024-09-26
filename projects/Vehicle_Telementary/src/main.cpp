
#include "headers/speed.hpp"
#include "headers/radar.hpp"
#include "headers/engineTemp.hpp"
#include "headers/batteryLevel.hpp"
#include "headers/batteryTemp.hpp"
#include "headers/car.hpp"

#include <iostream>

using namespace std;


int main(){

    Logger::getInstance()->setLogLevel(debug_4);
    Logger::getInstance()->clean("all");

    SpeedSensor speedSensor;
    RadarSensor radarSensor;
    TempratureSensor tempSensor;
    BatteryLevelSensor batteryLvl;
    BatteryTempSensor batterytemp;

    Car car(speedSensor, radarSensor, tempSensor, batteryLvl, batterytemp);
    
    Logger::getInstance()->debug("speed class size: ", sizeof(speedSensor));    
    Logger::getInstance()->debug("radar class size: ", sizeof(radarSensor));    
    Logger::getInstance()->debug("engine temprature class size: ", sizeof(tempSensor));    
    Logger::getInstance()->debug("batter temprature class size: ", sizeof(batterytemp));    
    Logger::getInstance()->debug("batter level class size: ", sizeof(batteryLvl));    
    Logger::getInstance()->debug("car class size: ", sizeof(car));    
    
    int counter = 0;
    while(true){
        Logger::getInstance()->analysis("Begin loop number ", counter);
        
        car.generateRandomVal();
        car.adaptiveCruiseControl();
        // car.showData();
        // car.diagnostics();

        Logger::getInstance()->analysis("End loop number ", counter);

        counter++;        
    }    

    Logger::getInstance()->~Logger();

}