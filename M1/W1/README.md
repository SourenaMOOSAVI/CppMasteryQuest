# Generic Data Structure Library

Design and implement a small library of generic data structures in `C++` that utilizes templates, ensures const correctness, and leverages smart pointers for memory management. You’ll implement a generic dynamic array (`DynamicArray<T>`) and a generic linked list (`LinkedList<T>`).  
LinkedList and DynamicArray are already implemented to give a head start. The concepts you will master working on these Data Structures are listed in the next section. There is also a section "Further Improvements" that would give you an idea how to move deeper with the concepts covered in the simple version of the code.

## Concepts to master

1. **Templates**: A template is a construct that generates an ordinary type or function at compile time based on arguments the user supplies for the template parameters. Templates allow writing generic and reusable code. For example, the `dynamicArray<T>` and `LinkedList<T>` classes in the current project are implemented as templates to support any data type.

2. **Const Correctness**: The `const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it. Ensuring const correctness in your code helps prevent accidental modifications and makes your code more predictable and easier to understand. For example, member functions that do not modify the state of the object should be marked as `const`.

3. **Smart Pointers**: In modern C++ programming, the Standard Library includes *smart pointers*, which are used to help ensure that programs are free of memory and resource leaks and are exception-safe. Smart pointers are defined in the `std` namespace in the `<memory>` header file. They are crucial to the RAII or *Resource Acquisition Is Initialization* programming idiom.  
   *When to use smart pointers?* Pretty much every time you can. They completely automate the memory management which is great since you don't need to be worried about accidental memory leaks. You just need to keep in mind that compared to *raw pointers*, *smart pointers* tend to present some overhead (especially *shared pointers* because of their reference counting system). Between `unique` pointer and `shared` pointer, you should privilege `unique` pointer because of its lower overhead.

4. **`std::move()`**: It **casts** (interprets) an object into an **rvalue reference** (`T&&`) to signal that the object's resources can be **transferred**. This is useful for optimizing performance by avoiding unnecessary copies. For example:

    ```cpp
    #include <iostream>
    #include <string>

    int main() {
        std::string str = "Hello, World!";
        std::string movedStr = std::move(str);

        std::cout << "Original string after move: \"" << str << "\"" << std::endl; // Likely empty
        std::cout << "Moved-to string: \"" << movedStr << "\"" << std::endl;

        return 0;
    }
    ```

    Explanation:

    * `std::move(str)` casts `str` into an rvalue reference (`std::string&&`), signaling that its internal resources can be transferred.
    * The move constructor of `std::string` transfers the contents of `str` to `movedStr`.
    * After the move, `str` is left in a valid but unspecified state (likely empty).

## Further improvements

### Add Tests for Edge Cases

* Adding or removing from an empty list.
* Removing a value that does not exist in the list.
* Handling duplicate values.
* Traversing or printing an empty list.
* Stress testing with a large number of nodes.
* Checking const-correctness with const `LinkedList<T>`.

### Optimize Both Classes

1. LinkedList Optimizations:

   * Avoid redundant memory allocations or deallocations.
   * Reduce the complexity of traversal or operations where possible.
   * Use smart pointers efficiently to ensure optimal memory management.

2. DynamicArray Optimizations:

   * Optimize resizing logic by minimizing unnecessary memory reallocations.
   * Use move semantics to avoid deep copies when expanding the array.

### Use `std::shared_ptr` in `LinkedList<T>` and Compare with `std::unique_ptr`

### Refactor Both Data Structures to Ensure Adherence to the Rule of Five

#### What is the rule of five?

It’s a C++ design principle that ensures proper resource management by implementing five special member functions:

1. Default constructor.
2. Destructor.
3. Copy constructor.
4. Copy assignment operator.
5. Move constructor and move assignment operator.
