
#include "headers/speed.hpp"
#include "headers/radar.hpp"
#include "headers/temprature.hpp"
#include "headers/battery.hpp"

#include <iostream>

using namespace std;

constexpr int minSpeed = -50; // 50 km/h backward
constexpr int maxSpeed = 100; // 100 km/h forward
constexpr int maxDistance = 300; // 300 meter
constexpr int minEngineTemp = 195; // 220°C is the upper recommended engine temprature
constexpr int maxEngineTemp = 220; // 195°C is the lower recommended engine temprature
constexpr int minBatteryTemp = -40; // -40°C 
constexpr int maxBatteryTemp = 55; // 55°C 

int main(){
    int speed, distance, engintemp, batteryLevel, batteryTemp;

    SpeedSensor speedSensor(minSpeed, maxSpeed);
    RadarSensor radarSensor;
    TempratureSensor tempSensor;


    while(true){
        /*SIMULATE SENSORS*/
        speedSensor.setRandomValue();
        radarSensor.setRandomValue();
        tempSensor.setRandomValue();

        /*GET SENSORS VALUES*/
        speed = speedSensor.getValue();
        distance = radarSensor.getValue();
        engintemp = tempSensor.getValue();
        
        /*SHOW ON DASHBOARD*/
        speedSensor.printValue();
        radarSensor.printValue();
        tempSensor.printValue();
        cout << endl;

        if (speed > 0.8*maxSpeed || speed < -0.8*minSpeed) /* apply breaks and set the speed to 80*/;
        if (distance < 0.2*maxDistance) /* apply breaks tell the distance be safe out of range */;
        if (engintemp > 0.9*maxEngineTemp || engintemp < 1.1*minEngineTemp) /* Put some alerts and some breaks */;
        if (batteryTemp > 0.9*maxBatteryTemp || batteryTemp < 0.9*minBatteryTemp) /* Put some alerts */;
        if (batteryLevel < 20) /* Put some alerts */;

    }    
}