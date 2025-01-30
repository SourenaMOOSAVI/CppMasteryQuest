#include "file_io.h"
#include <iostream>
#include <cassert>
#include <fstream>

void testReadDataFromFile() {
    // Create a sample file for testing
    const std::string testFile = "test_input.txt";
    std::ofstream outFile(testFile);
    outFile << "10\n20\n30\n40\n";
    outFile.close();

    // Read data from file
    std::vector<int> data = readDataFromFile(testFile);

    // Validate the results
    assert(data.size() == 4);
    assert(data[0] == 10);
    assert(data[1] == 20);
    assert(data[2] == 30);
    assert(data[3] == 40);

    std::cout << "testReadDataFromFile passed!" << std::endl;
}

void testWriteDataToFile() {
    const std::string testFile = "test_output.txt";
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Write data to file
    writeDataToFile(testFile, data);

    // Read data back for validation
    std::vector<int> readData = readDataFromFile(testFile);

    assert(readData == data);

    std::cout << "testWriteDataToFile passed!" << std::endl;
}

int main() {
    testReadDataFromFile();
    testWriteDataToFile();
    return 0;
}