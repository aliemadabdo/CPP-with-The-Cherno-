### Approach:
- First we have thinked about the architecture and how each component interact with each other.
- Second we implemented the abstract class Sensor which will be a parent for every sensor [Inheritance].
- We have devided each class into header and cpp files.
-  

### Notes and Questions [To Be Revised]
- Its not modular to take the sensor range with object instansiation.
- It may be better to handle this operation internally for each sensor class in a separet thread
- we need to create n threads, where n = the # sensors
- after a simple investigation inside the thread lib, i found that thread library is only POSIX complaint so i can not apply this on windows [but the chatGPT say that it should work so i will let it as a future work]
- In some cases, using friend is a cleaner solution than adding public accessor methods.

### Is It OOP Compliant?

Yes, the revised code follows Object-Oriented Programming (OOP) principles and is compliant with standard OOP practices. Let's break down how the major OOP principles are applied:

### 1. **Encapsulation**
   - Each sensor class (e.g., `SpeedSensor`, `RadarSensor`, etc.) encapsulates its own behavior and state (e.g., the `value` of the sensor).
   - Access to the sensor data is controlled via getter methods (`getValue()`, `getLevel()`, `getTemp()`), while modifying data is done through controlled methods (`setRandomValue()`).
   - Sensor-specific logic is encapsulated in each class, ensuring that each class handles its own behavior without exposing unnecessary details.

### 2. **Abstraction**
   - The `Sensor` base class defines an abstract interface (`printValue()` as a pure virtual function). This ensures that all derived sensors must implement their own version of `printValue()`.
   - The abstract class hides the implementation details from the user, providing a uniform interface (`printValue()` and `setRandomValue()`), which is used in the main function without needing to know the specific details of each sensor.

### 3. **Inheritance**
   - All sensor types (`SpeedSensor`, `RadarSensor`, `TempratureSensor`, `BatterySensor`) inherit from a base class (`Sensor`). This allows common functionality (e.g., the concept of a sensor having a value) to be shared, while each derived class implements its own specific behavior (e.g., random generation of values within specific ranges).
   - The abstract base class (`Sensor`) ensures that all derived classes must implement their own version of certain methods, ensuring consistency.

### 4. **Polymorphism**
   - The use of a pure virtual function (`printValue() const = 0;`) in the base class enforces polymorphism. This allows the derived classes to provide their own implementation of `printValue()`, enabling the code to call `printValue()` on any sensor without needing to know which sensor type is being used.
   - Polymorphism is effectively used when the `simulateSensors()` function handles multiple sensor types uniformly by calling their respective `printValue()` and `setRandomValue()` methods.
