# Car Sensor System

## Overview

The Car Sensor System is a modular software application designed to monitor various vehicle parameters using different sensors. This system incorporates a logging mechanism to track alerts, analyses, and general information about the vehicle's performance. 

## Features

- **Modular Sensor Design**: Abstract base class `Sensor` and derived classes for specific sensors (e.g., `SpeedSensor`, `RadarSensor`).
- **Logging System**: Singleton pattern implementation for logging various events, with categorized log files.
- **Car Integration**: A `Car` class that aggregates multiple sensors and manages their interactions.
- **Polymorphism**: Flexible handling of different sensor types using virtual functions.

## Components

1. **Sensors**:
   - `Sensor`: Abstract base class for all sensors.
   - `SpeedSensor`: Monitors vehicle speed.
   - `RadarSensor`: Measures distance to obstacles.

2. **Logger**:
   - Implements a logging system using the Singleton design pattern to ensure a single instance.
   - Supports logging different types of messages (alerts, analysis, information, debug).

3. **Car Class**:
   - Integrates sensors and manages their data, including alert checks.
