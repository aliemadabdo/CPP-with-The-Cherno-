# Files Cheat Sheet

1. **Introduction to File Handling in C++**
    - Overview of File Handling
    - File Streams in C++
  
2. **Basic File Operations**
    - Opening Files
    - Closing Files
    - Checking File Open Status

3. **Reading from Files**
    - Reading Line by Line
    - Reading Word by Word
    - Reading Character by Character
  
4. **Writing to Files**
    - Writing Text to Files
    - Appending to Files
    - Error Handling while Writing

5. **Binary File Operations**
    - Writing to Binary Files
    - Reading from Binary Files

6. **File Position and Seeking**
    - Using `.seekg()` and `.seekp()`
    - Reading/Writing from a Specific Position in Files

7. **File Modes and Flags**
    - `std::ios::in`, `std::ios::out`, `std::ios::app`, and More
    - Combining File Modes

8. **Error Handling and Best Practices**
    - Checking File Stream Status
    - Handling Common File IO Errors
    - Best Practices for Safe File Handling

9. **Working with Large Files**
    - Memory Mapping for File Access
    - Handling Large File Data in Chunks

10. **Case Studies and Examples**
    - Simple Text File Reader/Writer
    - Config File Parser
    - Log File System Implementation
    - Binary Data Storage Example

11. **Advanced Topics in File Handling**
    - File Locking Mechanisms
    - File Compression and Decompression (zlib, etc.)
    - Serialization and Deserialization (Storing Complex Data)

---

Working with files in C++ is commonly done using file streams, which are part of the `<fstream>` library. C++ provides three types of file streams for handling files:

1. **`ifstream`**: Input file stream used for reading data from files.
2. **`ofstream`**: Output file stream used for writing data to files.
3. **`fstream`**: General file stream capable of both reading from and writing to files.

### 1. **Basic Steps for File Handling in C++**

1. **Include the `<fstream>` library**.
2. **Create a file stream object**.
3. **Open the file using the `.open()` method or by passing the filename to the constructor**.
4. **Check if the file is open using `.is_open()`**.
5. **Perform read/write operations**.
6. **Close the file using `.close()`**.

### 2. **Opening a File**

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile;  // For reading
    std::ofstream outputFile; // For writing

    inputFile.open("input.txt"); // Open file for reading
    outputFile.open("output.txt"); // Open file for writing

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    // Perform file operations here

    inputFile.close();
    outputFile.close();

    return 0;
}
```

### 3. **Reading from a File**

You can read from a file using different techniques such as reading word by word, line by line, or character by character.

#### Reading Line by Line

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}
```

#### Reading Word by Word

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::string word;

    if (inputFile.is_open()) {
        while (inputFile >> word) {
            std::cout << word << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}
```

### 4. **Writing to a File**

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        outputFile << "This is a line of text.\n";
        outputFile << "Writing more text to the file.\n";
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    return 0;
}
```

### 5. **Appending to a File**

To append data to an existing file, open the file with the `std::ios::app` flag.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt", std::ios::app); // Open file in append mode

    if (outputFile.is_open()) {
        outputFile << "Appending new data to the file.\n";
        outputFile.close();
    } else {
        std::cerr << "Unable to open file for appending." << std::endl;
    }

    return 0;
}
```

### 6. **Binary File Operations**

C++ can also handle binary files (e.g., images, serialized objects, etc.). You need to use the `std::ios::binary` mode when opening the file.

#### Writing to a Binary File

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream binaryFile("data.bin", std::ios::binary);

    if (binaryFile.is_open()) {
        int number = 123456;
        binaryFile.write(reinterpret_cast<char*>(&number), sizeof(number));
        binaryFile.close();
    } else {
        std::cerr << "Unable to open binary file for writing." << std::endl;
    }

    return 0;
}
```

#### Reading from a Binary File

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream binaryFile("data.bin", std::ios::binary);

    if (binaryFile.is_open()) {
        int number;
        binaryFile.read(reinterpret_cast<char*>(&number), sizeof(number));
        std::cout << "Number from binary file: " << number << std::endl;
        binaryFile.close();
    } else {
        std::cerr << "Unable to open binary file for reading." << std::endl;
    }

    return 0;
}
```

### 7. **Error Handling**

When working with files, always check if the file stream was successfully opened, and handle errors appropriately.

```cpp
if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
}
```

### 8. **Common File Flags**

- **`std::ios::in`**: Open for reading.
- **`std::ios::out`**: Open for writing.
- **`std::ios::app`**: Append to the end of the file.
- **`std::ios::binary`**: Open in binary mode.
- **`std::ios::trunc`**: Truncate the file if it exists (default for `ofstream`).
- **`std::ios::ate`**: Open and seek to the end of the file immediately.

### 9. **Best Practices**

- Always check if the file was opened successfully with `.is_open()`.
- Close the file after performing operations using `.close()`.
- Use file streams (`ifstream`, `ofstream`, or `fstream`) instead of C-style file handling (e.g., `fopen`, `fclose`), as it is safer and integrates better with C++ features like RAII (Resource Acquisition Is Initialization).
- Use `std::ios::app` to append data to an existing file instead of overwriting it.
