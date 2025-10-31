#include <catch2/catch_all.hpp>
#include "utils.h"
#include <string>

using namespace da;

TEST_CASE("cleanWord removes punctuation and lowercases", "[utils]") {
    REQUIRE(cleanWord("Hello!") == "hello");
    REQUIRE(cleanWord("C++") == "c");
    REQUIRE(cleanWord("data-driven") == "datadriven");
    REQUIRE(cleanWord("123ABC") == "123abc");
    REQUIRE(cleanWord("...") == "");
}
