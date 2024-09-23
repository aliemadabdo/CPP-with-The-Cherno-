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
