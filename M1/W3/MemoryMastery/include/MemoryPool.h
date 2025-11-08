#pragma once
#include <cstddef>
#include <vector>
#include <cassert>

namespace mm {

class MemoryPool {
public:
    explicit MemoryPool(std::size_t blockSize, std::size_t blocksPerChunk = 1024);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* p) noexcept;

    std::size_t blockSize() const noexcept { return blockSize_; }
    std::size_t blocksPerChunk() const noexcept { return blocksPerChunk_; }

private:
    struct Chunk {
        char* data = nullptr;
        std::vector<void*> freeList;
    };

    std::size_t blockSize_;
    std::size_t blocksPerChunk_;
    std::vector<Chunk> chunks_;

    void allocateChunk();
};

} // namespace mm