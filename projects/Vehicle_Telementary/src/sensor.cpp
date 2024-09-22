#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#include "sensor.hpp"

constexpr int baseStart = 0;
constexpr int baseEnd = 100;

Sensor::Sensor()  {
    generateRandomData(baseStart, baseEnd); 
}

float Sensor::getValue() const {
    return value;
}

void Sensor::generateRandomData(int start, int end) {
    // Seed the random number generator with current time to guarentee no replications
    std::srand(std::time(0));

    // Generate a random number in the range [start, end]
    value = start + std::rand() % (end - start + 1);
}