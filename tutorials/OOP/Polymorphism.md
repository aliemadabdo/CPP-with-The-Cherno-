# Polymorphism In C++

**Polymorphism** in C++ is one of the fundamental principles of Object-Oriented Programming (OOP). It allows objects of different classes to be treated as objects of a common base class, primarily to achieve flexibility and reusability of code. There are two types of polymorphism in C++:

1. **Compile-time polymorphism** (also called **static polymorphism**)
2. **Runtime polymorphism** (also called **dynamic polymorphism**)

### 1. **Compile-Time Polymorphism**
This type of polymorphism is achieved at compile-time. It is implemented through:
- **Function Overloading**
- **Operator Overloading**
- **Template Overloading**

#### a. Function Overloading
Function overloading allows multiple functions with the same name but different parameter lists to coexist.

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    // Function to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add two floats
    float add(float a, float b) {
        return a + b;
    }
};

int main() {
    Math math;
    cout << "Sum of integers: " << math.add(5, 10) << endl;   // Calls the int version
    cout << "Sum of floats: " << math.add(5.5f, 2.5f) << endl; // Calls the float version
    return 0;
}
```

#### b. Operator Overloading
Operator overloading allows you to define how operators behave when applied to objects of a class.

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    
    Complex(int r, int i) : real(r), imag(i) {}

    // Overload + operator for complex number addition
    Complex operator + (const Complex &obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};

int main() {
    Complex c1(2, 3), c2(1, 7);
    Complex result = c1 + c2; // Calls the overloaded + operator
    cout << "Sum = " << result.real << " + " << result.imag << "i" << endl;
    return 0;
}
```

### 2. **Runtime Polymorphism**
Runtime polymorphism is achieved through **inheritance** and **virtual functions**. It allows a function call to be resolved at runtime, enabling the program to choose the right function to call depending on the actual object type, not just the reference type.

Runtime polymorphism is implemented through:
- **Virtual Functions**
- **Function overriding**

#### Example of Runtime Polymorphism
```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void sound() override {  // Overriding the base class function
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void sound() override {  // Overriding the base class function
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* animal;   // Pointer to the base class
    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();  // Output: Dog barks (Polymorphism in action)

    animal = &cat;
    animal->sound();  // Output: Cat meows (Polymorphism in action)

    return 0;
}
```

#### Explanation:
- **Virtual Function**: The `sound()` function in the base class `Animal` is declared as virtual. This ensures that the function call is resolved dynamically at runtime, depending on the actual object (like `Dog` or `Cat`) rather than the pointer/reference type (`Animal`).
- **Function Overriding**: The derived classes (`Dog` and `Cat`) override the `sound()` function to provide their specific implementation.

### Compile-Time vs Runtime Polymorphism

| **Compile-Time Polymorphism**                        | **Runtime Polymorphism**                            |
|------------------------------------------------------|-----------------------------------------------------|
| Achieved through **function overloading** and **operator overloading**. | Achieved through **virtual functions** and **inheritance**. |
| Decision of which function to invoke is made at **compile-time**. | Decision of which function to invoke is made at **runtime**. |
| Faster execution since function calls are resolved during compilation. | Slightly slower due to function calls being resolved during runtime. |
| Less flexible as behavior is determined at compile time. | More flexible as behavior can change based on object type at runtime. |

### Why Use Polymorphism?
1. **Code Reusability**: You can write generic functions that can handle different types of objects.
2. **Flexibility and Extensibility**: New derived classes can be introduced without altering the existing code that uses the base class.
3. **Dynamic Behavior**: Allows for behavior to change at runtime depending on the actual object type, which is essential for implementing design patterns and frameworks.

Polymorphism, particularly runtime polymorphism, is a powerful tool in C++ that enables dynamic behavior and flexibility when building complex systems.