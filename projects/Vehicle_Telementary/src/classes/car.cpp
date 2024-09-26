#include "../headers/car.hpp"

Car::Car(SpeedSensor& speedSensor, RadarSensor& radarSensor, TempratureSensor& tempSensor,
 BatteryLevelSensor& batteryLvl, BatteryTempSensor& batteryTemp){
    this->speedSensor = &speedSensor;
    this->radarSensor = &radarSensor;
    this->tempSensor = &tempSensor;
    this->batteryLvl = &batteryLvl;
    this->batteryTemp = &batteryTemp;
}

void Car::generateRandomVal(){
    /*SIMULATE SENSORS*/
    speedSensor->setRandomValue();
    radarSensor->setRandomValue();
    tempSensor->setRandomValue();
    batteryLvl->setRandomValue(); 
    batteryTemp->setRandomValue(); 
}

void Car::showData(){
    /*SHOW ON DASHBOARD*/
    speedSensor->printValue();
    radarSensor->printValue();
    tempSensor->printValue();
    batteryLvl->printValue();
    batteryTemp->printValue();
    std::cout << std::endl;
}

void Car::diagnostics(){
    if (tempSensor->isAlert()) 
        std::cout << "Engine temperature is critical! Initiating cooling...\n";
        // breaks(*speedSensor); // No actual relation between the speed and the engine temprature here so we apply the same logic
        // TODO: add relation between speed and engine temprature
    if (batteryTemp->isAlert()) 
        std::cout << "Battery temperature is critical! Initiating cooling...\n";
    if (batteryLvl->isAlert()) 
        std::cout << "Low battery level! Please recharge...\n";

}

void Car::adaptiveCruiseControl() {
    if (speedSensor->isAlert()) 
        breaks(*speedSensor); // apply breaks till be under threshold
    if (radarSensor->isAlert()) 
        breaks(*speedSensor); // No actual relation between the speed and the distance here so we apply the same logic
        // TODO: add relation between speed and distance
}