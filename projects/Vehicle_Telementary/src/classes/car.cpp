#include <vector>
#include <memory>

#include "../headers/car.hpp"
#include "../headers/logger.hpp"

Car::Car(std::vector<std::unique_ptr<Sensor>>& sens) {
    sensors = &sens;

    std::cout << "After passing" << std::endl;

    std::cout << "(*sensors)[0].get(): " << (*sensors)[0].get() << std::endl;
    std::cout << "&sensors[0]: " << &sensors[0] << std::endl;
    std::cout << "&sensors: " << &sensors << std::endl;
    std::cout << "sensors: " << sensors << std::endl;

    std::cout << "." << std::endl;

}

// Polymorphism 
void Car::generateRandomVal(){
    // due to unqieneess we can't assign the variable to more than one pointer 
    // so we have to use refernces
    for(const auto &s : *sensors){ 
        std::cout << "generateRandomVal(): " << (s.get()) << std::endl; 
        s.get()->setRandomValue();
    }
}

// Polymorphism 
void Car::showData(){
    // Using `const` can make your code clearer in terms of intent.
    // It signals to other developers (or to yourself in the future) that
    // the elements being iterated over should not be modified.
    for(const auto &s : *sensors){
        std::cout << "showData()" << std::endl;
        s.get()->printValue();
                std::cout << "." << std::endl;

    }
    std::cout << std::endl;
}

void Car::diagnostics(){
    if ( (*sensors)[index::tempSensor].get()->isAlert()) 
        Logger::getInstance()->alert("Engine temperature is critical! Initiating cooling...\n",0000);
        // TODO: add relation between speed and engine temprature
    if ( (*sensors)[index::batteryTemp].get()->isAlert()) 
        Logger::getInstance()->alert("Battery temperature is critical! Initiating cooling...\n",0000);
    if ( (*sensors)[index::batteryLvl].get()->isAlert()) 
        Logger::getInstance()->alert("Low battery level! Please recharge...\n",0000);

}

void Car::adaptiveCruiseControl() {
    // Correct dynamic cast
    SpeedSensor* speedSensor = dynamic_cast<SpeedSensor*>((*sensors)[index::speedSensor].get());

    if ( (*sensors)[index::speedSensor].get()->isAlert()){
        if (speedSensor)
            applyBrakes(speedSensor);
        else{
            Logger::getInstance()->debug("Invalid dynamic casting!\n",0000);
            return;
        }
    }

    if ( (*sensors)[index::radarSensor].get()->isAlert() ){
        if (speedSensor)
            applyBrakes(speedSensor);
    }  
    // TODO: add relation between speed and distance

    free(speedSensor);
}