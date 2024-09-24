# C++ String Cheat Sheet

## Table of Contents

1. [Basic Operations](#basic-operations)
   - [Initialization](#initialization)
   - [Concatenation](#concatenation)
   - [Access Characters](#access-characters)

2. [Modifying Strings](#modifying-strings)
   - [Append](#append)
   - [Insert](#insert)
   - [Erase](#erase)
   - [Replace](#replace)

3. [Finding and Substring](#finding-and-substring)
   - [Find](#find)
   - [Substring](#substring)

4. [String Comparison](#string-comparison)
   - [Compare](#compare)
   - [Lexicographical Comparison](#lexicographical-comparison)

5. [String Size and Capacity](#string-size-and-capacity)
   - [Length](#length)
   - [Capacity](#capacity)
   - [Resize](#resize)

6. [String Conversion](#string-conversion)
   - [To C-string](#to-c-string)
   - [From C-string](#from-c-string)

7. [Other Useful Methods](#other-useful-methods)
   - [Clear](#clear)
   - [Empty](#empty)
   - [Trim](#trim)
   - [To Upper/Lower Case](#to-upperlower-case)

---

## Basic Operations

### Initialization

```cpp
std::string str1 = "Hello";
std::string str2("World");
std::string str3(5, 'a'); // "aaaaa"
```

### Concatenation

```cpp
std::string str = "Hello" + std::string(" World");  // "Hello World"
```

### Access Characters

```cpp
char ch = str[0];   // 'H'
char ch2 = str.at(1); // 'e'
```

## Modifying Strings

### Append

```cpp
str.append("!!!");     // "Hello World!!!"
str += "!!!";          // "Hello World!!!!"
```

### Insert

```cpp
str.insert(5, " my");  // "Hello my World!!!!"
```

### Erase

```cpp
str.erase(5, 3);       // "Hello World!!!!"
```

### Replace

```cpp
str.replace(6, 5, "C++"); // "Hello C++!!!!"
```

## Finding and Substring

### Find

```cpp
size_t pos = str.find("C++"); // Position of "C++" or std::string::npos
```

### Substring

```cpp
std::string substr = str.substr(6, 3); // "C++"
```

## String Comparison

### Compare

```cpp
bool isEqual = (str == "Hello C++!!!!");  // true if equal
```

### Lexicographical Comparison

```cpp
bool isLess = (str < "Hello D++!!!!"); // true if less
```

## String Size and Capacity

### Length

```cpp
size_t len = str.length(); // or str.size()
```

### Capacity

```cpp
size_t cap = str.capacity();
```

### Resize

```cpp
str.resize(10); // Resize to 10 characters
```

## String Conversion

### To C-string

```cpp
const char* cstr = str.c_str();
```

### From C-string

```cpp
std::string strFromCStr(cstr);
```

## Other Useful Methods

### Clear

```cpp
str.clear(); // Empty the string
```

### Empty

```cpp
bool isEmpty = str.empty(); // true if empty
```

### Trim

```cpp
// Remove leading/trailing spaces manually or use a library
```

### To Upper/Lower Case

```cpp
// Convert characters manually or use libraries like Boost
```
