#include <catch2/catch_all.hpp>
#include "Analyzer.h"
#include <fstream>
#include <cstdio>
#include <string>
#include <filesystem>

using namespace da;
namespace fs = std::filesystem;

static std::string make_temp_file(const std::string& contents) {
    std::string path = "tests_tmp.txt";
    std::ofstream ofs(path);
    ofs << contents;
    ofs.close();
    return path;
}

TEST_CASE("Analyzer counts words correctly", "[analyzer]") {
    std::string data = "apple banana apple orange banana apple\n";
    auto tmp = make_temp_file(data);

    Analyzer a(tmp);
    a.analyze();
    auto res = a.results();

    REQUIRE(res["apple"] == 3);
    REQUIRE(res["banana"] == 2);
    REQUIRE(res["orange"] == 1);
    REQUIRE(res.size() == 3);

    std::remove(tmp.c_str());
}

TEST_CASE("Analyzer handles empty file", "[analyzer]") {
    std::string tmp = make_temp_file("");
    Analyzer a(tmp);
    a.analyze();
    auto res = a.results();
    REQUIRE(res.empty() == true);
    std::remove(tmp.c_str());
}
