#include "SharedPtr.h"
#include <cassert>
#include <iostream>

void testDefaultConstructor() {
    SharedPtr<int> sp;
    assert(sp.get() == nullptr);
    assert(sp.use_count() == 0);
    std::cout << "testDefaultConstructor passed!" << std::endl;
}

void testParameterizedConstructor() {
    SharedPtr<int> sp(new int(42));
    assert(*sp == 42);
    assert(sp.use_count() == 1);
    std::cout << "testParameterizedConstructor passed!" << std::endl;
}

void testCopyConstructor() {
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2 = sp1;
    assert(sp1.use_count() == 2);
    assert(sp2.use_count() == 2);
    assert(*sp1 == 42);
    assert(*sp2 == 42);
    std::cout << "testCopyConstructor passed!" << std::endl;
}

void testMoveConstructor() {
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2 = std::move(sp1);
    assert(sp1.get() == nullptr);
    assert(sp2.use_count() == 1);
    assert(*sp2 == 42);
    std::cout << "testMoveConstructor passed!" << std::endl;
}

void testCopyAssignment() {
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2;
    sp2 = sp1;
    assert(sp1.use_count() == 2);
    assert(sp2.use_count() == 2);
    assert(*sp1 == 42);
    assert(*sp2 == 42);
    std::cout << "testCopyAssignment passed!" << std::endl;
}

void testMoveAssignment() {
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2;
    sp2 = std::move(sp1);
    assert(sp1.get() == nullptr);
    assert(sp2.use_count() == 1);
    assert(*sp2 == 42);
    std::cout << "testMoveAssignment passed!" << std::endl;
}

void testReset() {
    SharedPtr<int> sp(new int(42));
    sp.reset();
    assert(sp.get() == nullptr);
    assert(sp.use_count() == 0);
    sp.reset(new int(99));
    assert(*sp == 99);
    assert(sp.use_count() == 1);
    std::cout << "testReset passed!" << std::endl;
}

void testUnique() {
    SharedPtr<int> sp1(new int(42));
    SharedPtr<int> sp2 = sp1;
    assert(!sp1.unique());
    sp2.reset();
    assert(sp1.unique());
    std::cout << "testUnique passed!" << std::endl;
}

void testCustomType() {
    struct Test {
        int x, y;
        Test(int a, int b) : x(a), y(b) {}
    };
    SharedPtr<Test> sp(new Test(3, 4));
    assert(sp->x == 3);
    assert(sp->y == 4);
    std::cout << "testCustomType passed!" << std::endl;
}

int main() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testReset();
    testUnique();
    testCustomType();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
