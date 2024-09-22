# Abstract Class VS Normal Base Class

Deciding between using an **abstract class** or a **normal base class** in C++ depends on the design needs of your program. Each serves a different purpose:

### When to Use an Abstract Class

An **abstract class** should be used when you want to define a common interface that **must** be implemented by derived classes. The abstract class can have pure virtual functions, which ensure that all derived classes will provide specific functionality.

- **Common Interface/Contract**: Use an abstract class when you want to enforce that certain behaviors (methods) must be implemented by every derived class. The abstract class outlines the "contract" that derived classes need to fulfill.
  
- **No Instantiation**: If the base class doesn't represent an entity that makes sense to be instantiated on its own, and its purpose is purely to serve as a blueprint for derived classes.

- **Polymorphic Behavior**: When using polymorphism, abstract classes define the interface, allowing you to treat derived class objects as instances of the abstract class, knowing that all essential methods will be implemented.

- **Mandatory Override**: If some methods have no meaningful implementation at the base class level, you should use pure virtual functions to force derived classes to provide their own implementation.

#### Example Use Case:
Consider you are building a system for different types of payment methods (e.g., credit card, PayPal). You want all payment methods to have a `pay()` method, but the way each method works will differ. Thus, the base class should be abstract:

```cpp
class Payment {
public:
    // Pure virtual function
    virtual void pay(double amount) = 0;
};

class CreditCard : public Payment {
public:
    void pay(double amount) override {
        // Credit card-specific payment logic
        cout << "Paying $" << amount << " with Credit Card." << endl;
    }
};

class PayPal : public Payment {
public:
    void pay(double amount) override {
        // PayPal-specific payment logic
        cout << "Paying $" << amount << " with PayPal." << endl;
    }
};
```

Here, `Payment` is an abstract class that defines the interface for payment methods but cannot be instantiated on its own. Each derived class (`CreditCard`, `PayPal`) implements the `pay()` method in its specific way.

### When to Use a Normal Base Class

A **normal base class** should be used when you want to provide **default functionality** that derived classes may inherit and use directly, or optionally override if needed.

- **Shared Functionality**: If you want to provide common functionality for all derived classes that may or may not be overridden. A normal base class can define both concrete (implemented) and virtual methods, giving flexibility to derived classes.
  
- **Instantiable Base Class**: If it makes sense for the base class to be instantiated on its own or represent a general concept that can be refined in derived classes.

- **Optional Override**: When the derived classes may want to override the base class methods but are not required to. This is often the case with polymorphic behavior, where the base class provides a default implementation, and only certain derived classes override it.

#### Example Use Case:
Imagine you are creating a base class for vehicles where every vehicle has the ability to `start()` and `stop()`, but some specific types of vehicles can override these behaviors if needed.

```cpp
class Vehicle {
public:
    // Concrete function with default behavior
    void start() {
        cout << "Vehicle is starting." << endl;
    }

    // Concrete function
    void stop() {
        cout << "Vehicle is stopping." << endl;
    }
};

class Car : public Vehicle {
    // Inherits the default start and stop behavior
};

class Bike : public Vehicle {
public:
    // Override the default start behavior
    void start() {
        cout << "Bike is kick-starting." << endl;
    }
};
```

In this case, `Vehicle` is a normal base class. The derived class `Car` inherits the default behavior for `start()` and `stop()`, while `Bike` overrides the `start()` method with its own specific behavior.

### Summary of When to Use Each:

| **Abstract Class**                              | **Normal Base Class**                             |
|-------------------------------------------------|--------------------------------------------------|
| Use when you want to enforce a common interface. | Use when you want to share common functionality.  |
| Contains at least one pure virtual function.     | Contains fully implemented methods and optional virtual methods. |
| Cannot be instantiated.                         | Can be instantiated if needed.                   |
| All derived classes **must** implement the pure virtual functions. | Derived classes may override methods or use inherited behavior. |
| Provides no meaningful default implementation.  | Provides concrete implementations that can be used or overridden. |
| Ideal for defining an interface or contract.     | Ideal for creating shared functionality that may be reused or refined. |

### Conclusion:
- Use an **abstract class** when the base class represents a generic interface or blueprint that derived classes **must** implement.
- Use a **normal base class** when you want to define default behavior and functionality that derived classes may use directly or override as needed.

Choosing between an abstract class and a normal base class depends on how strict the relationship should be between the base class and the derived classes.