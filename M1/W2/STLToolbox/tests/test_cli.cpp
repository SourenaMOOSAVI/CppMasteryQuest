// tests/test_cli.cpp
#include "cli.h"
#include <iostream>
#include <cassert>

void testCLI() {
    const char* argv[] = {"program", "--input", "input.txt", "--output", "output.txt", "--stats"};
    int argc = 5;
    CLI cli(argc, const_cast<char**>(argv));

    assert(cli.getInputFile() == "input.txt");
    assert(cli.getOutputFile() == "output.txt");
    assert(cli.shouldComputeStats());
    assert(!cli.shouldSort()); // Assuming sort flag isn't provided
    
    std::cout << "All CLI tests passed!" << std::endl;
}

int main() {
    testCLI();
    return 0;
}
