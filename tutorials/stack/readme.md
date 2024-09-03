# C++ `std::stack` Cheat Sheet

## Table of Contents

1. [Introduction](#introduction)
2. [Creating a Stack](#creating-a-stack)
3. [Basic Operations](#basic-operations)
   - [Push](#push)
   - [Pop](#pop)
   - [Top](#top)
   - [Empty](#empty)
   - [Size](#size)
4. [Advanced Operations](#advanced-operations)
   - [Swap](#swap)
   - [Emplace](#emplace)
5. [Underlying Container](#underlying-container)
6. [Stack Use Cases](#stack-use-cases)
7. [Example Code](#example-code)

---

## Introduction

`std::stack` is a container adapter in C++ that provides a Last-In-First-Out (LIFO) data structure. It is built on top of other container classes like `std::deque`, `std::vector`, or `std::list`.

## Creating a Stack

```cpp
#include <stack>

std::stack<int> stack1;             // Default stack (based on deque)
std::stack<int, std::vector<int>> stack2; // Stack based on vector
std::stack<int, std::list<int>> stack3;   // Stack based on list
```

## Basic Operations

### Push

Add an element to the top of the stack.

```cpp
stack1.push(10);   // Stack: [10]
stack1.push(20);   // Stack: [10, 20]
```

### Pop

Remove the top element of the stack. **Does not return the removed element**.

```cpp
stack1.pop();      // Stack: [10]
```

### Top

Access the top element of the stack without removing it.

```cpp
int topElement = stack1.top();  // topElement = 10
```

### Empty

Check if the stack is empty.

```cpp
bool isEmpty = stack1.empty();  // isEmpty = false
```

### Size

Get the number of elements in the stack.

```cpp
size_t stackSize = stack1.size();  // stackSize = 1
```

## Advanced Operations

### Swap

Swap the contents of two stacks.

```cpp
std::stack<int> stackA, stackB;
stackA.push(1);
stackB.push(2);
stackA.swap(stackB);  // stackA contains 2, stackB contains 1
```

### Emplace

Construct and insert an element at the top of the stack.

```cpp
std::stack<std::pair<int, int>> stackPair;
stackPair.emplace(1, 2);  // Adds pair(1, 2) to the stack
```

## Underlying Container

You can specify the underlying container when creating a stack. By default, it uses `std::deque`.

```cpp
std::stack<int, std::vector<int>> stackVec; // Stack using vector
```

### Common Underlying Containers

- `std::deque` (default)
- `std::vector`
- `std::list`

## Stack Use Cases

- **Expression Evaluation**: Used in evaluating postfix (Reverse Polish Notation) expressions.
- **Undo Mechanism**: Useful for implementing undo features in applications.
- **Balanced Parentheses**: Check if parentheses/brackets are balanced in an expression.
- **Depth-First Search (DFS)**: In graph algorithms, stack is used to explore vertices.

## Example Code

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    // Output: 3 2 1

    return 0;
}
```