#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

double calculateMean(const std::vector<int>& data);

double calculateMedian(const std::vector<int> data);

std::vector<int> calculateMode(const std::vector<int>& data);

int calculateRange(const std::vector<int>& data);

#endif // STATISTICS_H