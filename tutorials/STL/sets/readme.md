# C++ Sets Cheat Sheet


This cheat sheet now covers `std::set`, `std::multiset`, `std::unordered_set`, and `std::unordered_multiset`, highlighting the key differences and functionalities of each container.


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
### `std::set`
- An associative container that contains a sorted set of unique elements.
- Elements are automatically sorted and cannot be modified once inserted.

### `std::multiset`
- Similar to `std::set`, but allows duplicate elements.
- Elements are stored in sorted order.

### `std::unordered_set`
- An associative container that contains a set of unique elements with no particular order.
- Provides faster average time complexity for operations due to hashing.

### `std::unordered_multiset`
- Similar to `std::unordered_set`, but allows duplicate elements.
- Elements are stored in no particular order, and operations like insertion and lookup are generally fast due to hashing.

## Initialization
```cpp
#include <set>
#include <unordered_set>
using namespace std;

// Empty sets of integers
set<int> s1;
multiset<int> ms1;
unordered_set<int> us1;
unordered_multiset<int> ums1;

// Set initialized with an initializer list
set<int> s2 = {1, 2, 3, 4, 5};
multiset<int> ms2 = {1, 2, 2, 3, 4, 5};
unordered_set<int> us2 = {1, 2, 3, 4, 5};
unordered_multiset<int> ums2 = {1, 2, 2, 3, 4, 5};

// Set from another set (copy constructor)
set<int> s3(s2);
multiset<int> ms3(ms2);
unordered_set<int> us3(us2);
unordered_multiset<int> ums3(ums2);

// Set from another range
set<int> s4(s2.begin(), s2.end());
multiset<int> ms4(ms2.begin(), ms2.end());
unordered_set<int> us4(us2.begin(), us2.end());
unordered_multiset<int> ums4(ums2.begin(), ums2.end());
```

## Basic Operations
```cpp
// Size and emptiness
size_t size = s1.size();  // Number of elements
bool empty = s1.empty(); // Check if the set is empty

// Clear all elements
s1.clear();  // Removes all elements
ms1.clear();
us1.clear();
ums1.clear();
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
ms1.insert(10); // Inserts 10 into the multiset
us1.insert(10); // Inserts 10 into the unordered set
ums1.insert(10); // Inserts 10 into the unordered multiset

// Insert multiple elements
s1.insert({20, 30, 40});
ms1.insert({20, 30, 40});
us1.insert({20, 30, 40});
ums1.insert({20, 30, 40});

// Insert element with hint (faster insertion in `set` and `multiset`)
auto it = s1.insert(s1.begin(), 25);
auto mit = ms1.insert(ms1.begin(), 25);
```

## Deletion
```cpp
// Remove single element
s1.erase(10); // Removes the element with value 10
ms1.erase(10); // Removes all instances of the element with value 10
us1.erase(10); // Removes the element with value 10
ums1.erase(10); // Removes all instances of the element with value 10

// Remove element by iterator
s1.erase(s1.begin()); // Removes the first element
ms1.erase(ms1.begin());
us1.erase(us1.begin());
ums1.erase(ums1.begin());

// Remove a range of elements
s1.erase(s1.begin(), s1.find(30));
ms1.erase(ms1.begin(), ms1.find(30));
```

## Finding Elements
```cpp
// Find an element
auto it = s1.find(20); // Returns an iterator to the element with value 20 or s1.end() if not found
auto mit = ms1.find(20);
auto uit = us1.find(20);
auto umit = ums1.find(20);

if (it != s1.end()) {
    cout << "Found element: " << *it << endl;
}

// Count occurrences
size_t count = s1.count(20); // Always 0 or 1 in a `set`
size_t mcount = ms1.count(20); // Can be more than 1 in a `multiset`
size_t ucount = us1.count(20); // Always 0 or 1 in an `unordered_set`
size_t umcount = ums1.count(20); // Can be more than 1 in an `unordered_multiset`
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

// Note: unordered sets do not support comparison operators
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
- **Uniqueness**:
  - `std::set` and `std::unordered_set` only allow unique elements; duplicate values are not stored.
  - `std::multiset` and `std::unordered_multiset` allow duplicate elements.
  
- **Sorted Order**:
  - `std::set` and `std::multiset` store elements in sorted order.
  - `std::unordered_set` and `std::unordered_multiset` store elements in an arbitrary order based on hash values.

- **Logarithmic Complexity**:
  - In `std::set` and `std::multiset`, most operations, such as insertion, deletion, and lookup, have `O(log n)` time complexity due to the underlying balanced tree structure.
  
- **Average Constant Complexity**:
  - In `std::unordered_set` and `std::unordered_multiset`, operations like insertion, deletion, and lookup typically have `O(1)` average time complexity due to the use of hashing.

