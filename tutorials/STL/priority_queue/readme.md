# C++ Priority Queue Cheat Sheet

A `priority_queue` in C++ is a container adapter that provides constant-time access to the largest (or smallest) element. It is typically implemented as a binary heap.

## Table of Contents

1. [Overview](#overview)
2. [Header File](#header-file)
3. [Basic Syntax](#basic-syntax)
4. [Max-Heap vs Min-Heap](#max-heap-vs-min-heap)
5. [Common Operations](#common-operations)
   - [Push](#push)
   - [Top](#top)
   - [Pop](#pop)
   - [Empty](#empty)
   - [Size](#size)
6. [Examples](#examples)
   - [Max-Heap Example](#max-heap-example)
   - [Min-Heap Example](#min-heap-example)
   - [Custom Comparator Example](#custom-comparator-example)
7. [Time Complexity](#time-complexity)
8. [Additional Notes](#additional-notes)

## Overview

- A `priority_queue` is a type of data structure that stores elements based on priority.
- The element with the highest priority is always at the front.
- By default, it acts as a max-heap (largest element at the top), but it can also be configured as a min-heap.

## Header File

To use `priority_queue`, include the following header file:

```cpp
#include <queue>
```

## Basic Syntax

```cpp
std::priority_queue<Type, Container, ComparisonFunction> pq;
```

- **Type**: Data type of the elements (e.g., `int`, `double`).
- **Container**: Underlying container (default is `std::vector`).
- **ComparisonFunction**: Custom comparison (default is `std::less<Type>`).

## Max-Heap vs Min-Heap

### Max-Heap (default)

```cpp
std::priority_queue<int> maxHeap;
```

### Min-Heap

```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

## Common Operations

### Push

Adds an element to the priority queue.

```cpp
pq.push(value);
```

### Top

Accesses the element with the highest priority (largest for max-heap, smallest for min-heap).

```cpp
Type topElement = pq.top();
```

### Pop

Removes the element with the highest priority.

```cpp
pq.pop();
```

### Empty

Checks if the priority queue is empty.

```cpp
bool isEmpty = pq.empty();
```

### Size

Returns the number of elements in the priority queue.

```cpp
size_t size = pq.size();
```

## Examples

### Max-Heap Example

```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> maxHeap;

    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(5);

    std::cout << "Top of Max-Heap: " << maxHeap.top() << std::endl;  // Output: 10
    maxHeap.pop();
    std::cout << "Top after pop: " << maxHeap.top() << std::endl;    // Output: 5

    return 0;
}
```

### Min-Heap Example

```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(5);

    std::cout << "Top of Min-Heap: " << minHeap.top() << std::endl;  // Output: 3
    minHeap.pop();
    std::cout << "Top after pop: " << minHeap.top() << std::endl;    // Output: 5

    return 0;
}
```

### Custom Comparator Example

```cpp
#include <iostream>
#include <queue>
#include <vector>

struct ComparePair {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;  // Smaller first element has higher priority
    }
};

int main() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparePair> customHeap;

    customHeap.push({10, 2});
    customHeap.push({3, 4});
    customHeap.push({5, 1});

    std::cout << "Top of Custom Heap: (" << customHeap.top().first << ", " << customHeap.top().second << ")" << std::endl;  // Output: (3, 4)
    customHeap.pop();
    std::cout << "Top after pop: (" << customHeap.top().first << ", " << customHeap.top().second << ")" << std::endl;  // Output: (5, 1)

    return 0;
}
```

## Time Complexity

- **Push**: O(log n)
- **Pop**: O(log n)
- **Top**: O(1)
- **Empty**: O(1)
- **Size**: O(1)

## Additional Notes

- The `priority_queue` is implemented as a binary heap.
- Elements are stored in a complete binary tree structure.
- It is important to choose the correct comparison function to achieve desired behavior (max-heap or min-heap).
