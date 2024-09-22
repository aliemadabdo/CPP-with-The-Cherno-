#include "speed.hpp"

void sys_init(void){
    SpeedSensor ss; 
    ss.printValue();
    // then assign the constructor to a separate thread
}

int main(){
    sys_init();

}