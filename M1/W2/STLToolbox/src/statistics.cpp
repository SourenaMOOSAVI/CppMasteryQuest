#include "statistics.h"
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <stdexcept>

// Calculate Mean
double calculateMean(const std::vector<int>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Data is empty. Cannot calculate mean.");
    }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Calculate Median
double calculateMedian(std::vector<int> data) {
    if (data.empty()) {
        throw std::invalid_argument("Data is empty. Cannot calculate median.");
    }
    std::sort(data.begin(), data.end());
    size_t size = data.size();
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// Calculate Mode
std::vector<int> calculateMode(const std::vector<int>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Data is empty. Cannot calculate mode.");
    }
    std::unordered_map<int, int> frequency;
    for (int num : data) {
        frequency[num]++;
    }
    int maxFrequency = 0;
    for (const auto& [key, value] : frequency) {
        maxFrequency = std::max(maxFrequency, value);
    }
    std::vector<int> modes;
    for (const auto& [key, value] : frequency) {
        if (value == maxFrequency) {
            modes.push_back(key);
        }
    }
    return modes;
}

// Calculate Range
int calculateRange(const std::vector<int>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Data is empty. Cannot calculate range.");
    }
    auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
    return *maxIt - *minIt;
}
