
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
constexpr int maxBatteryLevel = 90; // 90% 

// Define thresholds for alerts
constexpr float speedAlertThreshold = 0.8f;
constexpr float engineTempAlertThreshold = 0.9f;
constexpr float batteryTempAlertThreshold = 0.9f;
constexpr int lowBatteryLevel = 20; // 20%

int main(){
    int speed, distance, engineTemp, batteryLevel, batteryTemp;

    SpeedSensor speedSensor(minSpeed, maxSpeed);
    RadarSensor radarSensor(0, maxDistance);
    TempratureSensor tempSensor(minEngineTemp, maxEngineTemp);
    BatterySensor battery(minBatteryTemp, maxBatteryTemp, maxBatteryLevel);



    while(true){
        /*SIMULATE SENSORS*/
        speedSensor.setRandomValue();
        radarSensor.setRandomValue();
        tempSensor.setRandomValue();
        battery.setRandomValue(); // for temp and level

        /*SHOW ON DASHBOARD*/
        speedSensor.printValue();
        radarSensor.printValue();
        tempSensor.printValue();
        battery.printValue();
        cout << endl;

        /* Diagnostics */
        /*GET SENSORS VALUES*/
        speed = speedSensor.getValue();
        distance = radarSensor.getValue();
        engineTemp = tempSensor.getValue();
        batteryLevel = battery.getLevel();
        batteryTemp = battery.getTemp();
        
        if (speed > 0.8*maxSpeed || speed < -0.8*minSpeed) 
            breaks(speedSensor); // apply breaks till be under threshold
        if (distance < 0.2*maxDistance) 
            breaks(speedSensor); // No actual relation between the speed and the distance here so we apply the same logic
            // TODO: add relation between speed and distance
        if (engineTemp > 0.9*maxEngineTemp || engineTemp < 1.1*minEngineTemp) 
            breaks(speedSensor); // No actual relation between the speed and the engine temprature here so we apply the same logic
            // TODO: add relation between speed and engine temprature
        if (batteryTemp > 0.9*maxBatteryTemp || batteryTemp < 0.9*minBatteryTemp) 
            cout << "\n[ALERT] Battery temperature is critical! Initiating cooling...\n" << endl;
        if (batteryLevel < 20) 
            cout << "\n[ALERT] Low battery level! Please recharge...\n" << endl;

    }    
}