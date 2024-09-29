### Approach:
- First we have thinked about the architecture and how each component interact with each other.
- Second we implemented the abstract class Sensor which will be a parent for every sensor [Inheritance].
- We have devided each class into header and cpp files.
- We used singleton design pattern to implement a single instance logging system
- all data and messages are logged in the logs directoy, each type of messages in its own log file
- We created a car class to assemble all parts in one entity with composed methods
- We used CMake to automate the building process
- we have used all oop princeples like mentioned below
- some helpful concepts like: friend functions, static functions, pure virutal functions, constructors and destructor, refrences, this keyword, working with files, cerr for error handling, setters and getters, initializer lists and more
- one trick i fealt iam an OOP guy, is the usage of the fn isAlert() as at the first i checked for the alerts in the diagnodtics fn it self trying to get all values i need from sensors but 
   bool isAlert(); // this fn helps to keep the class solid by exposing terminals to check on the sensor state with no need for passing any values to non-child classes.


### Notes and Questions [To Be Revised]
- Its not modular to take the sensor range with object instansiation.
- It may be better to handle this operation internally for each sensor class in a separet thread
- we need to create n threads, where n = the # sensors
- after a simple investigation inside the thread lib, i found that thread library is only POSIX complaint so i can not apply this on windows [but the chatGPT say that it should work so i will let it as a future work]
- In some cases, using friend is a cleaner solution than adding public accessor methods.
- where to use the logger
-  
