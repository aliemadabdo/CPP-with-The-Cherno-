
#include "headers/speed.hpp"
#include "headers/radar.hpp"
#include "headers/engineTemp.hpp"
#include "headers/batteryLevel.hpp"
#include "headers/batteryTemp.hpp"
#include "headers/logger.hpp"
#include "headers/car.hpp"

#include <iostream>

using namespace std;


int main(){

    SpeedSensor speedSensor;
    RadarSensor radarSensor;
    TempratureSensor tempSensor;
    BatteryLevelSensor batteryLvl;
    BatteryTempSensor batterytemp;

    Car car(speedSensor, radarSensor, tempSensor, batteryLvl, batterytemp);
    
    Logger::getInstance()->setLogLevel(debug_4);

    int counter = 0;
    while(true){
        Logger::getInstance()->analysis("Loop begin");
        car.generateRandomVal();
        car.adaptiveCruiseControl();
        // car.showData();
        // car.diagnostics();

        Logger::getInstance()->analysis("Loop end");

        counter++;        
    }    

}