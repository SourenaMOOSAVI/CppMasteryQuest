#include <iostream>
#include "SharedPtr.h"
#include "MemoryPool.h"
#include "WeakPtr.h"

int main() {
    std::cout << "Custom Smart Pointer and Memory Pool Manager Demo\n";

    // Example 1: SharedPtr usage
    {
        SharedPtr<int> sp1(new int(42));
        SharedPtr<int> sp2 = sp1;  // Copy construction
        std::cout << "SharedPtr Value: " << *sp1 << ", Ref Count: " << sp1.use_count() << "\n";
    } // sp1 and sp2 go out of scope; object should be deleted.

    // Example 2: WeakPtr usage
    {
        SharedPtr<int> sp(new int(100));
        WeakPtr<int> wp(sp);
        std::cout << "WeakPtr expired? " << (wp.expired() ? "Yes" : "No") << "\n";
        if (auto locked = wp.lock()) {
            std::cout << "Locked value: " << *locked << "\n";
        }
    } // sp goes out of scope; wp will now expire.

    // Example 3: MemoryPool usage
    {
        MemoryPool<int> pool(5);  // Pool for 5 integers
        int* obj1 = pool.allocate();
        int* obj2 = pool.allocate();

        *obj1 = 10;
        *obj2 = 20;
        std::cout << "MemoryPool Values: " << *obj1 << ", " << *obj2 << "\n";

        pool.deallocate(obj1);
        pool.deallocate(obj2);
    } // MemoryPool deallocates memory automatically.

    std::cout << "Demo finished!\n";
    return 0;
}