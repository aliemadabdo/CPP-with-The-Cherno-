# Friend Keyword Cheat Sheet

The `friend` keyword in C++ allows external functions or classes to access the private and protected members of a class. It should be used carefully as it can break encapsulation if overused.

---

### 1. **Friend Function**
- A function declared as a friend in a class has access to the class’s private and protected members.
  
**Syntax:**
```cpp
class ClassName {
private:
    int privateVar;

public:
    friend void friendFunction(ClassName &obj);  // Declaring a friend function
};
```

**Example:**
```cpp
#include <iostream>
class Box {
private:
    double width;

public:
    Box() : width(10.5) {}
    friend void printWidth(const Box &b);  // Friend function declaration
};

// Friend function definition
void printWidth(const Box &b) {
    std::cout << "Width: " << b.width << std::endl;  // Accessing private member
}

int main() {
    Box box;
    printWidth(box);  // Can access Box's private members
}
```

---

### 2. **Friend Class**
- A class declared as a friend in another class has access to all private and protected members of that class.

**Syntax:**
```cpp
class ClassName {
    friend class FriendClass;  // Declaring another class as a friend
};
```

**Example:**
```cpp
#include <iostream>
class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}
    friend class Car;  // Declaring Car as a friend class
};

class Car {
public:
    void showHorsepower(Engine &e) {
        std::cout << "Horsepower: " << e.horsepower << std::endl;  // Access private member
    }
};

int main() {
    Engine engine(500);
    Car car;
    car.showHorsepower(engine);  // Car can access Engine's private members
}
```

---

### 3. **Friend Function for Operator Overloading**
- A friend function can be used to overload operators that need to access private or protected members.

**Syntax:**
```cpp
class ClassName {
    friend ReturnType operator+(const ClassName &a, const ClassName &b);
};
```

**Example:**
```cpp
#include <iostream>
class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Friend function to overload '+' operator
    friend Complex operator+(const Complex &c1, const Complex &c2);
};

Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);  // Access private members
}

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    std::cout << "Sum: " << c3.real << " + " << c3.imag << "i" << std::endl;
}
```

---

### 4. **Friendship Properties**
- **Friendship is Not Inherited**: If class A declares class B as a friend, B’s derived classes cannot access A’s private members.
  
- **Friendship is Not Reciprocal**: If class A is a friend of class B, B is not automatically a friend of class A.

- **Friendship is Not Transitive**: If class A is a friend of class B, and B is a friend of class C, A is not automatically a friend of C.

---

### 5. **When to Use `friend`**

- **Tight Cooperation Between Classes**: When two classes need to access each other's private members and tightly collaborate.
  
- **Operator Overloading**: When an external function needs to manipulate private members of a class.
  
- **External Access Control**: When you want to allow a specific function or class to access private data without creating accessors for general use.

---

### 6. **When to Avoid `friend`**
- **Overuse Can Break Encapsulation**: Use sparingly, as it gives external access to private members, which can break the object's integrity.
  
- **Public Accessor Methods**: Prefer using getters and setters unless friend functions provide a cleaner or more efficient solution.

---

### 7. **Friend Class vs Inheritance**
- **Friend Classes**: When the class must access private members of another class but doesn’t need to derive from it.
  
- **Inheritance**: When you want a subclass to inherit behavior or state from a parent class.

---

### 8. **Common Mistakes**
- Forgetting to define friend functions **outside** the class.
- Misusing `friend` for general-purpose functions that don't require private member access.

