Here’s a more organized and structured version of your thoughts:

---

### Approach:

1. **System Architecture**:
   - We began by planning the architecture and how each component (sensors, car, logger) would interact.
   - Key components include sensors, a car class, and a logging system.

2. **Sensor Implementation**:
   - Created an abstract class `Sensor`, which serves as the parent class for all sensors, demonstrating the concept of **Inheritance**.
   - Each sensor is divided into header (`.hpp`) and implementation (`.cpp`) files for modularity and maintainability.

3. **Logging System**:
   - Utilized the **Singleton Design Pattern** to ensure that only a single instance of the `Logger` class exists throughout the application.
   - Different types of log messages (alerts, analysis, etc.) are saved in their respective log files under the `logs/` directory.

4. **Car Class**:
   - Implemented a `Car` class that composes different sensors, bringing all components together into a cohesive unit.
   - The `Car` class uses composed methods to manage and interact with its components (sensors, logger).

5. **Build Automation**:
   - Used **CMake** to automate the build process, ensuring cross-platform compatibility and simplifying the compilation.

6. **OOP Principles**:
   - Applied key Object-Oriented Programming principles such as:
     - **Encapsulation**: Encapsulating sensor data and controlling access through getters and setters.
     - **Abstraction**: Hiding implementation details through abstract methods.
     - **Inheritance**: All sensors inherit from the abstract `Sensor` class.
     - **Polymorphism**: Using virtual functions to achieve runtime flexibility.
   - Other concepts implemented include friend functions, static functions, constructors, destructors, references, `this` keyword, file handling, `cerr` for error handling, initializer lists, etc.

7. **OOP Trick**:
   - A notable OOP technique was using the `isAlert()` method in the `Car` class. Initially, the alert checks were done directly in the diagnostics function, but moving this logic into `isAlert()` kept the class design solid, exposing sensor status cleanly without passing values between non-child classes.

---

### Notes and Future Improvements:

1. **Modularity of Sensor Range**:
   - Currently, sensor ranges are passed during object instantiation. It might be better to handle these internally within each sensor class.

2. **Threading for Sensors**:
   - A potential improvement is to handle each sensor's operations in separate threads to improve performance. However, since the thread library is POSIX-compliant, this approach cannot be directly applied on Windows. It remains as future work.

3. **Friend Functions**:
   - In some cases, using friend functions can be cleaner than exposing public access methods.

4. **Logger Usage**:
   - Determine the best practices for where and how to use the `Logger` effectively throughout the system.

---

### OOP Compliance:

The implementation adheres to core Object-Oriented Programming principles:

1. **Encapsulation**:
   - Each sensor class encapsulates its state (e.g., value, temperature, etc.) and controls access through methods like `getValue()` and `setRandomValue()`.

2. **Abstraction**:
   - The `Sensor` base class abstracts common sensor behavior and enforces derived classes to implement specific methods like `printValue()`.

3. **Inheritance**:
   - All sensor types (e.g., `SpeedSensor`, `RadarSensor`) inherit from the `Sensor` base class, sharing common functionality and allowing individual behavior to be defined in derived classes.

4. **Polymorphism**:
   - Polymorphism is achieved through the virtual functions in the `Sensor` class, enabling the main function to interact with various sensor types in a uniform manner. 

