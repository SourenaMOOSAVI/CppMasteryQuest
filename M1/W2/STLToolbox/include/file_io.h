#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>

// Reads data from a file and returns a vector of integers.
// Throws an exception if the file cannot be opened or contains invalid data.
std::vector<int> readDataFromFile(const std::string& filename);

// Writes data to a file (for testing or saving results).
void writeDataToFile(const std::string& filename, const std::vector<int>& data);

#endif // FILE_IO_H
