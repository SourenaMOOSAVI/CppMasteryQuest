# Your Roadmap to Mastering Modern C++

> This is not a beginner’s tutorial.  
> This is a curated journey for the **intermediate C++ developer** ready to transcend syntax and truly **master modern C++**.

If you already understand the basics of classes, templates, and the STL but feel daunted by advanced features, high-performance patterns, or modern idioms, this repository is your **blueprint**.  
**CppMasteryQuest** is the structured path I would take today to evolve from an intermediate coder into a confident **C++ architect**.

Through hands-on challenges, deep dives into the standard library, and real-world projects, this roadmap helps you develop the intuition, craftsmanship, and fluency required to build professional-grade, high-performance software.

---

## Roadmap Overview

The **C++ Mastery Quest** is divided into six months.  
Each month focuses on specific topics, challenges, and projects that build on one another — from mastering fundamentals to building real-world systems.

---

### **Month 1: Mastering Fundamentals**

**Objective:** Strengthen your grasp of intermediate concepts and fill foundational gaps.

#### Weekly Themes

- **[Week 1: Core Language & Mechanics](https://github.com/SourenaMOOSAVI/CppMasteryQuest/blob/main/M1/W1/README.md#core-language--mechanics)**  
  Templates, const correctness, smart pointers, Rule of Five/Zero, and move semantics.  
  *Challenge:* Build template-based data structures (`stack`, `queue`, `dynamic array`) with RAII and const-correctness.

- **[Week 2: STL in Depth](https://github.com/SourenaMOOSAVI/CppMasteryQuest/blob/main/M1/W2/README.md#stl-in-depth)**  
  Containers, iterators, algorithms, lambdas, complexity analysis, and ranges (`C++20`).  
  *Challenge:* Build a **Data Analyzer** that ingests text/CSV files and computes stats using STL.

- **[Week 3: Memory Mastery](https://github.com/SourenaMOOSAVI/CppMasteryQuest/blob/main/M1/W3/README.md#memory-mastery)**  
  Dynamic allocation, alignment, caching, allocators, and smart pointer internals.  
  *Challenge:* Implement your own `shared_ptr`, then design a custom allocator and a memory pool.

- **[Week 4: Object-Oriented Programming (OOP)](https://github.com/SourenaMOOSAVI/CppMasteryQuest/blob/main/M1/W4/README.md#oop-architecture--plugin-engineering)**  
  Inheritance, polymorphism, SOLID principles, and common design patterns.  
  *Challenge:* Build a **Plugin System** with dynamically loaded modules.

---

### **Month 2: Advanced C++ Features**

**Objective:** Deepen your understanding of compile-time programming, concurrency, and language internals.

- Move semantics, threading models, and advanced template metaprogramming.
- Dive into C++20 features: Concepts, Coroutines, and Modules.

---

### **Month 3: Problem Solving & Algorithms**

**Objective:** Strengthen algorithmic thinking using C++ as your weapon.

- Sorting, searching, graph algorithms, dynamic programming, and custom data structures.
- Focus on **complexity analysis**, **benchmarking**, and **code efficiency**.

---

### **Month 4: Systems Programming & Performance**

**Objective:** Go low-level and fast.

- Filesystems, sockets, and network programming.  
- Cache-aware programming, memory alignment, and profiling.  
- *Challenge:* Implement a multithreaded logger or a simple TCP server.

---

### **Month 5: Large-Scale Software Development**

**Objective:** Think and code like a software engineer.

- Modular design, build systems (CMake), testing (Catch2), debugging, and CI/CD.  
- *Challenge:* Build and test a mini-compiler or interpreter module.

---

### **Month 6: Real-World Applications & Open Source**

**Objective:** Apply everything you’ve learned.

- GUI apps, game dev, or open-source contributions.  
- Build a portfolio-ready project that showcases your C++ mastery.

---

## Repository Structure

```plaintext
CppMasteryQuest/
├── Month1/
│   ├── Week1/    # Core Language & Mechanics
│   ├── Week2/    # STL in Depth
│   ├── Week3/    # Memory Mastery
│   └── Week4/    # Object-Oriented Programming
├── Challenges/    # Coding challenges and solutions
├── Projects/      # Larger real-world applications
├── Resources/     # Books, articles, and learning materials
└── README.md      # You are here!
```

## Set up

Before diving in:

```bash
sudo apt install g++ cmake valgrind
```

## Recommended Tools

| Tool                  | Purpose               |
| --------------------- | --------------------- |
| GCC ≥ 12 / Clang ≥ 15 | Modern C++ compiler   |
| CMake                 | Build automation      |
| Valgrind / ASan       | Memory debugging      |
| Google Benchmark      | Performance testing   |
| VSCode / CLion        | IDEs for productivity |

## Recommended flags

```bash
-std=c++20 -O2 -Wall -Wextra -Wpedantic
```

## How to Use This Repository

1. **Follow the Roadmap** — start with Month 1 and progress sequentially.
2. **Read Each Week’s README** — it explains key concepts and coding tasks.
3. **Build and Run the Examples** — modify them, experiment, and test edge cases.
4. **Complete the Challenges** — these solidify understanding through creation.
5. **Reflect and Benchmark** — measure performance and learn from results.

## Why This Repository?

This repository is designed to:

- Provide a structured learning path to modern C++ mastery.
- Offer hands-on coding challenges with increasing complexity.
- Bridge theory and practice through applied, project-based learning.
- Build real-world coding habits that scale to professional work.
- Serve as a collaborative learning hub for developers worldwide.

## Recommended Resources

| Category | Resource                                           |
| -------- | -------------------------------------------------- |
| Book     | *Effective Modern C++* – Scott Meyers              |
| Book     | *The C++ Programming Language* – Bjarne Stroustrup |
| Website  | [cppreference.com](https://en.cppreference.com/)   |
| Tutorial | [LearnCpp.com](https://www.learncpp.com/)          |
| Tool     | [Compiler Explorer](https://godbolt.org/)          |
| Course   | *C++ Nanodegree* – Udacity (optional)              |

## Contributing

We welcome your contributions!
Here’s how you can help:

1. Fork the repository.
2. Create a branch (`feature/add-new-challenge`).
3. Submit a Pull Request describing your changes clearly.

## You can contribute

- New code examples or optimized implementations.
- Benchmark comparisons between different approaches.
- Additional resources or advanced topics.
- Corrections or editorial improvements.

## License

This project is licensed under the [GPL-3.0](https://github.com/SourenaMOOSAVI/CppMasteryQuest/tree/main?tab=GPL-3.0-1-ov-file) License.
See the GPL-3.0 License file for details.

Happy coding — and welcome to your C++ mastery journey.
