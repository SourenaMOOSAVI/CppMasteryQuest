#include <catch2/catch_all.hpp>
#include "SimpleAllocator.h"
#include <vector>

using namespace mm;

TEST_CASE("SimpleAllocator integrates with vector", "[allocator]") {
    std::vector<int, SimpleAllocator<int>> v;
    v.reserve(4);
    for (int i = 0; i < 4; ++i) v.push_back(i);
    REQUIRE(v.size() == 4);
    REQUIRE(v[2] == 2);
}