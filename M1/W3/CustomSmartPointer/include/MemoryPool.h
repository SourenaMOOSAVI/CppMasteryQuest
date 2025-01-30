// MemoryPool.h
#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H

#include <cstddef>
#include <stack>
#include <stdexcept>
#include <vector>

template <typename T>
class MemoryPool {
private:
    std::vector<T*> pool;
    std::stack<T*> freeBlocks;
    size_t blockSize;

public:
    explicit MemoryPool(size_t blockSize = 100);
    ~MemoryPool();

    T* allocate();
    void deallocate(T* ptr);

    MemoryPool(const MemoryPool&) = delete;
    MemoryPool& operator=(const MemoryPool&) = delete;
};

// Implementation

template <typename T>
MemoryPool<T>::MemoryPool(size_t blockSize) : blockSize(blockSize) {
    pool.reserve(blockSize);
    for (size_t i = 0; i < blockSize; ++i) {
        T* block = new T;
        pool.push_back(block);
        freeBlocks.push(block);
    }
}

template <typename T>
MemoryPool<T>::~MemoryPool() {
    for (T* block : pool) {
        delete block;
    }
}

template <typename T>
T* MemoryPool<T>::allocate() {
    if (freeBlocks.empty()) {
        throw std::runtime_error("MemoryPool out of memory.");
    }
    T* block = freeBlocks.top();
    freeBlocks.pop();
    return block;
}

template <typename T>
void MemoryPool<T>::deallocate(T* ptr) {
    freeBlocks.push(ptr);
}

#endif // MEMORYPOOL_H