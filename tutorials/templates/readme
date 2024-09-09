# C++ Templates Overview

## Table of Contents
1. [Introduction](#introduction)
2. [Function Templates](#function-templates)
   - [Syntax](#syntax)
   - [Example](#example)
   - [Specialization](#specialization)
3. [Class Templates](#class-templates)
   - [Syntax](#syntax-1)
   - [Example](#example-1)
   - [Specialization](#specialization-1)
4. [Template Parameters](#template-parameters)
   - [Non-type Parameters](#non-type-parameters)
   - [Template Template Parameters](#template-template-parameters)
5. [Variadic Templates](#variadic-templates)
6. [Template Metaprogramming](#template-metaprogramming)
7. [Specialization](#specialization-2)
   - [Function Template Specialization](#function-template-specialization)
   - [Class Template Specialization](#class-template-specialization)
   - [Partial Specialization](#partial-specialization)
8. [Type Traits](#type-traits)
   - [Common Type Traits](#common-type-traits)
   - [Best Practices](#best-practices)
9. [Best Practices](#best-practices-1)
10. [Common Pitfalls](#common-pitfalls)
11. [References](#references)

---

## Introduction

Templates in C++ provide a way to create generic and reusable code. They enable functions and classes to operate with different data types without being rewritten for each type. Templates are a cornerstone of generic programming in C++.

---

## Function Templates

### Syntax

Function templates are defined using the `template` keyword followed by a template parameter list. Here is the basic syntax:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

### Example

```cpp
#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;        // Outputs 7
    std::cout << max(3.5, 2.5) << std::endl;    // Outputs 3.5
    return 0;
}
```

### Specialization

Function template specialization allows you to define a custom implementation for specific types:

```cpp
#include <iostream>
#include <cstring>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Specialization for const char*
template <>
const char* max<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;                // Outputs 7
    std::cout << max(3.5, 2.5) << std::endl;            // Outputs 3.5
    std::cout << max("apple", "banana") << std::endl;   // Outputs "banana"
    return 0;
}
```

---

## Class Templates

### Syntax

Class templates are similar to function templates but are used for creating generic classes. Here is the basic syntax:

```cpp
template <typename T>
class Container {
public:
    Container(T value);
    T getValue();
private:
    T value;
};
```

### Example

```cpp
#include <iostream>

template <typename T>
class Container {
public:
    Container(T value) : value(value) {}
    T getValue() { return value; }
private:
    T value;
};

int main() {
    Container<int> intContainer(5);
    Container<double> doubleContainer(3.14);

    std::cout << intContainer.getValue() << std::endl;    // Outputs 5
    std::cout << doubleContainer.getValue() << std::endl; // Outputs 3.14

    return 0;
}
```

### Specialization

Class template specialization allows you to define specific behaviors for certain types:

```cpp
#include <iostream>

// Primary template
template <typename T>
class Container {
public:
    void print() { std::cout << "Primary template" << std::endl; }
};

// Specialization for int
template <>
class Container<int> {
public:
    void print() { std::cout << "Specialized for int" << std::endl; }
};

int main() {
    Container<double> c1;
    Container<int> c2;

    c1.print(); // Outputs: Primary template
    c2.print(); // Outputs: Specialized for int
    return 0;
}
```

#### Partial Specialization

Partial specialization allows you to specialize templates based on some but not all template parameters:

```cpp
#include <iostream>

// Primary template
template <typename T, typename U>
class Pair {
public:
    void print() { std::cout << "Primary template" << std::endl; }
};

// Partial specialization where both types are the same
template <typename T>
class Pair<T, T> {
public:
    void print() { std::cout << "Specialized Pair<T, T>" << std::endl; }
};

int main() {
    Pair<int, double> p1;
    Pair<int, int> p2;

    p1.print(); // Outputs: Primary template
    p2.print(); // Outputs: Specialized Pair<T, T>
    return 0;
}
```

---

## Template Parameters

### Non-type Parameters

Templates can accept non-type parameters, such as integers:

```cpp
template <int N>
class Array {
public:
    Array() { std::cout << "Array size: " << N << std::endl; }
};
```

### Template Template Parameters

Templates can also accept other templates as parameters:

```cpp
template <template <typename> class ContainerType>
class Wrapper {
    ContainerType<int> container;
};
```

---

## Variadic Templates

Variadic templates allow for templates that accept a variable number of template arguments:

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}
```

---

## Template Metaprogramming

Template metaprogramming involves using templates to perform computations at compile-time. This can be used for optimizing code or generating code based on compile-time conditions.

```cpp
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};
```

---

## Specialization

### Function Template Specialization

Function template specialization enables you to provide a specific implementation for certain types:

```cpp
#include <iostream>
#include <cstring>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Specialization for const char*
template <>
const char* max<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;                // Outputs 7
    std::cout << max(3.5, 2.5) << std::endl;            // Outputs 3.5
    std::cout << max("apple", "banana") << std::endl;   // Outputs "banana"
    return 0;
}
```

### Class Template Specialization

Class template specialization lets you define a specific implementation for certain types:

```cpp
#include <iostream>

// Primary template
template <typename T>
class Container {
public:
    void print() { std::cout << "Primary template" << std::endl; }
};

// Specialization for int
template <>
class Container<int> {
public:
    void print() { std::cout << "Specialized for int" << std::endl; }
};

int main() {
    Container<double> c1;
    Container<int> c2;

    c1.print(); // Outputs: Primary template
    c2.print(); // Outputs: Specialized for int
    return 0;
}
```

### Partial Specialization

Partial specialization allows you to specialize templates based on some but not all template parameters:

```cpp
#include <iostream>

// Primary template
template <typename T, typename U>
class Pair {
public:
    void print() { std::cout << "Primary template" << std::endl; }
};

// Partial specialization where both types are the same
template <typename T>
class Pair<T, T> {
public:
    void print() { std::cout << "Specialized Pair<T, T>" << std::endl; }
};

int main() {
    Pair<int, double> p1;
    Pair<int, int> p2;

    p1.print(); // Outputs: Primary template
    p2.print(); // Outputs: Specialized Pair<T, T>
    return 0;
}
```

---

## Type Traits

Type traits are tools that provide compile-time information about types. They help with template programming by allowing you to perform operations based on type properties. This can improve code readability and maintainability.

### Common Type Traits

1. **`std::is_integral`**

   Checks if a type is an integral type.

   ```cpp
   #include <iostream>
   #include <type_traits>

   template <typename T>
   void checkType() {
       if (std::is_integral<T

>::value) {
           std::cout << "Integral type" << std::endl;
       } else {
           std::cout << "Non-integral type" << std::endl;
       }
   }

   int main() {
       checkType<int>();    // Outputs: Integral type
       checkType<double>(); // Outputs: Non-integral type
       return 0;
   }
   ```

2. **`std::is_floating_point`**

   Checks if a type is a floating-point type.

   ```cpp
   #include <iostream>
   #include <type_traits>

   template <typename T>
   void checkType() {
       if (std::is_floating_point<T>::value) {
           std::cout << "Floating-point type" << std::endl;
       } else {
           std::cout << "Non-floating-point type" << std::endl;
       }
   }

   int main() {
       checkType<float>();  // Outputs: Floating-point type
       checkType<int>();    // Outputs: Non-floating-point type
       return 0;
   }
   ```

3. **`std::enable_if`**

   Enables or disables function/template instantiation based on a condition.

   ```cpp
   #include <iostream>
   #include <type_traits>

   template <typename T>
   typename std::enable_if<std::is_integral<T>::value, void>::type
   print(T value) {
       std::cout << "Integral: " << value << std::endl;
   }

   template <typename T>
   typename std::enable_if<std::is_floating_point<T>::value, void>::type
   print(T value) {
       std::cout << "Floating-point: " << value << std::endl;
   }

   int main() {
       print(42);       // Outputs: Integral: 42
       print(3.14);     // Outputs: Floating-point: 3.14
       return 0;
   }
   ```

   In this example, `print` is enabled based on whether `T` is an integral or floating-point type.

### Best Practices

- **Use `std::is_same`**: For comparing types, `std::is_same` is straightforward and efficient.
- **Combine Traits**: Combine multiple traits to perform more complex type checks.
- **Prefer `std::enable_if` and `if constexpr`**: For conditionally enabling/disabling template instantiations, prefer using `std::enable_if` and `if constexpr` in modern C++.

---

## Best Practices

- **Prefer Type Traits**: Use type traits to perform type checks and transformations.
- **Limit Specializations**: Use template specializations sparingly to avoid complexity.
- **Use `constexpr` for Constant Expressions**: For compile-time constants and computations.

---

## Common Pitfalls

- **Template Instantiation Errors**: Errors may occur if template arguments are not correctly specified or if template specializations are missing.
- **Code Bloat**: Excessive use of templates can lead to code bloat due to multiple instantiations.
- **Complex Error Messages**: Templates can generate complex error messages that are hard to understand.

---

## References

- [C++ Standard Documentation](https://en.cppreference.com/w/)
- [Effective Modern C++ by Scott Meyers](https://www.amazon.com/Effective-Modern-Specific-Ways-Improve/dp/1491908418)
- [C++ Templates: The Complete Guide by David Vandevoorde and Nicolai M. Josuttis](https://www.amazon.com/Cpp-Templates-Complete-Guide-2nd/dp/0321714121)
