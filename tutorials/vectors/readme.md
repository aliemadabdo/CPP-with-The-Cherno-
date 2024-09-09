# C++ Vectors Cheat Sheet

## Table of Contents
- [Initialization](#initialization)
- [Basic Operations](#basic-operations)
- [Iteration](#iteration)
- [Capacity Management](#capacity-management)
- [Element Insertion](#element-insertion)
- [Element Deletion](#element-deletion)
- [Swapping and Assigning](#swapping-and-assigning)
- [Accessing Data](#accessing-data)
- [Comparison](#comparison)
- [Advanced Operations](#advanced-operations)
- [Special Functions](#special-functions)
- [2D Vectors](#2d-vectors)

## Initialization
```cpp
#include <vector>
using namespace std;

// Empty vector of integers
vector<int> vec1;

// Vector with initial size 10, all elements initialized to 0
vector<int> vec2(10);

// Vector with initial size 5, all elements initialized to 3
vector<int> vec3(5, 3);

// Vector initialized with an initializer list
vector<int> vec4 = {1, 2, 3, 4, 5};

// Vector copy constructor
vector<int> vec5(vec4);

// Vector from another range
vector<int> vec6(vec4.begin(), vec4.begin() + 3); // {1, 2, 3}
```

## Basic Operations
```cpp
// Adding elements
vec1.push_back(10);  // Adds 10 to the end
vec1.emplace_back(20); // Constructs 20 at the end (more efficient)

// Accessing elements
int val = vec1[0];   // Access without bounds checking
int val2 = vec1.at(1); // Access with bounds checking

// Size and capacity
size_t size = vec1.size();  // Number of elements
size_t capacity = vec1.capacity(); // Capacity (allocated memory)
bool empty = vec1.empty();  // Check if the vector is empty

// Modifying elements
vec1[0] = 100;       // Assigns 100 to the first element
vec1.front() = 200;  // Accesses and modifies the first element
vec1.back() = 300;   // Accesses and modifies the last element

// Removing elements
vec1.pop_back();     // Removes the last element
vec1.erase(vec1.begin());   // Removes the first element
vec1.erase(vec1.begin(), vec1.begin() + 2); // Removes a range of elements
vec1.clear();        // Removes all elements
```

## Iteration
```cpp
// Range-based for loop
for (int num : vec4) {
    cout << num << " ";
}

// Iterator-based loop
for (auto it = vec4.begin(); it != vec4.end(); ++it) {
    cout << *it << " ";
}

// Reverse iteration
for (auto rit = vec4.rbegin(); rit != vec4.rend(); ++rit) {
    cout << *rit << " ";
}
```

## Capacity Management
```cpp
// Resizing the vector
vec1.resize(5);    // Resize to 5 elements (new elements are default-initialized)
vec1.resize(8, 100); // Resize to 8 elements, new elements initialized to 100

// Reserving capacity
vec1.reserve(20);  // Pre-allocate memory for at least 20 elements

// Shrink capacity to fit size
vec1.shrink_to_fit();  // Reduce capacity to size
```

## Element Deletion

### 1. `erase()`
- **Purpose**: `erase` is used to remove specific elements from a vector.
- **Syntax**:
  - To remove a single element:
    ```cpp
    vector_name.erase(iterator);
    ```
  - To remove a range of elements:
    ```cpp
    vector_name.erase(start_iterator, end_iterator);
    ```

- **Example**: Remove the second element (index 1) from a vector.
  ```cpp
  #include <iostream>
  #include <vector>

  using namespace std;

  int main() {
      vector<int> vec = {1, 2, 3, 4, 5};

      // Remove element at index 1 (value = 2)
      vec.erase(vec.begin() + 1);

      for (int val : vec) {
          cout << val << " ";  // Output: 1 3 4 5
      }
      return 0;
  }
  ```

- **Example**: Remove a range of elements (from the 2nd to the 4th element).
  ```cpp
  #include <iostream>
  #include <vector>

  using namespace std;

  int main() {
      vector<int> vec = {1, 2, 3, 4, 5};

      // Remove elements from index 1 to index 3 (2, 3, and 4)
      vec.erase(vec.begin() + 1, vec.begin() + 4);

      for (int val : vec) {
          cout << val << " ";  // Output: 1 5
      }
      return 0;
  }
  ```

### 2. `clear()`
- **Purpose**: `clear` removes **all** elements from the vector, leaving it empty.
- **Syntax**:
  ```cpp
  vector_name.clear();
  ```

- **Example**: Clear all elements from a vector.
  ```cpp
  #include <iostream>
  #include <vector>

  using namespace std;

  int main() {
      vector<int> vec = {1, 2, 3, 4, 5};

      // Clear the vector
      vec.clear();

      cout << "Size after clear: " << vec.size() << endl;  // Output: 0

      return 0;
  }
  ```

### Key Differences:
- **`erase`**: Removes a specific element or range of elements but leaves the rest of the vector intact. The size of the vector is reduced.
- **`clear`**: Empties the entire vector, removing all elements.

### Notes:
- `erase` has **linear complexity**, as it may need to shift elements after removing.
- `clear` has **constant complexity** because it simply resets the internal data structure of the vector.


## Element Insertion
```cpp
// Insert single element
vec1.insert(vec1.begin(), 50);  // Insert 50 at the beginning

// Insert multiple elements
vec1.insert(vec1.end(), 3, 60);  // Insert 3 elements with value 60 at the end

// Insert elements from another container
vector<int> vec7 = {100, 200};
vec1.insert(vec1.begin(), vec7.begin(), vec7.end());  // Insert vec7 at the beginning
```

## Swapping and Assigning
```cpp
// Assign new content
vec1.assign(5, 10);  // Assign 5 elements with value 10
vec1.assign(vec4.begin(), vec4.begin() + 3); // Assign elements from another range

// Swap contents with another vector
vec1.swap(vec3);  // Swap contents of vec1 and vec3
```

## Accessing Data
```cpp
// Direct access to underlying array
int* data_ptr = vec1.data();  // Get pointer to the first element

// Accessing the first and last element
int first = vec1.front();  // First element
int last = vec1.back();    // Last element
```

## Comparison
```cpp
// Compare vectors
if (vec1 == vec2) { /* Vectors are equal */ }
if (vec1 != vec2) { /* Vectors are not equal */ }
if (vec1 < vec2) { /* vec1 is lexicographically less than vec2 */ }

```
- Best case: O(1) — if the vectors differ in the very first element.
- Worst case: O(n) — if the vectors are of the same size and identical, where n is the size of the vectors.

## Advanced Operations
```cpp
// Sorting the vector
sort(vec1.begin(), vec1.end());  // Sort in ascending order

// Reversing the vector
reverse(vec1.begin(), vec1.end());  // Reverse the vector

// Finding an element
auto it = find(vec1.begin(), vec1.end(), 3);  // Find the first occurrence of 3
if (it != vec1.end()) {
    // Element found
}
```

## Special Functions
```cpp
// Emplace at position (constructs in-place)
vec1.emplace(vec1.begin(), 500);  // Insert 500 at the beginning

// Using emplace_back for efficiency
vec1.emplace_back(600);  // Constructs and adds 600 at the end
```

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
```

