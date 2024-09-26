#ifndef LOGGER_H
#define LOGGER_H


#include <string>
#include <fstream>
#include <chrono>


enum logLevel{
    off=0, alerts_1, analysis_2, info_3 , debug_4
};

class Logger{
private:
    logLevel level;
    std::ofstream alertsFile;
    std::ofstream analysisFile;
    std::ofstream infoFile;
    std::ofstream debugFile;


public:
    Logger(logLevel l);
    Logger();

    void clean(std::string fileName);
    void setLogLevel(logLevel l);    

    void alert(std::string message);
    void analysis(std::string message);
    void info(std::string message, int num);
    void debug(std::string message, int num);
    
    friend std::string time_ms();

    ~Logger();
};

// friend fn
// int64_t time_ms(){
//     auto now = std::chrono::high_resolution_clock::now();
    
//     // Get the time in milliseconds since epoch
//     auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
//     return ms;
// }

#endif // LOGGER_H