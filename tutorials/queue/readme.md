## **Queue Cheat Sheet in C++**

### **Table of Contents**
1. [Queue Basics](#queue-basics)
2. [Common Operations](#common-operations)
   - [Check if the Queue is Empty](#check-if-the-queue-is-empty)
   - [Get the Size of the Queue](#get-the-size-of-the-queue)
   - [Access the Front Element](#access-the-front-element)
   - [Access the Back Element](#access-the-back-element)
   - [Add an Element to the Queue](#add-an-element-to-the-queue)
   - [Remove an Element from the Queue](#remove-an-element-from-the-queue)
3. [Usage Example](#usage-example)
4. [Key Points](#key-points)

---

### **Queue Basics**
- **Header File**: `#include <queue>`
- **Declaration**: 
  ```cpp
  std::queue<int> q; // A queue of integers
  ```

### **Common Operations**

#### **Check if the Queue is Empty**
```cpp
q.empty(); // Returns true if the queue is empty, false otherwise
```

#### **Get the Size of the Queue**
```cpp
q.size(); // Returns the number of elements in the queue
```

#### **Access the Front Element**
```cpp
q.front(); // Returns a reference to the front element of the queue
```

#### **Access the Back Element**
```cpp
q.back(); // Returns a reference to the back element of the queue
```

#### **Add an Element to the Queue**
```cpp
q.push(10); // Inserts the element '10' at the back of the queue
```

#### **Remove an Element from the Queue**
```cpp
q.pop(); // Removes the front element from the queue
```

### **Usage Example**
```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Inserting elements
    q.push(1);
    q.push(2);
    q.push(3);

    // Accessing elements
    std::cout << "Front element: " << q.front() << std::endl; // Output: 1
    std::cout << "Back element: " << q.back() << std::endl; // Output: 3

    // Removing elements
    q.pop(); // Removes 1
    std::cout << "Front element after pop: " << q.front() << std::endl; // Output: 2

    // Check size
    std::cout << "Queue size: " << q.size() << std::endl; // Output: 2

    // Check if empty
    if(q.empty()) {
        std::cout << "Queue is empty" << std::endl;
    } else {
        std::cout << "Queue is not empty" << std::endl;
    }

    return 0;
}
```

### **Key Points**
- **First-In-First-Out (FIFO)**: The first element added to the queue will be the first one removed.
- **Queue does not provide direct access to elements**: You can only access the front and back elements.
