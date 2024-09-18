# C++ Pair Cheat Sheet

## Table of Contents
- [Introduction](#introduction)
- [Syntax](#syntax)
- [Creating a Pair](#creating-a-pair)
- [Accessing Pair Elements](#accessing-pair-elements)
- [Modifying Pair Elements](#modifying-pair-elements)
- [Using `make_pair()`](#using-make_pair)
- [Comparing Pairs](#comparing-pairs)
- [Common Use Cases](#common-use-cases)
- [Code Example](#code-example)

---

## Introduction
In C++, a `pair` is a container that holds two values of potentially different types. It is part of the Standard Template Library (STL) and is useful for grouping two values together, such as key-value pairs.

## Syntax
```cpp
std::pair<T1, T2> pairName;
```
- `T1` and `T2`: Data types of the elements.
- `pairName`: Name of the pair.

## Creating a Pair
You can create a pair by initializing it with values of the specified types.
```cpp
std::pair<int, std::string> myPair(1, "apple");
```

## Accessing Pair Elements
The elements of the pair can be accessed using the `.first` and `.second` members.
```cpp
std::cout << "First: " << myPair.first;   // Outputs: 1
std::cout << "Second: " << myPair.second; // Outputs: "apple"
```

## Modifying Pair Elements
The elements can also be modified in the same way.
```cpp
myPair.first = 2;
myPair.second = "banana";
```

## Using `make_pair()`
You can use `make_pair()` to create a pair without specifying the types explicitly.
```cpp
auto myPair = std::make_pair(2, "orange");
```

## Comparing Pairs
Pairs are compared **lexicographically**:
- First, the `.first` elements are compared.
- If the `.first` elements are equal, the `.second` elements are compared.

```cpp
std::pair<int, int> p1(1, 2);
std::pair<int, int> p2(1, 3);

if (p1 < p2) {
    std::cout << "p1 is less than p2";
}
```

## Common Use Cases
- **In Associative Containers**: `std::map` and `std::unordered_map` store elements as key-value pairs.
```cpp
std::map<int, std::string> myMap;
myMap[1] = "apple";
```

- **Returning Multiple Values from Functions**: Functions can return two related values using `std::pair`.
```cpp
std::pair<int, double> getDimensions() {
    return std::make_pair(10, 15.5);
}
```

## Code Example
```cpp
#include <iostream>
#include <utility>  // For std::pair

int main() {
    // Creating and accessing a pair
    std::pair<int, std::string> myPair(1, "apple");
    std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;

    // Modifying elements of the pair
    myPair.first = 2;
    myPair.second = "banana";
    std::cout << "Modified Pair - First: " << myPair.first << ", Second: " << myPair.second << std::endl;

    // Using make_pair
    auto anotherPair = std::make_pair(3, "cherry");
    std::cout << "First: " << anotherPair.first << ", Second: " << anotherPair.second << std::endl;

    // Comparing pairs
    std::pair<int, int> p1(1, 2), p2(1, 3);
    if (p1 < p2) {
        std::cout << "p1 is less than p2" << std::endl;
    }

    return 0;
}
```

---

### Additional Resources
- [C++ Reference for `std::pair`](https://en.cppreference.com/w/cpp/utility/pair)
