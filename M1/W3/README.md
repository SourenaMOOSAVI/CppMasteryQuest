# Memory Mastery

Welcome to Week 3 of the CppMasteryQuest! This week is all about understanding how `C++` handles memory — from allocation to ownership, cache behavior, and smart pointer internals.

In real-world systems (and interviews), strong memory fundamentals separate an average developer from a true `C++` engineer.
Here, you’ll go beyond using `new`/`delete` — you’ll understand when and why memory is allocated, freed, and optimized.
By the end of this week, you’ll implement a Custom Smart Pointer and Memory Pool Manager to solidify your understanding of memory management in `C++`.

---

## Concepts Covered

1. **RAII (Resource Acquisition Is Initialization) :**

    RAII is a core `C++` idiom where resource allocation is tied to object lifetime. When an object is created, it acquires resources (like memory), and when it goes out of scope, it releases them automatically. RAII ensures resources are properly released when an object goes out of scope. It’s the foundation of modern memory safety in `C++`.

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

2. **Dynamic Allocation and Alignment :**

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
    * Explain dynamic memory allocation in `C++`.
    * Discuss the importance of memory alignment.
    * Identify potential memory leaks in code snippets.

3. **Smart Pointers Internals :**

    Smart pointers (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`) automate memory management by encapsulating raw pointers and managing their lifetimes. Understanding their internals helps in choosing the right smart pointer for the job and avoiding pitfalls like cyclic references.

    **Example:**

    ```cpp
    #include <iostream>
    #include <memory>

    struct Node {
        int value;
        std::shared_ptr<Node> next;
        Node(int val) : value(val), next(nullptr) {}
    };

    int main() {
        auto head = std::make_shared<Node>(1);
        head->next = std::make_shared<Node>(2);
        std::cout << head->value << " -> " << head->next->value << '\n';
    }
    ```

    **Interview Mini Q&A:**
    * ❓ *How does `std::shared_ptr` manage reference counting?*
      * `std::shared_ptr` maintains a control block that tracks the number of shared owners. When a new `shared_ptr` is created from an existing one, the count increments; when a `shared_ptr` is destroyed, the count decrements. When the count reaches zero, the managed object is deleted.
    * ❓ *What is a cyclic reference and how can it be avoided?*
      * A cyclic reference occurs when two or more `shared_ptr`s reference each other, preventing their memory from being freed. It can be avoided using `std::weak_ptr` to break the cycle.
    * ❓ *When should you use `std::unique_ptr` over `std::shared_ptr`?*
      * Use `std::unique_ptr` when you want exclusive ownership of a resource, as it has lower overhead and better performance than `std::shared_ptr`.

    **Types of interview questions you might face:**
    * Explain how smart pointers work in `C++`.
    * Discuss scenarios for using different types of smart pointers.
    * Analyze code for potential memory management issues with smart pointers.

4. **Custom Allocators and Memory Pooling :**

    Custom allocators allow fine-tuned control over memory allocation strategies, which can be customized for specific performance needs.. Memory pooling is a technique where a pool of pre-allocated memory blocks is maintained to reduce allocation overhead and fragmentation.

    **Example:**

    ```cpp
    #include <memory>
    #include <vector>

    template<typename T>
    struct SimpleAllocator {
        using value_type = T;

        T* allocate(std::size_t n) {
            std::cout << "Allocating " << n << " objects\n";
            return static_cast<T*>(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t) noexcept {
            ::operator delete(p);
        }
    };

    int main() {
        std::vector<int, SimpleAllocator<int>> v(10);
    }
    ```

    **Interview Mini Q&A:**
    * ❓ *What are the benefits of using custom allocators?*
      * Custom allocators can reduce fragmentation, improve cache locality, and optimize allocation/deallocation patterns for specific workloads.
    * ❓ *Why are custom allocators used in performance-critical systems?*
      * They minimize fragmentation, reduce system calls, and optimize cache usage.
    * ❓ *How does memory pooling improve performance?*
      * Memory pooling reduces the overhead of frequent allocations/deallocations by reusing pre-allocated memory blocks, leading to faster memory operations and reduced fragmentation.
    * ❓ *When would you consider implementing a custom allocator?*
      * When standard allocators do not meet performance requirements, such as in high-frequency allocation scenarios or when specific alignment or locality optimizations are needed.

    **Types of interview questions you might face:**
    * Explain the concept of custom allocators in C++.
    * Discuss the advantages of memory pooling.
    * Analyze scenarios where custom memory management strategies are beneficial.

---

## Challenge — Memory Manager Toolkit

You’ll build your own memory management mini-library with three modules:

1. **Custom Smart Pointer `MySharedPtr<T>`**:
    * Implement a reference-counted smart pointer.
    * Support copy/move semantics and proper cleanup.
    * (Optional) Add weak reference support.
2. **Memory Pool Manager**:
    * Manage a fixed-size memory block pool.
    * Support allocate/release operations.
    * Optionally integrate with your allocator.
3. **`SimpleAllocator<T>`**:
    * Implement a minimal custom allocator compatible with STL containers.
    * Track allocation and deallocation calls.
