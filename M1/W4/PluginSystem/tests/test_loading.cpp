#include <catch2/catch_all.hpp>
#include "PluginManager.h"

TEST_CASE("load echo plugin", "[plugin]") {
    PluginManager pm;
    bool ok = pm.loadPlugin("plugins/echo.so");
    REQUIRE(ok == true);

    IPlugin* p = pm.get("echo");
    REQUIRE(p != nullptr);
    REQUIRE(p->execute("abc") == "Echo: abc");

    pm.unloadAll();
}

TEST_CASE("load math plugin", "[plugin]") {
    PluginManager pm;
    bool ok = pm.loadPlugin("plugins/math.so");
    REQUIRE(ok == true);

    IPlugin* p = pm.get("math");
    REQUIRE(p != nullptr);
    REQUIRE(p->execute("3 4") == "7");

    pm.unloadAll();
}
