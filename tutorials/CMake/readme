# CMake Cheat Sheet

#### 1. **Basic Commands**
- **Generate Build Files**:  
  ```bash
  cmake .
  ```
- **Specify Build Directory**:  
  ```bash
  mkdir build
  cd build
  cmake ..
  ```
- **Build Project**:  
  ```bash
  make
  ```
- **Run Program**:  
  ```bash
  ./my_program
  ```

#### 2. **Basic `CMakeLists.txt` Structure**
```cmake
cmake_minimum_required(VERSION 3.10)  # Minimum CMake version
project(MyProject)                    # Project name

add_executable(my_program main.cpp)   # Create executable
```

#### 3. **Variables**
- **Set a Variable**:  
  ```cmake
  set(MY_VAR "value")
  ```
- **Use a Variable**:  
  ```cmake
  ${MY_VAR}
  ```

#### 4. **Targets**
- **Add Executable**:  
  ```cmake
  add_executable(my_program main.cpp)
  ```
- **Add Library**:  
  ```cmake
  add_library(mylib mylib.cpp)
  ```
- **Link Library to Executable**:  
  ```cmake
  target_link_libraries(my_program PRIVATE mylib)
  ```

#### 5. **Find Packages**
- **Find and Link External Library (e.g., OpenCV)**:
  ```cmake
  find_package(OpenCV REQUIRED)
  target_link_libraries(my_program PRIVATE ${OpenCV_LIBS})
  ```

#### 6. **Compiler Options**
- **Set Compiler Flags**:  
  ```cmake
  target_compile_options(my_program PRIVATE -Wall -Wextra)
  ```

#### 7. **Build Configurations**
- **Specify Build Type**:  
  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  ```
- **Common Build Types**:
  - `Release`: Optimized for performance.
  - `Debug`: Includes debugging information.

#### 8. **Install Targets**
- **Install Executable**:
  ```cmake
  install(TARGETS my_program DESTINATION /usr/local/bin)
  ```

#### 9. **Custom Commands**
- **Add Post-Build Command**:
  ```cmake
  add_custom_command(TARGET my_program POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:my_program> /path/to/destination)
  ```

#### 10. **Header File Directories**
- **Include Directories**:
  ```cmake
  target_include_directories(my_program PRIVATE include/)
  ```

#### 11. **Options**
- **Define an Option**:
  ```cmake
  option(BUILD_TESTS "Build the tests" ON)
  ```

#### 12. **Multiple Source Files**
- **Add Multiple Source Files**:
  ```cmake
  add_executable(my_program main.cpp utils.cpp helper.cpp)
  ```

#### 13. **Subdirectories**
- **Include Subdirectory**:
  ```cmake
  add_subdirectory(src)
  ```

#### 14. **Cross-Compilation**
- **Toolchain File**:
  ```bash
  cmake -DCMAKE_TOOLCHAIN_FILE=path/to/toolchain_file.cmake ..
  ```

#### 15. **Testing**
- **Add Testing**:
  ```cmake
  enable_testing()
  add_test(NAME my_test COMMAND my_program)
  ```

---

### Example `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Add library
add_library(mylib mylib.cpp)

# Add executable
add_executable(my_program main.cpp)

# Link library
target_link_libraries(my_program PRIVATE mylib)

# Compiler options
target_compile_options(my_program PRIVATE -Wall -Wextra)

# Install executable
install(TARGETS my_program DESTINATION bin)

# Set include directories
target_include_directories(my_program PRIVATE include/)
```
