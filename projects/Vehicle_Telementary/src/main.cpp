
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
    Logger log(debug_4);

    // log.clean("all");
    
    log.alert("You Have To Pray NOW!!! ");
    log.info("You Have To Pray NOW!!! ", 1);
    log.analysis("You Have To Pray NOW!!! ");
    log.debug("You Have To Pray NOW!!! ", 5.44);
    
    while(true){
        car.generateRandomVal();
        car.adaptiveCruiseControl();
        car.showData();
        car.diagnostics();        
    }    
}