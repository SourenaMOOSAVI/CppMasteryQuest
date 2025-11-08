# Project Structure

The following structure ensures that the data analysis tool is clean, modular and scalable. The proposed structure is based on principles of **modularity**, **single responsibility**, and **separation of concerns**, which align with best practices in software engineering.

```bash
DataAnalyzer/
├── CMakeLists.txt         # CMake config: builds executable, fetches Catch2, sets up tests
├── include/
│   ├── Analyzer.h         # Public API: Analyzer class declaration (pragma once, namespace da)
│   └── utils.h            # Utility decls (e.g., cleanWord)
├── src/
│   ├── Analyzer.cpp       # Core impl: file reading, tokenization, analysis, printing
│   └── utils.cpp          # Utility impls (minimal, just cleanWord)
├── main.cpp               # Entry point: Arg parsing, Analyzer orchestration
├── data/
│   └── sample.txt         # Sample input: Multi-line text for testing
├── tests/
│   ├── test_analyzer.cpp  # Analyzer unit tests (file-based mocks)
│   └── test_utils.cpp     # Utils unit tests (simple assertions)
└── README.md              # This file: Project overview, build/run instructions
```

## Key Components

1. Utilities (`include/utils.h` / `src/utils.cpp`):

   Lightweight helper for word normalization. This is the "preprocessing" layer.

2. Analyzer Class (`include/Analyzer.h` / `src/Analyzer.cpp`):

   The heart of the app: Encapsulates file I/O, tokenization, stats computation, and output. Private members: `filename_`, `wordCount_` (`unordered_map` for `O(1)` lookups), `totalWords_ (size_t counter)`.

3. CLI Entry Point (`main.cpp`):

   Simple arg parser (no external lib like Boost.ProgramOptions—keeps it lightweight).

## Build & Run Instructions

```bash
mkdir build && cd build
cmake ..  # Or cmake -B build -S . for out-of-tree
cmake --build .  # Builds data_analyzer and tests
ctest -V  # Runs tests
./data_analyzer --input ../data/sample.txt  # Run the analyzer
```
