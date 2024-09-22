# Virtual Functions VS Pure Virtual Functions In CPP

In C++, both **virtual functions** and **pure virtual functions** play a significant role in implementing polymorphism, allowing derived classes to override the behavior of base class methods. However, they serve different purposes and have distinct characteristics.

### 1. **Virtual Functions**

A **virtual function** is a member function in a base class that you can override in a derived class. It provides a default implementation in the base class but allows derived classes to provide their own implementation if needed.

- **Default behavior**: A virtual function has a default implementation in the base class.
- **Overridable**: Derived classes can override the virtual function, but they are not required to.
- **Can be called**: You can instantiate objects of the base class and call the virtual function on them.
  
#### Example of a Virtual Function
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function with a default implementation
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Overriding the virtual function
    void sound() override {
        cout << "Dog barks!" << endl;
    }
};

int main() {
    Animal a;
    Dog d;

    a.sound();  // Output: Animal makes a sound
    d.sound();  // Output: Dog barks!

    // Using a base class pointer
    Animal* animalPtr = &d;
    animalPtr->sound();  // Output: Dog barks! (polymorphism in action)

    return 0;
}
```

### 2. **Pure Virtual Functions**

A **pure virtual function** is a virtual function that has no implementation in the base class and must be overridden in the derived class. It is declared by appending `= 0` to the function declaration in the base class.

- **No default behavior**: A pure virtual function does not provide any implementation in the base class.
- **Must be overridden**: Derived classes are required to provide their own implementation of the pure virtual function.
- **Abstract class**: A class with one or more pure virtual functions becomes an **abstract class** and cannot be instantiated.
  
#### Example of a Pure Virtual Function
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    // Pure virtual function (no default implementation)
    virtual void sound() = 0;
};

class Dog : public Animal {
public:
    // Must override the pure virtual function
    void sound() override {
        cout << "Dog barks!" << endl;
    }
};

int main() {
    // Animal a;  // Error: Cannot instantiate an abstract class

    Dog d;
    d.sound();  // Output: Dog barks!

    Animal* animalPtr = &d;
    animalPtr->sound();  // Output: Dog barks!

    return 0;
}
```

### Key Differences Between Virtual Functions and Pure Virtual Functions

| **Virtual Functions**                   | **Pure Virtual Functions**                           |
|-----------------------------------------|------------------------------------------------------|
| Has a default implementation in the base class. | Has no implementation in the base class.             |
| Can be overridden in derived classes but is not mandatory. | Must be overridden in derived classes, or the derived class itself becomes abstract. |
| The base class can be instantiated.     | The base class becomes abstract and cannot be instantiated. |
| Used when you want to provide a common behavior that derived classes can override if needed. | Used when you want to enforce derived classes to implement specific behavior. |

### Use Cases:
- **Virtual Functions** are useful when you want to provide a default behavior but still allow derived classes to optionally override it.
- **Pure Virtual Functions** are used to define an interface (or contract) where all derived classes **must** provide specific implementations. This is essential when the base class itself cannot have any meaningful implementation of a method.

Both virtual and pure virtual functions are key components in C++ for achieving runtime polymorphism and designing flexible, extensible class hierarchies.