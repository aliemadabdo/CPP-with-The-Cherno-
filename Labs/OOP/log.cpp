#include <iostream>
#include <string>

using namespace std;

enum LogLevel {
	noLog = 0, errorLevel, warnningLevel, infoLevel
};

class Log {
	LogLevel logLevel;
	
public:

	Log() {
		logLevel = noLog;
	}

	void setLogLevel(LogLevel l) {
		logLevel = l;
	}

	void print(string logType, string s) {
		if (logLevel >= errorLevel && logType == "ERROR") {
			cout << logType << ": " << s << endl;
		}
		else if (logLevel >= warnningLevel && logType == "WARN") {
			cout << logType << ": " << s << endl;
		}
		else if (logLevel >= infoLevel && logType == "INFO") {
			cout << logType << ": " << s << endl;
		}
		else {
			// no logging
		}
	}
};