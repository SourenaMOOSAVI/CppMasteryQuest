# Memory Mastery

Welcome to Week 3 of the CppMasteryQuest! This week is all about understanding how `C++` handles memory — from allocation to ownership, cache behavior, and smart pointer internals.

In real-world systems (and interviews), strong memory fundamentals separate an average developer from a true C++ engineer.
Here, you’ll go beyond using new/delete — you’ll understand when and why memory is allocated, freed, and optimized.
By the end of this week, you’ll implement a Custom Smart Pointer and Memory Pool Manager to solidify your understanding of memory management in C++.

---

## Concepts Covered

1. **RAII (Resource Acquisition Is Initialization)**
    RAII is a core C++ idiom where resource allocation is tied to object lifetime. When an object is created, it acquires resources (like memory), and when it goes out of scope, it releases them automatically. RAII ensures resources are properly released when an object goes out of scope. It’s the foundation of modern memory safety in C++.

    **Example:**

    ```cpp
    #include <iostream>
    #include <fstream>

    class FileRAII {
        std::ofstream file_;
    public:
        explicit FileRAII(const std::string& path) : file_(path) {
            if (!file_) throw std::runtime_error("Failed to open file");
        }
        ~FileRAII() { file_.close(); }
    };

    int main() {
        try {
            FileRAII f("output.txt");
            // File automatically closed at end of scope
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    ```

    **Interview Mini Q&A:**
    * ❓ *What problem does RAII solve that manual resource management does not?*
      * RAII ensures deterministic resource cleanup using destructors, even when exceptions occur — unlike manual `new`/`delete` or `open`/`close` calls.
    * ❓ *How does RAII relate to exception safety?*
      * RAII helps maintain exception safety by ensuring that resources are released even if an exception occurs, as destructors are called during stack unwinding.
    * ❓ *Can RAII be applied to non-memory resources?*
      * Yes, RAII can manage any resource, such as file handles, network connections, or mutex locks, ensuring they are properly released when no longer needed.

    **Types of interview questions you might face:**
    * Explain how RAII works with examples.
    * Discuss the benefits of RAII in resource management.
    * Analyze code snippets for proper RAII usage.

2. **Dynamic Allocation and Alignment**
    Dynamic allocation happens on the heap using `new`, `delete`, or allocators. Understanding how memory is allocated on the heap, including alignment requirements, is crucial for performance and correctness. Proper alignment ensures data fits CPU boundaries for optimal access.

    **Example:**

    ```cpp
    #include <iostream>
    #include <new> // for std::align_val_t

    struct alignas(64) CacheFriendly {
        double data[8];
    };

    int main() {
        CacheFriendly* ptr = new CacheFriendly;
        std::cout << "Address: " << ptr << '\n';
        delete ptr;
    }
    ```

    **Interview Mini Q&A:**
    * ❓ *What is memory alignment and why is it important?*
      * Memory alignment refers to arranging data in memory according to certain boundaries (e.g., 4-byte, 8-byte). Proper alignment improves access speed and prevents hardware exceptions on some architectures.
    * ❓ *Why can misaligned data cause performance penalties?*
      * Misaligned access may span multiple cache lines or cause hardware exceptions on certain architectures.
    * ❓ *How does `new` differ from `malloc`?*
      * `new` calls constructors and returns typed pointers, while `malloc` only allocates raw memory without initialization. `new` also throws exceptions on failure, whereas `malloc` returns `nullptr`.
    * ❓ *What are memory leaks and how can they be prevented?*
      * Memory leaks occur when allocated memory is not freed. They can be prevented using RAII, smart pointers, and careful resource management.

    **Types of interview questions you might face:**
    * Explain dynamic memory allocation in C++.
    * Discuss the importance of memory alignment.
    * Identify potential memory leaks in code snippets.