#include "file_io.h"    // Include custom header file for declarations
#include <fstream>      // Include standard library header file for file I/O
#include <sstream>      // Include standard library header file for string streams
#include <stdexcept>    // Include standard library header file for exceptions    
#include <iostream>     // Include standard library header file for input/output

// Function to read data from a file and return a vector of integers
std::vector<int> readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);   // Open the file for reading
    if (!file.is_open()) {          // Check if the file could not be opened
        throw std::runtime_error("Could not open file: " + filename);   // Throw an exception with an error message
    }

    std::vector<int> data;  // Create a vector to store the data read from the file
    int number;             // Variable to store each number read from the file

    while (file >> number) {    // Read each number from the file
        data.push_back(number); // Add the number to the vector
    }

    if (file.bad()) {  // Check if an error occurred while reading the file
        throw std::runtime_error("Error reading file: " + filename);    // Throw an exception with an error message
    }

    file.close();   // Explicitly close the file after reading all the data

    return data;    // Return the vector of integers read from the file
}

// Function to write a vector of integers to a file
void writeDataToFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);   // Open the file for writing
    if (!file.is_open()) {          // Check if the file could not be opened
        throw std::runtime_error("Could not open file for writing: " + filename);  // Throw an exception with an error message
    }

    for (const auto& number : data) {   // Iterate over each number in the vector
        file << number << "\n";         // Write the number to the file
    }
}