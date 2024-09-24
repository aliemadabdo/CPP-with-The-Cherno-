# Smart Pointers Cheat Sheet

## Table of Contents

1. [Introduction](#introduction)
2. [Types of Smart Pointers](#types-of-smart-pointers)
   - [std::unique_ptr](#stdunique_ptr)
   - [std::shared_ptr](#stdshared_ptr)
   - [std::weak_ptr](#stdweak_ptr)
3. [Best Practices](#best-practices)
4. [Additional Resources](#additional-resources)

## Introduction

Smart pointers are a part of the C++ Standard Library that provide automatic and safe memory management. They help prevent memory leaks and dangling pointers by ensuring that memory is properly deallocated when it is no longer needed.

## Types of Smart Pointers

### `std::unique_ptr`

- **Description**: 
  - Represents exclusive ownership of a dynamically allocated object.
  - The object is destroyed when the `std::unique_ptr` goes out of scope.
  - Cannot be copied, only moved.

- **Syntax**:
  ```cpp
  std::unique_ptr<Type> ptr(new Type());
  ```

- **Common Operations**:
  ```cpp
  // Create a unique pointer
  std::unique_ptr<int> ptr1 = std::make_unique<int>(10);

  // Access the underlying object
  *ptr1 = 20;

  // Transfer ownership
  std::unique_ptr<int> ptr2 = std::move(ptr1);

  // Release ownership without deleting
  int* rawPtr = ptr2.release();

  // Reset the unique pointer to a new object
  ptr2.reset(new int(30));
  ```

- **Notes**:
  - Use `std::make_unique` for exception safety and simplicity.
  - Ensure no other pointers access the object once ownership is transferred.

### `std::shared_ptr`

- **Description**:
  - Represents shared ownership of a dynamically allocated object.
  - The object is destroyed when the last `std::shared_ptr` owning it is destroyed or reset.
  - Can be copied and assigned.

- **Syntax**:
  ```cpp
  std::shared_ptr<Type> ptr(new Type());
  ```

- **Common Operations**:
  ```cpp
  // Create a shared pointer
  std::shared_ptr<int> ptr1 = std::make_shared<int>(10);

  // Access the underlying object
  *ptr1 = 20;

  // Copy shared pointer
  std::shared_ptr<int> ptr2 = ptr1;

  // Check the number of owners
  std::cout << "Use count: " << ptr1.use_count() << std::endl;

  // Reset the shared pointer
  ptr1.reset();
  ```

- **Notes**:
  - Use `std::make_shared` to avoid multiple allocations and for exception safety.
  - Be cautious of cyclic references, which can cause memory leaks.

### `std::weak_ptr`

- **Description**:
  - Provides a non-owning "weak" reference to an object managed by `std::shared_ptr`.
  - Used to break cyclic dependencies in `std::shared_ptr`.

- **Syntax**:
  ```cpp
  std::weak_ptr<Type> weakPtr(sharedPtr);
  ```

- **Common Operations**:
  ```cpp
  // Create a weak pointer from a shared pointer
  std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
  std::weak_ptr<int> weakPtr(sharedPtr);

  // Convert weak pointer to shared pointer
  if (auto lockedPtr = weakPtr.lock()) {
      std::cout << "Value: " << *lockedPtr << std::endl;
  } else {
      std::cout << "Object has been deleted" << std::endl;
  }
  ```

- **Notes**:
  - `weak_ptr` does not affect the reference count of the managed object.
  - Use `lock()` to obtain a `shared_ptr` and check if the object still exists.
  - After the object is deleted, all std::weak_ptrs that were observing this object become "expired."
  - An expired `std::weak_ptr` no longer points to a valid object, and calling `lock()` on it will return a `std::shared_ptr` that is nullptr.

## Best Practices

1. **Prefer `std::unique_ptr`** for sole ownership and when no shared ownership is required.
2. **Use `std::shared_ptr`** when ownership needs to be shared across multiple owners.
3. **Avoid cyclic dependencies** when using `std::shared_ptr`, use `std::weak_ptr` to mitigate this issue.

## Additional Resources

- [C++ Reference for `std::unique_ptr`](https://en.cppreference.com/w/cpp/memory/unique_ptr)
- [C++ Reference for `std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr)
- [C++ Reference for `std::weak_ptr`](https://en.cppreference.com/w/cpp/memory/weak_ptr)
