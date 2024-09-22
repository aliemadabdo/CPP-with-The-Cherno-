# Inheritance In C++

Inheritance in C++ is a fundamental concept of Object-Oriented Programming (OOP), where a class (child or derived class) inherits properties and behavior (data members and member functions) from another class (parent or base class). This allows for code reusability, easier maintenance, and the ability to implement hierarchical relationships.

### Types of Inheritance in C++
1. **Single Inheritance**: A derived class inherits from a single base class.
2. **Multiple Inheritance**: A derived class inherits from more than one base class.
3. **Multilevel Inheritance**: A class is derived from another derived class, forming a chain.
4. **Hierarchical Inheritance**: Multiple classes inherit from a single base class.
5. **Hybrid Inheritance**: A combination of two or more types of inheritance.

### Syntax of Inheritance
Here’s an example illustrating how inheritance works in C++:

```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark!" << endl;
    }
};

int main() {
    // Create an object of the derived class
    Dog myDog;

    // Accessing the base class methods
    myDog.eat();   // Output: I can eat!
    myDog.sleep(); // Output: I can sleep!

    // Accessing the derived class method
    myDog.bark();  // Output: I can bark!

    return 0;
}
```

### Types of Access Specifiers in Inheritance
- **public inheritance**: Public members of the base class become public in the derived class.
- **protected inheritance**: Public members of the base class become protected in the derived class.
- **private inheritance**: Public members of the base class become private in the derived class.

### Example of Access Specifiers

```cpp
class Base {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

// Derived with public inheritance
class DerivedPublic : public Base {
public:
    void display() {
        cout << "Public var: " << publicVar << endl;     // Accessible
        cout << "Protected var: " << protectedVar << endl; // Accessible
        // cout << "Private var: " << privateVar << endl;  // Not accessible (error)
    }
};

int main() {
    DerivedPublic obj;
    cout << obj.publicVar << endl;  // Accessible
    // cout << obj.protectedVar << endl; // Error: Not accessible
}
```

Inheritance is a powerful feature in C++ that can be used to build complex hierarchies and extend functionality while keeping code modular and reusable.