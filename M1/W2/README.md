# STL in Depth

This week is all about mastering the Standard Template Library (STL) — the foundation of productive, idiomatic, and efficient modern `C++`.

Understanding STL is crucial for both real-world software development and technical interviews. It teaches you how to think in terms of algorithms and iterators rather than manual loops, how to choose the right containers for performance and clarity, and how to harness lambdas and ranges to write expressive, clean `C++20` code.

By the end of this week, you’ll build a Data Analyzer that processes text or CSV data and computes statistics — all powered by STL containers and algorithms.

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
     * `std::vector` offers contiguous memory and `O(1)` random access, making it ideal for fast traversal. std::list provides `O(1)` insertion/removal but poor cache locality and no random access.
   * ❓ *What are the differences between `std::map` and `std::unordered_map`?*
     * `std::map` is ordered (implemented as a red-black tree) with `O(log n)` operations; `std::unordered_map` is hash-based and faster on average `(O(1))` but unordered.

   **Types of interview questions you might face:**
   * Choose the most efficient container for a scenario.
   * Implement frequency counters or leaderboards using associative containers.
   * Analyze container time complexity trade-offs.


2. **STL Algorithms**:
   Algorithms are a fundamental part of the C++ Standard Library. Algorithms don't work with containers themselves but rather with iterators. Therefore, the same algorithm can be used by most if not all of the C++ Standard Library containers. The Standard Library Algorithms can come in several categories:

   - **Non-modifying Algorithms**: These algorithms do not alter the contents of the container but perform operations like searching, counting, and checking properties. Examples: `std::find`, `std::count`, etc.
   - **Modifying Algorithms**: These algorithms modify the elements of the container or its structure. Examples: `std::copy`, `std::fill`, `std::remove`, etc.
   - **Sorting and Partitioning Algorithms**: These algorithms rearrange the elements of a container. Examples: `std::sort`, `std::partition`, etc.
   - **Set Algorithms**: These algorithms work on sorted ranges and perform set-like operations. Examples: `std::set_union`, `std::set_difference`, etc.
   - **Heap Algorithms**: These algorithms help work with heaps, which are specialized binary tree-like structures. Examples: `std::make_heap`, `std::push_heap`, etc.

3. **Iterators**:
   An **iterator** is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. They can be visualized as something similar to a pointer pointing to some location and we can access content at that particular location using them. Depending upon the functionality of iterators they can be classified into five categories:

   - **Input Iterators**: Used to read a sequence of values.
   - **Output Iterators**: Used to write a sequence of values.
   - **Forward Iterators**: Can be read, written, and moved forward.
   - **Bidirectional Iterators**: Can be read, written, and moved both forward and backward.
   - **Random-Access Iterators**: Can be read, written, and moved to any element in constant time.

4. **Custom Comparators and Lambda Functions**:
   Custom comparators and lambda functions are powerful features in C++ that allow you to define custom logic for sorting, searching, or transforming data. In this project, they are used extensively to demonstrate the flexibility and expressiveness of the Standard Template Library (STL).

   - **Lambda Functions**: Lambda functions are anonymous functions that are defined in place, making them ideal for short, specific operations. They are written using the following syntax:

     ```cpp
     [ capture_clause ] ( parameters ) -> return_type { body }
     ```

     Example:

     ```cpp
     auto add = [](int a, int b) -> int { return a + b; };
     std::cout << add(2, 3); // Outputs: 5
     ```

   - **Custom Comparators**: Custom comparators are functions or lambda expressions used to define **custom sorting or comparison logic** for STL algorithms. These are particularly useful in operations like `std::sort`, `std::set`, or `std::priority_queue`.

     Example:

     ```cpp
     std::vector<int> data = {5, 2, 9, 1, 5, 6};
     std::sort(data.begin(), data.end(), [](int a, int b) { return a > b; }); // Sort in descending order
     ```

5. **File I/O with STL Streams**:
   File I/O operations are essential for reading and writing data to and from files. The C++ Standard Library provides a set of classes for file I/O operations, including `std::ifstream` for reading from files, `std::ofstream` for writing to files, and `std::fstream` for both reading and writing.

   Example:

   ```cpp
   std::ifstream inputFile("data.txt");
   std::vector<int> data;
   int value;
   while (inputFile >> value) {
       data.push_back(value);
   }
   inputFile.close();
   ```

## How to run the project

1. **Clone the repository**:
    Clone the repository to your local machine using the following command:

    ```sh
    git clone https://github.com/sourenamoosavi/stl-toolbox.git
    ```

2. **Build the project**:
    Ensure you have a C++ compiler installed. Then, run the following command to compile the project:

    ```sh
    cd stl-toolbox
    make
    ```

3. **Run the executable**:
    After building the project, you can run the executable:

    ```sh
    ./data_analyzer
    ```

    you should see the following output:

    ```sh
    Usage: ./data_analyzer [options]
    Options:
    --sort            Sort the data
   --deduplicate     Remove duplicates
   --stats           Compute statistics (mean, median, mode, range)
   --transform       Apply transformations (e.g., square each value)
   --input=<file>    Input file path (required)
   --output=<file>   Output file path
   --help            Show this help message
   ```

4. **Run tests**:
    To ensure everything is working correctly, run the tests:

    ```sh
    ./main_program --input=data/input.txt --output=data/output.txt --stats
    ```
