#include "../include/WeakPtr.h"
#include <iostream>
#include <cassert>

void testWeakPtr() {
    SharedPtr<int> shared1(new int(100));
    WeakPtr<int> weak1(shared1);
    SharedPtr<int> locked1 = weak1.lock();

    assert(locked1 && *locked1 == 100);

    shared1.reset();
    SharedPtr<int> locked2 = weak1.lock();
    assert(!locked2); // weak1 should now be expired

    std::cout << "WeakPtr tests passed.\n";
}

int main() {
    testWeakPtr();
    return 0;
}