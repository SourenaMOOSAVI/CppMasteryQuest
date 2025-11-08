#include <iostream>
#include <vector>
#include "MySharedPtr.h"
#include "SimpleAllocator.h"
#include "MemoryPool.h"

using namespace mm;

int main() {
    std::cout << "=== Memory Mastery Demo ===\n\n";

    // MySharedPtr demo
    {
        std::cout << "[MySharedPtr]\n";
        MySharedPtr<int> a(new int(42));
        std::cout << "value: " << *a << ", use_count: " << a.use_count() << "\n";
        {
            MySharedPtr<int> b = a;
            std::cout << "after copy use_count: " << a.use_count() << "\n";
        }
        std::cout << "after scope use_count: " << a.use_count() << "\n\n";
    }

    // SimpleAllocator demo
    {
        std::cout << "[SimpleAllocator]\n";
        std::vector<int, SimpleAllocator<int>> v;
        v.reserve(8);
        for (int i = 0; i < 8; ++i) v.push_back(i * 2);
        std::cout << "vector size: " << v.size() << "\n\n";
    }

    // MemoryPool demo
    {
        std::cout << "[MemoryPool]\n";
        MemoryPool pool(64, 8); // blocks of 64 bytes, 8 blocks per chunk
        void* p1 = pool.allocate();
        void* p2 = pool.allocate();
        std::cout << "allocated: " << p1 << " , " << p2 << "\n";
        pool.deallocate(p1);
        pool.deallocate(p2);
        std::cout << "deallocated returned to pool\n";
    }

    return 0;
}
