#include "speed.hpp"
#include <thread>

void sys_init(void){
    SpeedSensor ss; 
    ss.printValue();
    // then assign the constructor to a separate thread
}

int main(){
    sys_init();
    // we need to create n threads, where n = the # sensors
    
}