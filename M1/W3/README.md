# Memory Management: Custom Smart Pointer and Memory Pool Manager

Build a custom smart pointer (similar to `std::shared_ptr`) and a **memory pool manager** to deeply understand memory management in C++. This project involves implementing *dynamic allocation*, *reference counting*, and a *memory pool* for efficient allocation and deallocation of objects. It will help you master concepts like **RAII (Resource Acquisition Is Initialization)** and manual memory management while reducing the risk of leaks and *dangling pointers*.

## Concepts to Master

1. **Dynamic Memory Allocation**:
   Dynamic memory allocation in C++ allows you to allocate memory at runtime using operators like `new` and `delete`. This is essential for creating objects whose size or lifetime cannot be determined at compile time. However, improper management of dynamically allocated memory can lead to memory leaks and undefined behavior.

2. **RAII (Resource Acquisition Is Initialization)**:
*Resource Acquisition Is Initialization* or RAII, is a C++ programming technique which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object. This ensures that resources are properly cleaned up even if an exception is thrown.  
C++11 introduced smart pointers like `std::unique_ptr` and `std::shared_ptr`, which use RAII to manage dynamic memory.  
`std::unique_ptr` is a smart pointer that owns a resource exclusively. It ensures that the resource is released when the `std::unique_ptr` goes out of scope.  
In the context of resource management there is a technique called **Reference Counting**. It is used to manage the lifetime of shared resources. It involves keeping a counter that tracks the number of owners of a resource. When the counter drops to zero, the resource is released. `std::shared_ptr` is a smart pointer that uses reference counting to manage shared ownership of a resource.

3. **Custom Smart Pointers**:
Custom smart pointers are user-defined classes designed to manage resources like memory, file handles, or network connections. They work similarly to standard smart pointers (`std::unique_ptr`, `std::shared_ptr`), but they allow for more control and customization over resource management behaviors.  
Creating a custom smart pointer involves defining a class that handles resource acquisition and release, ensuring that resources are properly managed throughout the object's lifecycle. This can be useful when the default behavior of standard smart pointers doesn't fit the specific needs of your application.
4. **Memory Pool Management**:
A memory pool, also known as a fixed-size block allocation, is a memory management technique that involves preallocating a large block of memory and then dividing it into smaller, fixed-size chunks. These chunks are then allocated and deallocated as needed by the application. The main goal of using a memory pool is to improve the performance of memory allocation and deallocation by reducing fragmentation and the overhead associated with dynamic memory allocation.  
While the concept of memory pools is not strictly classified into "types" within the C++ standard library, they can be categorized based on where the memory is allocated from:

    **a. Static Memory Pool**: Memory is preallocated at compile-time and resides in the global or static memory area. This type of memory pool does not grow or shrink during program execution.
    * **Usage**: Useful for embedded systems with fixed memory requirements.  

    **b. Heap-Based Memory Pool**: Memory is dynamically allocated from the heap at runtime. This type of memory pool can grow or shrink as needed, depending on the application's demands.
    * **Usage**: Common in applications where memory usage patterns are not known at compile time.

    **c. Stack-Based Memory Pool**: Memory is allocated on the stack, typically using `alloca()` or similar mechanisms. This type of memory pool is automatically reclaimed when the function call returns.
    * **Usage**: Suitable for short-lived allocations within a function's scope.
5. **The Rule of Five**:
The Rule of Five is a guideline in C++ that dictates that if a class needs a custom implementation of one of the following five special member functions, it likely needs custom implementations for all five. These functions manage the lifecycle of class objects and their resources:  
   a. **Destructor** (`~ClassName()`)  
   b. **Copy Constructor** (`ClassName(const ClassName& other)`)  
   c. **Copy Assignment Operator** (`ClassName& operator=(const ClassName& other)`)  
   d. **Move Constructor** (`ClassName(ClassName&& other) noexcept`)  
   e. **Move Assignment Operator** (`ClassName& operator=(ClassName&& other) noexcept`)  

Reasoning Behind the Rule:  
The Rule of Five ensures that resources like dynamic memory, file handles, or network connections are correctly managed when objects are copied or moved. If one of these functions is needed, it's usually because the class is managing a resource that requires special handling to avoid issues such as double deletion, memory leaks, or resource corruption.

## How to run the project

1. **Clone the repository**:
    Clone the repository to your local machine using the following command:

    ```sh
    git clone https://github.com/sourenamoosavi/custom-smart-pointer.git
    cd custom-smart-pointer
    ```

2. **Create the build directory**:

    ```sh
    mkdir build && cd build
    ```

3. **Build the project**:
    Ensure you have a C++ compiler installed. Then, run the following command to compile the project:

    ```sh
    cmake ..
    cmake --build .
    ```

4. **Run tests**:
    To ensure everything is working correctly, run the tests:

    ```sh
    cd build
    ./MemoryPoolTests
    ./SharedPtrTests
    ./WeakPtrTests
    ```
