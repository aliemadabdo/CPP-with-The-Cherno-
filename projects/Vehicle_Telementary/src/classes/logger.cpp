#include "../headers/logger.hpp"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

Logger* Logger::instance = nullptr; // Explain...

// friend fn
std::string time_ms() {
    // Get the current time point from the high-resolution clock
    auto currentTimePoint = std::chrono::system_clock::now();
    
    // Convert to time_t for formatting the date and time
    std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);
    
    // Create a struct to hold the formatted time
    std::tm* localTime = std::localtime(&currentTime);

    // Calculate the number of milliseconds by subtracting seconds part
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(currentTimePoint.time_since_epoch()) % 1000;

    // Use a string stream to format the time as YYYY-MM-DD HH:MM:SS.mmm
    std::ostringstream timeStream;
    timeStream << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    timeStream << '.' << std::setfill('0') << std::setw(3) << ms.count();  // Add milliseconds

    return timeStream.str();
}

void Logger::clean(std::string fileName){ // to delete all files just pass "all"

    /* FIX IT*/

    if (fileName == "alerts" || fileName == "all")
        alertsFile.open("logs/alerts.txt", std::ios::trunc);
    if (fileName == "analysis" || fileName == "all")
        analysisFile.open("logs/analysis.txt", std::ios::trunc);
    if (fileName == "info" || fileName == "all")
        infoFile.open("logs/info.txt", std::ios::trunc);
    if (fileName == "debug" || fileName == "all")
        debugFile.open("logs/debug.txt", std::ios::trunc);
}

void Logger::closeAll(){
        if (alertsFile.is_open()) {
        alertsFile.close();
    }
    if (analysisFile.is_open()) {
        analysisFile.close();
    }
    if (infoFile.is_open()) {
        infoFile.close();
    }
    if (debugFile.is_open()) {
        debugFile.close();
    }
}

Logger::Logger(): level(debug_4){
    clean("all"); std::cout << "all cleaned.\n";
    closeAll();   std::cout << "all closed.\n";

    alertsFile.open("logs/alerts.txt", std::ios::app);
    if(!alertsFile.is_open())
        std::cerr << "Failed to open the alerts file" << std::endl;

    analysisFile.open("logs/analysis.txt", std::ios::app);
    if(!analysisFile.is_open())
        std::cerr << "Failed to open the analysis File" << std::endl;

    infoFile.open("logs/info.txt", std::ios::app);
    if(!infoFile.is_open())
        std::cerr << "Failed to open the info File" << std::endl;

    debugFile.open("logs/debug.txt", std::ios::app);
    if(!debugFile.is_open())
        std::cerr << "Failed to open the debug File" << std::endl;
}

void Logger::setLogLevel(logLevel l){
    level = l;
}

void Logger::alert(std::string message, float num){
    if(level >= alerts_1)
        alertsFile << time_ms() << "\t[ALERT]:\t" << message << num << std::endl;
}

void Logger::analysis(std::string message, float num){
    if(level >= analysis_2)
        analysisFile << time_ms() << "\t[ANALYSIS]:\t" << message << num << std::endl;
}

void Logger::info(std::string message, float num){
    if(level >= info_3)
        infoFile << time_ms() << "\t[INFO]:\t" << message << num << std::endl;
}

void Logger::debug(std::string message, float num){
    if(level >= debug_4)
        debugFile << time_ms() << "\t[DEBUG]:\t" << message << num << std::endl;
}


// Destructor: Ensures files are closed
Logger::~Logger() {
    closeAll();
}

