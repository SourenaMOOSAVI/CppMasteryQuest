#include "MemoryPool.h"
#include <new>

namespace mm {

MemoryPool::MemoryPool(std::size_t blockSize, std::size_t blocksPerChunk)
    : blockSize_(blockSize), blocksPerChunk_(blocksPerChunk) {
    assert(blockSize_ > 0);
    // start with one chunk to avoid first-time allocation cost later
    allocateChunk();
}

MemoryPool::~MemoryPool() {
    for (auto& c : chunks_) {
        delete[] c.data;
        c.data = nullptr;
    }
    chunks_.clear();
}

void MemoryPool::allocateChunk() {
    Chunk c;
    c.data = new char[blockSize_ * blocksPerChunk_];
    c.freeList.reserve(blocksPerChunk_);
    for (std::size_t i = 0; i < blocksPerChunk_; ++i) {
        c.freeList.push_back(c.data + i * blockSize_);
    }
    chunks_.push_back(std::move(c));
}

void* MemoryPool::allocate() {
    for (auto& c : chunks_) {
        if (!c.freeList.empty()) {
            void* p = c.freeList.back();
            c.freeList.pop_back();
            return p;
        }
    }
    // no free block -> allocate new chunk and return one block
    allocateChunk();
    Chunk& c = chunks_.back();
    void* p = c.freeList.back();
    c.freeList.pop_back();
    return p;
}

void MemoryPool::deallocate(void* p) noexcept {
    if (!p) return;
    for (auto& c : chunks_) {
        char* start = c.data;
        char* end = c.data + blockSize_ * blocksPerChunk_;
        if (p >= start && p < end) {
            c.freeList.push_back(p);
            return;
        }
    }
    // pointer not belonging to pool: ignore silently
}

} // namespace mm
