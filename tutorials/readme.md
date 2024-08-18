# C++ Vectors Cheat Sheet

## Table of Contents
- [Initialization](#initialization)
- [Basic Operations](#basic-operations)
- [Iteration](#iteration)
- [Capacity Management](#capacity-management)
- [Element Insertion](#element-insertion)
- [Swapping and Assigning](#swapping-and-assigning)
- [Accessing Data](#accessing-data)
- [Comparison](#comparison)
- [Advanced Operations](#advanced-operations)
- [Special Functions](#special-functions)
- [2D Vectors](#2d-vectors)

## 2D Vectors
```cpp
#include <vector>
using namespace std;

// Creating a 2D vector with 3 rows and 4 columns, all elements initialized to 0
vector<vector<int>> vec2D(3, vector<int>(4, 0));

// Accessing elements
int val = vec2D[0][1]; // Access element in first row, second column

// Modifying elements
vec2D[2][3] = 10; // Set element in third row, fourth column to 10

// Adding a new row
vector<int> newRow = {5, 6, 7, 8};
vec2D.push_back(newRow);

// Iterating through a 2D vector
for (size_t i = 0; i < vec2D.size(); ++i) {
    for (size_t j = 0; j < vec2D[i].size(); ++j) {
        cout << vec2D[i][j] << " ";
    }
    cout << endl;
}

// Another way to iterate (range-based loop)
for (const auto& row : vec2D) {
    for (int elem : row) {
        cout << elem << " ";
    }
    cout << endl;
}

// Resizing 2D vector
vec2D.resize(5);           // Resize to 5 rows
for (auto& row : vec2D) {
    row.resize(6);         // Resize each row to 6 columns
}

// Clearing all elements
vec2D.clear();  // Clears all rows
