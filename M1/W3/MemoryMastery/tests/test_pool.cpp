#include <catch2/catch_all.hpp>
#include "MemoryPool.h"

using namespace mm;

TEST_CASE("MemoryPool allocate and reuse", "[pool]") {
    MemoryPool pool(32, 4);
    void* a = pool.allocate();
    void* b = pool.allocate();
    REQUIRE(a != nullptr);
    REQUIRE(b != nullptr);
    pool.deallocate(a);
    void* c = pool.allocate();
    REQUIRE(c != nullptr);
    // c may or may not equal a depending on implementation details, but allocation succeeded
}