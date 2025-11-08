# Project Structure

Below is the structure for "Custom Smart Pointer and Memory Pool Manager" project.

```bash
MemoryMastery/
├── CMakeLists.txt
├── include/
│   ├── MySharedPtr.h
│   ├── SimpleAllocator.h
│   └── MemoryPool.h
├── src/
│   ├── MySharedPtr.cpp     (tiny, only for build convenience — implementations are header-only)
│   └── MemoryPool.cpp
├── main.cpp
├── tests/
│   ├── test_shared_ptr.cpp
│   ├── test_allocator.cpp
│   └── test_pool.cpp
└── README.md
```

Notes:

* Template-based components are header-only where appropriate (e.g., `SimpleAllocator`).

* `MySharedPtr` is implemented as a thread-safe, minimal control-block-based smart pointer (header-only).

* `MemoryPool` has a small `.cpp` implementation to keep the interface clean.

## Build & Run Instructions

```bash
mkdir build && cd build
cmake ..
cmake --build . -- -j
# run tests
ctest --output-on-failure
# run demo executable
./memory_mastery
```
