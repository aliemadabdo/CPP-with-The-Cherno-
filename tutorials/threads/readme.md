# Threads Cheat Sheet

A quick reference guide for working with threads in C++.

## Table of Contents
1. [Creating Threads](#1-creating-threads)
2. [Joining and Detaching Threads](#2-joining-and-detaching-threads)
3. [Passing Arguments to Threads](#3-passing-arguments-to-threads)
4. [Thread Synchronization](#4-thread-synchronization)
   - [Mutex](#mutex)
   - [Lock Guard](#lock-guard)
   - [Unique Lock](#unique-lock)
   - [Condition Variables](#condition-variables)
5. [Thread Safety](#5-thread-safety)
6. [Thread IDs and Hardware Concurrency](#6-thread-ids-and-hardware-concurrency)
7. [Thread Management Tips](#7-thread-management-tips)

---

## 1. Creating Threads

You can create a new thread by passing a function or callable object to the `std::thread` constructor.

```cpp
#include <thread>

void task() {
    // Do some work
}

int main() {
    std::thread t1(task);  // Create a thread running 'task'
    t1.join();             // Wait for thread to finish
}
```

## 2. Joining and Detaching Threads

- **Join**: Blocks until the thread finishes execution.
- **Detach**: The thread continues execution independently.

```cpp
std::thread t1(task);

// Wait for thread to complete
t1.join();  

// Allow the thread to run independently
t1.detach(); 
```

- **Note**: A thread must be either joined or detached before it goes out of scope, otherwise it will cause an exception.

## 3. Passing Arguments to Threads

You can pass arguments to a thread function in two ways:

### By Value:
```cpp
void task(int x) {
    // Do something with x
}

int main() {
    std::thread t1(task, 5);  // Pass 5 by value
    t1.join();
}
```

### By Reference:
```cpp
void task(int& x) {
    // Modify x
}

int main() {
    int value = 10;
    std::thread t1(task, std::ref(value));  // Pass by reference
    t1.join();
}
```

## 4. Thread Synchronization

When multiple threads access shared data, synchronization is necessary to prevent data races.

### Mutex
A **mutex** is used to ensure only one thread can access a resource at a time.

```cpp
#include <mutex>

std::mutex mtx;

void task() {
    std::lock_guard<std::mutex> lock(mtx);
    // Safe access to shared resource
}
```

### Lock Guard
A **lock guard** automatically manages the mutex, locking it on creation and unlocking it when the scope ends.

```cpp
std::lock_guard<std::mutex> guard(mtx);
```

### Unique Lock
A **unique lock** is more flexible than a lock guard, allowing manual locking/unlocking.

```cpp
std::unique_lock<std::mutex> lock(mtx);
lock.unlock();  // Manually unlock
```

### Condition Variables
Condition variables allow threads to wait for a condition to become true.

```cpp
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void task() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });  // Wait until ready is true
    // Proceed after notification
}

int main() {
    std::thread t1(task);
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();  // Notify waiting thread
    t1.join();
}
```

## 5. Thread Safety

- Use **mutexes** or **atomic** operations to avoid data races.
- Use **std::atomic** for simple shared variables (e.g., counters, flags).

```cpp
#include <atomic>

std::atomic<int> counter(0);

void increment() {
    counter++;  // Atomic increment, no need for a mutex
}
```

## 6. Thread IDs and Hardware Concurrency

### Get Current Thread ID:
```cpp
std::thread::id this_id = std::this_thread::get_id();
```

### Get Number of Hardware Threads:
```cpp
unsigned int n = std::thread::hardware_concurrency();
```

This function returns the number of concurrent threads supported by the hardware.

## 7. Thread Management Tips

- Always **join** or **detach** a thread before it goes out of scope.
- Use **lock guards** or **unique locks** to avoid deadlocks.
- Minimize shared data between threads for better scalability.
- Use **atomic** operations when possible for simple data synchronization.
- Beware of potential **deadlocks** when using multiple mutexes; try to avoid locking multiple mutexes in different orders.

---

This cheat sheet provides a quick overview of threading in C++. For more complex scenarios, consider using thread pools or higher-level concurrency frameworks.