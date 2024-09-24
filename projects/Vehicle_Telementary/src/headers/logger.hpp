#ifndef LOGGER_H
#define LOGGER_H


#include <string>
#include <fstream>

enum logLevel{
    off=0, alerts_1, data_2
};

class Logger{
private:
    logLevel level;
    std::ofstream alertsFile;
    std::ofstream dataFile;

public:
    Logger(logLevel l);
    Logger();

    void setLogLevel(logLevel l);    
    void alert(std::string s);
    
    template<typename T>
    void data(T logs);

    ~Logger();
};

#endif // LOGGER_H