#ifndef DATA_PROCESSING_H
#define DATA8PROCESSING_H

#include <vector>

// Sorts the vector of integers in ascending order.
void sortAscending(std::vector<int>& data);

// Sorts the vector of integers in descending order.
void sortDescending(std::vector<int>& data);

// Removes the duplicates from the vector of integers.
void removeDuplicates(std::vector<int>& data);

// Applies a square transformation to each element in the vector.
void squareValues(std::vector<int>& data);

#endif // DATA_PROCESSING_H