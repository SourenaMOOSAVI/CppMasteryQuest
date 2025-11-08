#include <catch2/catch_all.hpp>
#include "MySharedPtr.h"

using namespace mm;

TEST_CASE("MySharedPtr basic semantics", "[shared_ptr]") {
    MySharedPtr<int> p = MySharedPtr<int>(new int(5));
    REQUIRE(p);
    REQUIRE(*p == 5);
    REQUIRE(p.use_count() == 1);

    {
        auto q = p;
        REQUIRE(p.use_count() == 2);
        REQUIRE(q.use_count() == 2);
    }

    REQUIRE(p.use_count() == 1);
    p.reset();
    REQUIRE(p.use_count() == 0);
    REQUIRE(!p);
}
