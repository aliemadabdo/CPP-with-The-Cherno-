To implement a configuration file for storing sensor ranges and thresholds, you can follow these steps:

1. **Choose a Configuration Format**: JSON or XML are commonly used formats. JSON is generally simpler to read and write compared to XML, and it has good library support in C++.

2. **Create a Configuration File**: Define a file that contains your sensor ranges and thresholds in JSON format. For example:

   **config.json**:
   ```json
   {
       "sensors": {
           "temperature": {
               "min": -40,
               "max": 125,
               "alert_threshold": 100
           },
           "battery_temp": {
               "min": -20,
               "max": 80,
               "alert_threshold": 70
           },
           "battery_level": {
               "min": 0,
               "max": 100,
               "alert_threshold": 15
           }
       }
   }
   ```

3. **Parse the JSON File**: Use a library like [nlohmann/json](https://github.com/nlohmann/json) to parse the JSON file and load the sensor configurations into your C++ application.

4. **Integrate the Configuration with Your Code**: Read the configuration file at runtime and use the values for sensor initialization and alert checks.

### Example:

#### 1. **Install the JSON library**:
You can install the `nlohmann/json` library using your package manager or download the header-only version from [here](https://github.com/nlohmann/json/releases).

#### 2. **Include and Parse the Configuration**:

**`main.cpp`**:
```cpp
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "sensor.hpp"

// For convenience
using json = nlohmann::json;

struct SensorConfig {
    double min;
    double max;
    double alert_threshold;
};

// Function to load the configuration file
std::map<std::string, SensorConfig> loadConfig(const std::string& filename) {
    std::map<std::string, SensorConfig> sensorConfigs;

    // Open the configuration file
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        throw std::runtime_error("Unable to open configuration file!");
    }

    // Parse the JSON file
    json configJson;
    configFile >> configJson;

    // Extract sensor configurations
    for (auto& [key, value] : configJson["sensors"].items()) {
        SensorConfig config;
        config.min = value["min"];
        config.max = value["max"];
        config.alert_threshold = value["alert_threshold"];
        sensorConfigs[key] = config;
    }

    return sensorConfigs;
}

int main() {
    try {
        // Load sensor configurations
        auto sensorConfigs = loadConfig("config.json");

        // Access specific sensor configurations
        auto tempConfig = sensorConfigs["temperature"];
        auto batteryTempConfig = sensorConfigs["battery_temp"];

        std::cout << "Temperature Sensor Range: " << tempConfig.min << " - " << tempConfig.max << std::endl;
        std::cout << "Battery Temp Sensor Alert Threshold: " << batteryTempConfig.alert_threshold << std::endl;

        // You can now use these configurations in your sensors' logic
        // Example: pass the loaded configuration to a sensor object
        Sensor tempSensor(tempConfig.min, tempConfig.max, tempConfig.alert_threshold);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```

**`sensor.hpp`**:
```cpp
#ifndef SENSOR_HPP
#define SENSOR_HPP

class Sensor {
public:
    Sensor(double minVal, double maxVal, double threshold)
        : minVal(minVal), maxVal(maxVal), alertThreshold(threshold) {}

    void printConfig() {
        std::cout << "Min Value: " << minVal << ", Max Value: " << maxVal 
                  << ", Alert Threshold: " << alertThreshold << std::endl;
    }

private:
    double minVal;
    double maxVal;
    double alertThreshold;
};

#endif // SENSOR_HPP
```

### Explanation:
- **Step 1**: Define a JSON configuration file (`config.json`) to store sensor parameters such as min, max, and alert_threshold values.
- **Step 2**: Use the `nlohmann/json` library to read and parse the configuration file.
- **Step 3**: Load the configuration into a C++ `std::map`, where each sensor's settings are stored in a `SensorConfig` struct.
- **Step 4**: Access the configuration values when initializing or using the sensors in the program.

This approach decouples sensor parameters from the source code, allowing for easy configuration changes without recompilation.