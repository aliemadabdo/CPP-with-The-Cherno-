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
    static Logger* instance; // Pointer to the single instance

    logLevel level;
    std::ofstream alertsFile;
    std::ofstream analysisFile;
    std::ofstream infoFile;
    std::ofstream debugFile;

    Logger(); // private constructor to prevent instantiation

public:

    static Logger* getInstance(){
        if(!instance){ // only one pointer to a single instance
            instance = new Logger();
        }
        return instance;
    }

    void setLogLevel(logLevel l);    

    void alert(std::string message);
    void analysis(std::string message);
    void info(std::string message, int num);
    void debug(std::string message, int num);
    
    void clean(std::string fileName);
    
    friend std::string time_ms();

    // Deleting copy constructor and assignment operator to prevent copies
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

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