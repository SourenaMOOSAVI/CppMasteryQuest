# Core Language & Mechanics

*Mastery is not achieved through shortcuts, but through deliberate practice.*

Week 1 lays the foundation for mastering **modern C++**.  
This week, you’ll deepen your understanding of templates, const correctness, smart pointers, and move semantics — then apply them to build generic, safe, and efficient data structures.

---

## Objectives

By the end of Week 1, you will:

- Write **generic, reusable code** using templates.  
- Apply **const correctness** for safe and predictable APIs.  
- Manage resources with **RAII and smart pointers**.
- Implement **Rule of Five/Zero** and **move semantics**.  
- Build and benchmark custom **template-based data structures**.

---

## Study Flow

1. **Read** each concept section below carefully.  
2. **Implement** the mini-exercises along the way.  
3. **Complete** the final challenges.  
4. **Benchmark & Reflect** — measure how move semantics or ownership choices affect performance.

---

## 1️⃣ Templates

Templates allow writing generic code that works with any type. They are one of C++’s most powerful features.

### Learn

- Function and class templates  
- Template specialization  
- Type deduction and constraints (C++20 Concepts)

### Mini Q&A

- ❓ *What’s the difference between function overloading and templates?*  
  Function overloading defines multiple functions for different types.  
  Templates define a single generic blueprint instantiated at compile time.

- ❓ *What is template specialization?*  
  It provides a custom implementation for specific types.

### Mini Exercise

Implement a function template:

```cpp
template<typename T>
T max_of_three(const T& a, const T& b, const T& c) {
    return std::max(std::max(a, b), c);
}
```

Now extend it to accept a custom comparator.

---

## 2️⃣ Const Correctness

`const` ensures immutability and helps enforce clean, safe APIs.

### Learn

- `const` parameters and member functions
- `const` pointers vs. pointers to `const`
- `const` overloads

### Mini Q&A

- ❓ What’s the difference between `const int*`, `int* const`, and `const int* const`?
  See <a href="https://en.cppreference.com/w/cpp/language/cv.html" target="_blank" rel="noopener noreferrer">cppreference: const ↗</a>

- ❓ Why mark methods as `const`?
  They can be safely called on `const` objects.

### Mini Exercise

Mark every non-modifying method in your stack/queue as `const`.
Try calling them on `const` instances and observe what the compiler allows or rejects.

## 3️⃣ Smart Pointers & RAII

Smart pointers automate resource management through ownership semantics.

### Learn

- `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- RAII (Resource Acquisition Is Initialization)
- Rule of Five/Zero

### Guidelines

| Pointer Type | Ownership | Copyable | Use Case         |
| ------------ | --------- | -------- | ---------------- |
| `unique_ptr` | Exclusive | No       | Single ownership |
| `shared_ptr` | Shared    | Yes      | Shared ownership |
| `weak_ptr`   | Observer  | No       | Break cycles     |

### Mini Q&A

Implement a minimal `UniquePtr<T>` that supports:

- move constructor and assignment
- `operator*` and `operator->`

Then test with a small class that prints messages on construction/destruction.

## 4️⃣ Move Semantics & Rule of Five/Zero

Move semantics optimize performance by stealing resources from temporaries instead of copying them.

### Learn

- Copy vs. move constructors/assignments
- Lvalues vs. rvalues
- Rule of Five: destructor, copy/move ctor, copy/move assignment
- Rule of Zero: rely on RAII types when possible

| Concept          | When to Use                                 |
| ---------------- | ------------------------------------------- |
| **Rule of Five** | Manual resource management                  |
| **Rule of Zero** | Use smart pointers/containers for ownership |

### Mini Q&A

Implement a class `DynamicArray<T>` that:

- Implements Rule of Five
- Demonstrates move vs copy in logs
- Uses `std::move` to optimize reassignment

Then measure the time difference for copying vs. moving large arrays.

### Final Challenge: Build Template-Based Data Structures

1. Template-based Stack/Queue

    - Build `Stack<T>` and `Queue<T>` using templates.
    - Use `std::unique_ptr` internally for memory safety.
    - Ensure const correctness (`const` getters, etc.).

2. Template-based DynamicArray

    - Recreate a simplified `std::vector`.
    - Implement copy/move constructors and assignment operators.
    - Compare copy vs move performance for large data.

## Benchmark & Reflect

Profile your `DynamicArray` operations using large data sets.

Measure and compare:

- Copy vs Move construction
- Raw pointer vs `unique_ptr` memory usage
- Function call performance differences with and without `const`

Write down what you’ve learned — these observations become invaluable intuition later.

### References

- <a href="https://en.cppreference.com/w/cpp/language/templates" target="_blank" rel="noopener noreferrer">cppreference: Templates ↗</a>
- <a href="https://www.oreilly.com/library/view/effective-modern-c/9781491908419/" target="_blank" rel="noopener noreferrer">Effective Modern C++ — Items 1–11 ↗</a>
- <a href="https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines" target="_blank" rel="noopener noreferrer">ISO C++ Core Guidelines ↗</a>
