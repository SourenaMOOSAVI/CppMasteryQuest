# Core Language & Mechanics

The first week you should focus on mastering essential C++ features (including modern C++) that every intermediate developer must internalize before moving to advanced topics. We’ll explore templates, const correctness, smart pointers, and move semantics, and then apply them to implement generic data structures.

---

## Concepts to master

1. **Templates**: 

    A template is a construct that generates an ordinary type or function at compile time based on arguments the user supplies for the template parameters. Templates allow writing generic and type-agnostic code. Instead of rewriting data structures (e.g., `stack`, `queue`) for `int`, `double`, or `std::string`, we can write one generic implementation that works with any type.

   * Function templates
   * Class templates
   * Template specialization
   * Template deduction

   **Interview Mini Q&A:**

   * ❓ *What is the difference between function overloading and function templates?*
     * Function overloading defines multiple versions of a function with different parameter types. Function templates define a single generic version that the compiler instantiates for specific types.
   * ❓ *What is template specialization?*
     * Template specialization lets you define a custom implementation of a template for a specific type (e.g., optimizing behavior for `bool`).

   **Types of interview questions you might face:**

   * Implement a generic data structure (e.g., ``stack``, ``queue``, ``linked list``) using templates.
   * Debug or fix template-related compilation errors.
   * Explain why templates can increase compile-time complexity but improve runtime efficiency.

2. **Const Correctness**:

   The `const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it. Ensuring const correctness in your code helps prevent accidental modifications and APIs safer and easier to reason about. For example, member functions that do not modify the state of the object should be marked as `const`.

   * `const` parameters → avoid accidental modification
   * `const` member functions → enforce read-only access
   * Pointers to const vs. const pointers

   **Interview Mini Q&A:**
   * ❓ *What is the difference between `const int *ptr`, `int* const ptr`, and `const int* const ptr`?*
     * `const int* ptr` → pointer to a constant integer (the integer value cannot be changed through the pointer).
     * `int* const ptr` → constant pointer to an integer (the pointer itself cannot be changed to point to another address).
     * `const int* const ptr` → constant pointer to a constant integer (neither the pointer nor the integer value can be changed).

   * ❓ *Why should member functions that do not modify the object be declared const?*
     * It allows calling them on const objects and improves API safety.

   **Types of interview questions you might face:**
   * Identify whether a method should be marked `const`.
   * Spot errors related to const-correctness in given code.
   * Discuss how const correctness affects function overloading.

3. **Smart Pointers**:

    In modern C++ programming, the Standard Library includes *smart pointers* (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`), which are used to help ensure that programs are free of memory and resource leaks and are exception-safe. Smart pointers are defined in the `std` namespace in the `<memory>` header file. They are crucial to the RAII or *Resource Acquisition Is Initialization* programming idiom.

   * `std::unique_ptr` → exclusive ownership, cannot be copied, only moved.
   * `std::shared_ptr` → shared ownership, reference counting, can be copied.
   * `std::weak_ptr` → non-owning observer.
   * Rule of Five/Zero → ensuring correct resource management.  

   *When to use smart pointers?* Use them to express ownership semantics when you need dynamic allocation. Smart pointers automate memory management and help prevent leaks, but they're not a universal solution.

   **Guidelines :**
   * Use `unique_ptr` for exclusive ownership—it has minimal overhead (one indirection)
   * Use `shared_ptr` only when you truly need shared ownership—it has significant overhead from atomic reference counting and the control block
   * Use raw pointers or references for non-owning access (observers/borrowers)
   * Prefer `unique_ptr` over `shared_ptr` whenever possible

   **Performance considerations**: In low-latency and high-performance contexts, even unique_ptr's overhead can matter. Consider:
   * Avoiding dynamic allocation entirely (stack allocation, value semantics)
   * Custom allocators (arena/pool allocators for bulk allocations)
   * Raw pointers with clear ownership conventions in hot paths
   * Profiling first—premature optimization is real, but so is death by a thousand allocations

   Smart pointers are excellent for general-purpose code, but in performance-critical systems, the best pointer is often no pointer at all.

   **Interview Mini Q&A:**
   * ❓ *What is the difference between `std::unique_ptr` and `std::shared_ptr` ?*
     * `std::unique_ptr` enforces sole ownership and cannot be copied (only moved). `std::shared_ptr` allows multiple owners via reference counting.
   * ❓ *Why does `std::weak_ptr` exist?*
     * To break cyclic dependencies between `std::shared_ptr` objects (avoiding memory leaks).

   **Types of interview questions you might face:**
   * Implement a simplified version of `unique_ptr` or `shared_ptr`.
   * Explain how reference counting works in `shared_ptr`.
   * Debug memory leak issues raw pointers vs. smart pointers.

4. **Move Semantics & Rule of Five/Zero**: 

    `C++11` introduced move semantics to optimize performance by avoiding deep copies of temporary objects. It **casts** (interprets) an object into an **rvalue reference** (`T&&`) to signal that the object's resources can be **transferred**. This is useful for optimizing performance by avoiding unnecessary copies.

   * Copy vs. move constructors
   * Copy vs. move assignment operators
   * Rule of Five → when to define destructor, copy/move ctor, copy/move assignment
   * Rule of Zero → prefer RAII types and let the compiler generate defaults

   **Interview Mini Q&A:**
   * ❓ *What is the difference between lvalues and rvalue?*
     * Lvalues have a persistent memory address (like variables), while rlavules are temporary values (like `x + y`).
   * ❓ *Why do we need move constructors if we already have copy constructors?*
     * Copying is expensive for large objects (allocates new memory and copies data). Move constructors “steal” resources from temporaries, improving performance.

   **Types of interview questions you might face:**
   * Implement a class with correct Rule of Five behavior.
   * Demonstrate how move semantics improve efficiency with large vectors.
   * Identify when the compiler implicitly generates move/copy functions.

---

## Challenges

Using the concepts above, implement the following **generic data structures:**

1. **Template-based Stack/Queue**: Create a stack and queue class using templates. Ensure proper const-correctness and implement RAII principles for memory management.

   * Implement the `queue<T>` as a linked-list-based queue.
   * Implement `push`, `pop`, `top` (for stack) / `front`, `back` (for queue), and `isEmpty` and `size` methods.
   * Ensure the above methods are `const`-correct where applicable.
   * Use `std::unique_ptr` or `std::shared_ptr` for internal storage to manage dynamic memory safely.
   * Ensure that member functions that do not modify the state are marked as `const`.

2. **Template-based DynamicArray**

   * Recreate a minimal version of `std::vector`.
   * Implement copy constructor, move constructor, and assignment operators (Rule of Five).
   * Compare performance between copy and move operations.

---

## Learning Outcomes

By the end of Week 1, you should:

* Understand how to write generic, reusable C++ code with templates
* Apply `const` correctness to create safe, predictable APIs.
* Manage resources automatically with smart pointers and RAII.
* Appreciate the performance benefits of move semantics and follow the Rule of Five/Zero.
* Be able to answer common interview questions around these concepts confidently.
* Gain hands-on experience by building non-trivial data structures that reinforce these concepts.
