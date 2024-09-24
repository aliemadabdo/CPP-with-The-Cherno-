# C++ Maps Cheat Sheet

## Table of Contents
- [Initialization](#initialization)
- [Basic Operations](#basic-operations)
- [Iteration](#iteration)
- [Element Access](#element-access)
- [Element Insertion](#element-insertion)
- [Element Deletion](#element-deletion)
- [Searching](#searching)
- [Comparison](#comparison)
- [Advanced Operations](#advanced-operations)
- [Custom Comparators](#custom-comparators)

## Initialization
```cpp
#include <map>
using namespace std;

// Empty map of integers
map<int, int> m1;

// Map with initial key-value pairs
map<int, string> m2 = {
    {1, "one"},
    {2, "two"},
    {3, "three"}
};

// Map copy constructor
map<int, string> m3(m2);

// Map initialized from another range (using iterators)
map<int, string> m4(m2.begin(), m2.find(2)); // Contains elements with keys 1 and 2
```

## Basic Operations
```cpp
// Inserting elements
m1.insert({4, 40});          // Insert a key-value pair
m1[5] = 50;                  // Insert or update a key-value pair

// Accessing elements
int val = m1[4];             // Access value with key 4
int size = m1.size();        // Number of elements
bool empty = m1.empty();     // Check if the map is empty

// Removing elements
m1.erase(4);                 // Remove element with key 4
m1.clear();                  // Remove all elements
```

## Iteration
```cpp
// Iterator-based loop
for (auto it = m2.begin(); it != m2.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

// Range-based loop
for (const auto& [key, value] : m2) {
    cout << key << ": " << value << endl;
}
```

## Element Access
```cpp
// Accessing and modifying elements
string val = m2[1];          // Access value with key 1
m2[2] = "TWO";               // Modify value with key 2

// Attempting to access a non-existent key creates it
m2[4];                       // Creates a key-value pair {4, ""}

// Accessing with at() (throws exception if key doesn't exist)
try {
    string val = m2.at(1);
} catch (const out_of_range& e) {
    cout << "Key not found!" << endl;
}
```

## Element Insertion
```cpp
// Single element insertion
m2.insert({5, "five"});

// Insertion with hint (improves performance for inserting in order)
m2.insert(m2.end(), {6, "six"});

// Inserting elements from another map
map<int, string> m5;
m5.insert(m2.begin(), m2.end());

// Using emplace (constructs elements in place)
m2.emplace(7, "seven");
```

## Element Deletion
```cpp
// Erase by key
m2.erase(3);                // Erase element with key 3

// Erase by iterator
auto it = m2.find(2);
m2.erase(it);               // Erase element with key 2

// Erase range of elements
m2.erase(m2.begin(), m2.find(4)); // Erase elements with keys 1, 2, 3
```

## Searching
```cpp
// Finding an element by key
auto it = m2.find(2);
if (it != m2.end()) {
    cout << "Found: " << it->second << endl;
} else {
    cout << "Key not found" << endl;
}

// Counting elements with a specific key (always 0 or 1 for maps)
int count = m2.count(2);

// Checking if a key exists (using find)
if (m2.find(3) != m2.end()) {
    cout << "Key exists" << endl;
}

// Lower and upper bounds
auto lb = m2.lower_bound(2);  // First element not less than key 2
auto ub = m2.upper_bound(2);  // First element greater than key 2
```

## Comparison
```cpp
// Compare two maps
if (m2 == m3) { /* Maps are equal */ }
if (m2 != m3) { /* Maps are not equal */ }
if (m2 < m3) {  /* m2 is lexicographically less than m3 */ }
```

## Advanced Operations
```cpp
// Swapping maps
m1.swap(m2);                 // Swap contents of m1 and m2

// Merging maps
m1.insert(m2.begin(), m2.end()); // Insert all elements from m2 into m1

// Extracting an element
auto node = m2.extract(2);    // Extract element with key 2

// Inserting the extracted element into another map
m1.insert(move(node));
```

## Custom Comparators
```cpp
// Custom comparator for reverse order
struct ReverseCompare {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

// Map with custom comparator
map<int, string, ReverseCompare> m6 = {
    {1, "one"},
    {2, "two"},
    {3, "three"}
};
```
