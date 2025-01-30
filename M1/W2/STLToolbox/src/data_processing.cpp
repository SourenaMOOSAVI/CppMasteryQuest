#include "data_processing.h"
#include <algorithm>
#include <set>

void sortAscending(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
}

void sortDescending(std::vector<int>& data) {
    std::sort(data.begin(), data.end(), std::greater<int>());
}

void removeDuplicates(std::vector<int>& data) {
    std::set<int> uniqueSet(data.begin(), data.end());
    data.assign(uniqueSet.begin(), uniqueSet.end());
}

void squareValues(std::vector<int>& data) {
    std::transform(data.begin(), data.end(), data.begin(), [](int x) { return x * x; });
}