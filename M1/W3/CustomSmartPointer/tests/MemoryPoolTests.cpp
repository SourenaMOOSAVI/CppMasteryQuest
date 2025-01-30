#include "../include/MemoryPool.h"
#include <iostream>
#include <cassert>

void testMemoryPool() {
    MemoryPool<int> pool(10);
    
    // Allocate and deallocate
    int* a = pool.allocate();
    int* b = pool.allocate();
    *a = 42;
    *b = 99;
    assert(*a == 42 && *b == 99);

    pool.deallocate(a);
    pool.deallocate(b);

    // Reallocate
    int* c = pool.allocate();
    int* d = pool.allocate();
    assert(c == a && d == b); // Memory should be reused
    std::cout << "MemoryPool tests passed.\n";
}

int main() {
    testMemoryPool();
    return 0;
}