# OOP in C++

## Table of Contents

1. [Introduction](#introduction)
2. [Classes and Objects](#classes-and-objects)
   - [Defining a Class](#defining-a-class)
   - [Creating Objects](#creating-objects)
   - [Access Specifiers](#access-specifiers)
   - [Constructors and Destructors](#constructors-and-destructors)
   - [Types of Constructors](#types-of-constructors)
   - [Types of Destructors](#types-of-destructors)
   - [Member Functions](#member-functions)
   - [Static Members](#static-members)
   - [When to Use Classes and Objects](#when-to-use-classes-and-objects)
3. [Encapsulation](#encapsulation)
   - [Encapsulation in Depth](#encapsulation-in-depth)
   - [When to Use Encapsulation](#when-to-use-encapsulation)
4. [Inheritance in C++](#inheritance-in-c)
   - [Types of Inheritance](#types-of-inheritance)
   - [Single Inheritance](#single-inheritance)
   - [Multiple Inheritance](#multiple-inheritance)
   - [When to Use Inheritance](#when-to-use-inheritance)
5. [Polymorphism](#polymorphism)
   - [Compile-Time Polymorphism](#compile-time-polymorphism)
   - [Runtime Polymorphism](#runtime-polymorphism)
   - [Tricky Uses of Polymorphism](#tricky-uses-of-polymorphism)
   - [When to Use Polymorphism](#when-to-use-polymorphism)
6. [Abstract Class](#abstract-class)
   - [Pure Virtual Functions](#pure-virtual-functions)
   - [Tricky Uses of Abstract Classes](#tricky-uses-of-abstract-classes)
   - [When to Use an Abstract Class](#when-to-use-an-abstract-class)
7. [Virtual Functions vs Pure Virtual Functions](#virtual-functions-vs-pure-virtual-functions)
8. [When to Use Abstract Class vs Normal Base Class](#when-to-use-abstract-class-vs-normal-base-class)
9. [Operator Overloading](#operator-overloading)
   - [When to Use Operator Overloading](#when-to-use-operator-overloading)
10. [Function Overloading](#function-overloading)
   - [When to Use Function Overloading](#when-to-use-function-overloading)
11. [Friend Functions and Friend Classes](#friend-functions-and-friend-classes)
   - [When to Use Friend Functions and Classes](#when-to-use-friend-functions-and-classes)
12. [Copy Constructor](#copy-constructor)
   - [When to Use Copy Constructors](#when-to-use-copy-constructors)
13. [Function Overriding](#function-overriding)
   - [When to Use Function Overriding](#when-to-use-function-overriding)
14. [Dynamic Memory Allocation in OOP](#dynamic-memory-allocation-in-oop)
   - [When to Use Dynamic Memory Allocation](#when-to-use-dynamic-memory-allocation)
15. [Tricky Uses of OOP Principles](#tricky-uses-of-oop-principles)
16. [Conclusion](#conclusion)

---

## Introduction

**Object-Oriented Programming (OOP)** in C++ is a programming model that revolves around the concept of **objects** and **classes**. It allows you to model real-world entities, focusing on data and behavior. C++ provides various OOP features such as **encapsulation**, **inheritance**, **polymorphism**, and **abstraction**, making code more modular, reusable, and maintainable.

---

## Classes and Objects

### When to Use Classes and Objects

Use classes and objects when you want to represent real-world entities with attributes (data members) and behaviors (functions). Classes help in grouping data and functions into meaningful units and provide the structure for reusable code.

---

## Encapsulation

### Encapsulation in Depth

**Encapsulation** is the process of wrapping up data and functions into a single unit (class). It provides a mechanism to restrict direct access to some of the object’s components, which is why private and protected members are not accessible from outside the class directly. Instead, public functions (getters and setters) are used to access and modify private data.

**Key benefits:**
- **Control**: You can control what data can be modified or accessed.
- **Data Hiding**: Internal implementation details of a class are hidden from the outside world, providing a cleaner and more understandable interface.

```cpp
class BankAccount {
private:
    int balance;  // Private members can only be accessed by member functions.

public:
    BankAccount(int initialBalance) : balance(initialBalance) {}

    void deposit(int amount) {
        balance += amount;
    }

    int getBalance() const {
        return balance;
    }
};
```

### When to Use Encapsulation

- **Data Protection**: Use encapsulation whenever you want to protect sensitive data from direct access.
- **Interface Simplification**: It allows you to expose a simplified interface for complex classes and hide unnecessary details.

---

## Constructors and Destructors

### Types of Constructors

1. **Default Constructor**: A constructor with no parameters.
   ```cpp
   class Person {
   public:
       Person() {
           cout << "Default constructor called" << endl;
       }
   };
   ```

2. **Parameterized Constructor**: A constructor that accepts parameters to initialize object attributes.
   ```cpp
   class Person {
   public:
       Person(string name, int age) {
           cout << "Parameterized constructor called for " << name << endl;
       }
   };
   ```

3. **Copy Constructor**: A constructor that creates a copy of an object.
   ```cpp
   class Person {
   public:
       Person(const Person &p) {
           cout << "Copy constructor called" << endl;
       }
   };
   ```

4. **Move Constructor**: Introduced in C++11, a move constructor efficiently transfers ownership of resources from a temporary object.
   ```cpp
   class Person {
   public:
       Person(Person&& other) noexcept {
           cout << "Move constructor called" << endl;
       }
   };
   ```

### Types of Destructors

A **destructor** is a special member function that is called when an object is destroyed. It is used to release resources allocated by the constructor.

- **Default Destructor**: Automatically generated if not explicitly defined.
  ```cpp
  ~Person() {
      cout << "Destructor called" << endl;
  }
  ```

### When to Use Constructors and Destructors

- **Constructors**: Always use constructors to ensure proper initialization of an object’s members.
- **Destructors**: Use destructors for classes that manage resources like file handles or dynamic memory, ensuring proper cleanup.

---

## Inheritance in C++

### When to Use Inheritance

- **Reusability**: Use inheritance when you want to reuse code across classes with a common base.
- **Hierarchical Structure**: It is useful when there’s a hierarchical relationship in the problem domain (e.g., base class `Animal` and derived classes `Dog`, `Cat`).

---

## Polymorphism

### Tricky Uses of Polymorphism

- **Interface Flexibility**: Use polymorphism to allow derived classes to modify or extend base class behavior without modifying the base class.
- **Extensibility**: Runtime polymorphism (with virtual functions) enables programs to be easily extended with new derived classes, without altering existing code.

### When to Use Polymorphism

- **Dynamic Behavior**: Use polymorphism when objects need to exhibit different behaviors based on their runtime type (for example, overriding functions in derived classes).
- **Code Maintenance**: If a system involves frequent updates or the need to extend functionality, polymorphism helps manage future changes effectively.

---

## Abstract Class

### Tricky Uses of Abstract Classes

Abstract classes allow you to define a contract without providing complete implementations. This ensures that derived classes will implement certain functionalities, while still allowing flexibility for derived classes to have different implementations.

### When to Use an Abstract Class

- **Common Interface**: Use abstract classes when you want to define a common interface for all derived classes.
- **Mandatory Implementation**: Use it to enforce certain functionality across all derived classes through pure virtual functions.

---

## Operator Overloading

### When to Use Operator Overloading

- **Custom Data Types**: Operator overloading is useful when you have user-defined types (e.g., `Complex` numbers, `Matrix` class) that need to behave like built-in types.

---

## Function Overloading

### When to Use Function Overloading

- **Different Argument Types**: Use function overloading when you need multiple versions of a function that operate on different types or numbers of parameters.

---

## Friend Functions and Friend Classes

### When to Use Friend Functions and Classes

- **Private Access**: Use friend functions and classes when you need an external function or class to access private members of another class but do not want to expose those members to the general public.

---

## Copy Constructor

### When to Use Copy Constructors

- **Copying Objects**: Use the copy constructor to create an exact copy of an object, especially when it contains dynamically allocated memory or other resources that require deep copying.

---

## Function Overriding

### When to Use Function Overriding

- **Different Behavior**: Use function overriding when you need a derived class to have

 a different implementation of a function that’s already defined in the base class.

---

## Tricky Uses of OOP Principles

1. **Mixing Virtual and Non-Virtual Functions**: Carefully mix virtual and non-virtual functions to balance performance and flexibility.
2. **Virtual Inheritance**: Solve the diamond problem with virtual inheritance to ensure only one base class instance is inherited.
3. **Interface Segregation**: Use multiple smaller interfaces (abstract classes) rather than a large, monolithic interface.
