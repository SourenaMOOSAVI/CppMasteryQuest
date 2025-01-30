#include "statistics.h"
#include <iostream>
#include <vector>
#include <cassert>

void testStatistics() {
    std::vector<int> data = {1, 2, 2, 3, 4, 4, 4, 5};

    // Mean
    assert(calculateMean(data) == 3.125);

    // Median
    assert(calculateMedian(data) == 3.0);

    // Mode
    std::vector<int> mode = calculateMode(data);
    assert(mode.size() == 1 && mode[0] == 4);

    // Range
    assert(calculateRange(data) == 4);

    std::cout << "All statistics tests passed.\n";
}

int main() {
    testStatistics();
    return 0;
}
