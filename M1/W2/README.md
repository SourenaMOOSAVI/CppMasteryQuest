# STL in Depth

This week is all about mastering the Standard Template Library (STL) — the foundation of productive, idiomatic, and efficient modern `C++`.

Understanding STL is crucial for both real-world software development and technical interviews. It teaches you how to think in terms of algorithms and iterators rather than manual loops, how to choose the right containers for performance and clarity, and how to harness lambdas and ranges to write expressive, clean `C++20` code.

By the end of this week, you’ll build a Data Analyzer that processes text or CSV data and computes statistics — all powered by STL containers and algorithms.

---

## Concepts Covered

1. **STL Containers**:

   STL provides a rich set of generic containers that manage memory, store data, and provide efficient access.
   Common categories:

   * **Sequence Containers**: `std::vector`, `std::deque`, `std::list`.
   * **Associative Containers**: `std::set`, `std::map`.
   * **Unordered containers**: `std::unordered_set`, `std::unordered_map`.
   * **Container Adapters**: `std::stack`, `std::queue`, `std::priority_queue`.

   **Interview Mini Q&A:**

   * ❓ *When should you use `std::vector` over `std::list`?*
     * `std::vector` offers contiguous memory and `O(1)` random access, making it ideal for fast traversal. `std::list` provides `O(1)` insertion/removal but poor cache locality and no random access.
   * ❓ *What are the differences between `std::map` and `std::unordered_map`?*
     * `std::map` is ordered (implemented as a red-black tree) with `O(log n)` operations; `std::unordered_map` is hash-based and faster on average `(O(1))` but unordered.

   **Types of interview questions you might face:**
   * Choose the most efficient container for a scenario.
   * Implement frequency counters or leaderboards using associative containers.
   * Analyze container time complexity trade-offs.

2. **Iterators**:

   Iterators are STL’s abstraction for traversing containers uniformly. They act like smart pointers that give algorithmic access to any container.

   * Input/output iterators
   * Forward/bidirectional/random access iterators
   * Iterator validity (lifetime, invalidation)

   **Interview Mini Q&A:**
   * ❓ *What happens to iterators when you modify a container?*
     * It depends on the container and operation. For example, inserting into a `std::vector` may invalidate all iterators if reallocation occurs, while `std::list` iterators remain valid unless the erased element is the one being pointed to.
   * ❓ *What is the difference between an iterator and a pointer?*
     * An iterator is a generalized pointer that provides a uniform interface to traverse different container types, while a pointer is specific to a memory address.

   **Types of interview questions you might face:**
   * Predict which iterators are invalidated after modifications.
   * Write algorithms using iterators rather than indices.
   * Explain how `std::begin()`/`std::end()` enable generic code.
   * Implement custom iterators for user-defined containers.

3. **Algorithms**:

   STL algorithms are pre-built, efficient, and generic functions operating on iterator ranges.
   Key groups:

   * **Non-modifying**: `std::for_each`, `std::find`, `std::count`
   * **Modifying**: `std::transform`, `std::remove_if`, `std::sort`
   * **Numeric**: `std::accumulate`, `std::inner_product`
   * **Set operations**: `std::set_union`, `std::set_difference`

   **Interview Mini Q&A:**
   * ❓ *How do STL algorithms improve code quality?*
     * They provide well-tested, optimized implementations that reduce boilerplate code, improve readability, and minimize bugs.
   * ❓ *Why is `std::sort` faster than many hand-written sorts?*
     * `std::sort` uses highly optimized algorithms (like Introsort - a hybrid of quicksort, heapsort, and insertion sort) that adapt to data patterns and leverage low-level optimizations, making them faster than naive implementations.
   * ❓ *How do you remove elements conditionally from a vector?*
     * Use the erase–remove idiom:

     ```cpp
     vec.erase(std::remove_if(vec.begin(), vec.end(), predicate), vec.end());
     ```

   **Types of interview questions you might face:**
   * Implement custom algorithms using STL building blocks.
   * Analyze algorithm time complexities.
   * Rewrite a manual loop using STL algorithms.
   * Explain complexity of sorting and searching.
   * Write code that chains multiple algorithms efficiently.

4. **Lambdas**:

   Lambdas are **anonymous functions** introduced in `C++11` that allow inline behavior definitions, often passed to algorithms.

   * Syntax: `[captures](parameters) { body }`
   * Captures: by value `[=]`, by reference `[&]`, or explicit `[&x, y]`
   * Mutable and return-type specifications

   **Interview Mini Q&A:**
   * ❓ *When should you use a lambda over a regular function?*
     * Use lambdas for short, throwaway functions that are used in a limited scope, especially when passing behavior to algorithms. They improve readability by keeping the logic close to its usage.
   * ❓ *What does the capture list `[&]` mean?*
     * It means that all variables used inside the lambda are captured by reference, allowing the lambda to modify those variables in the enclosing scope.
   * ❓ *What happens when a lambda captures variables by value?*
     * Copies are made at the time of lambda creation; modifications inside the lambda don’t affect the originals.

   **Types of interview questions you might face:**
   * Implement a custom sorting criterion using a lambda.
   * Explain capture semantics and lifetime.
   * Transform data using `std::transform` and lambdas.

5. **Ranges (C++20)**:

   Ranges bring **functional programming style** to `C++`, allowing pipelines of transformations directly on containers.

   Example:

   ```cpp
   #include <ranges>
   auto evens = data | std::views::filter([](int n){ return n % 2 == 0; });
   ```

   **Interview Mini Q&A:**
   * ❓ *What’s the difference between ranges and traditional iterators?*
     * Ranges provide a higher-level abstraction that allows chaining operations directly on containers without explicitly managing iterators, leading to more readable and expressive code.
   * ❓ *What are views?*
     * Views are lightweight, non-owning wrappers around data sequences that lazily evaluate transformations.

   **Types of interview questions you might face:**
   * Rewrite a sequence of STL algorithms using ranges.
   * Discuss lazy evaluation and composability in `C++20`.
   * Pipelines using `views::filter`, `views::transform`.

---

## Challenge: Data Analyzer

Build a **Data Analyzer** that reads numerical data from a text or CSV file and computes various statistics using STL containers and algorithms.

### Features/Requirements

* Parse lines using `std::ifstream` and `std::getline`.  
* Tokenize text using `std::stringstream` or `std::ranges::views::split`.  
* Compute:
  * Word frequency (`std::unordered_map`)
  * Average word length (`std::accumulate`)
  * Most frequent word(s)
* Display sorted results using STL algorithms and iterators.

### Sample Input

```plain-text
C++ STL makes coding elegant and efficient.
The STL provides containers, iterators, algorithms, and function objects.
Mastering STL is key to writing modern C++ code.
C++ STL is powerful.
```

### Sample Output

```bash
$ ./data_analyzer data/sample.csv
Total words: 120
Unique words: 53
Average length: 4.7
Most frequent word: "data" (12 times)

Top 10 words (sorted):
 1. "data" — 12 times
 2. "the"  — 10 times
 3. "and"  — 8 times
 4. "of"   — 7 times
 5. "to"   — 6 times
 6. "is"   — 5 times
 7. "in"   — 4 times
 8. "this" — 3 times
 9. "with" — 3 times
10. "for"  — 2 times
```

### Hints

* Use `std::istringstream` to tokenize words.
* Use `std::unordered_map<std::string, int>` for frequency counting.
* Use `std::max_element` and `std::min_element` with custom lambdas to find extremes.

---

## Learning Outcomes

By the end of Week 2, you should:

* Be fluent with STL containers, iterators, and algorithms.
* Understand time and space complexity trade-offs between containers.
* Use lambdas effectively to make your code cleaner and more functional.
* Write expressive, high-performance data processing pipelines.
* Be able to handle STL-related interview questions confidently.
