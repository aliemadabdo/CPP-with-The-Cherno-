
# C++ Sets Cheat Sheet

## Table of Contents
- [Overview](#overview)
- [Initialization](#initialization)
- [Basic Operations](#basic-operations)
- [Iteration](#iteration)
- [Insertion](#insertion)
- [Deletion](#deletion)
- [Finding Elements](#finding-elements)
- [Accessing Elements](#accessing-elements)
- [Comparison](#comparison)
- [Special Functions](#special-functions)

## Overview
- `std::set` is an associative container that contains a sorted set of unique elements.
- Elements in a `std::set` are automatically sorted and cannot be modified once inserted.

## Initialization
```cpp
#include <set>
using namespace std;

// Empty set of integers
set<int> s1;

// Set initialized with an initializer list
set<int> s2 = {1, 2, 3, 4, 5};

// Set from another set (copy constructor)
set<int> s3(s2);

// Set from another range
set<int> s4(s2.begin(), s2.end());
```

## Basic Operations
```cpp
// Size and emptiness
size_t size = s1.size();  // Number of elements
bool empty = s1.empty(); // Check if the set is empty

// Clear all elements
s1.clear();  // Removes all elements
```

## Iteration
```cpp
// Range-based for loop
for (const int& elem : s2) {
    cout << elem << " ";
}

// Iterator-based loop
for (set<int>::iterator it = s2.begin(); it != s2.end(); ++it) {
    cout << *it << " ";
}

// Reverse iteration
for (set<int>::reverse_iterator rit = s2.rbegin(); rit != s2.rend(); ++rit) {
    cout << *rit << " ";
}
```

## Insertion
```cpp
// Insert single element
s1.insert(10); // Inserts 10 into the set

// Insert multiple elements
s1.insert({20, 30, 40}); // Inserts 20, 30, and 40

// Insert element with hint (faster insertion)
auto it = s1.insert(s1.begin(), 25); // Inserts 25 and returns an iterator to it
```

## Deletion
```cpp
// Remove single element
s1.erase(10); // Removes the element with value 10

// Remove element by iterator
s1.erase(s1.begin()); // Removes the first element

// Remove a range of elements
s1.erase(s1.begin(), s1.find(30)); // Removes elements from the beginning up to but not including 30

// Clear all elements
s1.clear(); // Removes all elements
```

## Finding Elements
```cpp
// Find an element
auto it = s1.find(20); // Returns an iterator to the element with value 20 or s1.end() if not found

if (it != s1.end()) {
    cout << "Found element: " << *it << endl;
} else {
    cout << "Element not found" << endl;
}

// Count occurrences (always 0 or 1 in a set)
size_t count = s1.count(20); // Returns 1 if the element exists, otherwise 0
```

## Accessing Elements
```cpp
// Access element (via iterator)
auto it = s1.find(20);
if (it != s1.end()) {
    cout << "Element value: " << *it << endl;
}

// Accessing all elements
for (const auto& elem : s1) {
    cout << elem << " ";
}
```

## Comparison
```cpp
// Compare sets
if (s1 == s2) { /* Sets are equal */ }
if (s1 != s2) { /* Sets are not equal */ }
if (s1 < s2) { /* s1 is lexicographically less than s2 */ }
if (s1 > s2) { /* s1 is lexicographically greater than s2 */ }
```

## Special Functions
```cpp
// Lower bound (first element not less than the given value)
auto it = s1.lower_bound(25); // Returns an iterator to the first element not less than 25

// Upper bound (first element greater than the given value)
it = s1.upper_bound(25); // Returns an iterator to the first element greater than 25

// Equal range (returns a pair of iterators for the range of equal elements)
auto range = s1.equal_range(25); // Returns a pair of iterators
```

### Key Points:
- **Uniqueness**: `std::set` only allows unique elements; duplicate values are not stored.
- **Sorted Order**: Elements are stored in a sorted order by default, based on the comparison function provided (usually `<`).
- **Logarithmic Complexity**: Most operations, such as insertion, deletion, and lookup, have `O(log n)` time complexity due to the underlying balanced tree structure.
