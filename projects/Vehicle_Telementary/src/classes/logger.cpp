#include "../headers/logger.hpp"
#include <fstream>
#include <iostream>



Logger::Logger(logLevel l) : level(l){
    alertsFile.open("../logs/alerts.txt", std::ios::app);
    dataFile.open("../logs/data.txt", std::ios::app);
}
Logger::Logger(): level(off){
    alertsFile.open("../logs/alerts.txt", std::ios::app);
    dataFile.open("../logs/data.txt", std::ios::app);
}

void Logger::setLogLevel(logLevel l){
    level = l;
}

void Logger::alert(std::string s){
    if(level < alerts_1) return;

    if(!alertsFile.is_open())
        std::cerr << "Failed to open the alerts file" << std::endl;

    alertsFile << "[ALERT]: " << s;

}
template<typename T>
void Logger::data(T logs){
    if(level < data_2) return;


    if(!dataFile.is_open())
        std::cerr << "Failed to open the data file" << std::endl;

    dataFile << logs;
}

// Destructor: Ensures files are closed
Logger::~Logger() {
    if (alertsFile.is_open()) {
        alertsFile.close();
    }
    if (dataFile.is_open()) {
        dataFile.close();
    }
}