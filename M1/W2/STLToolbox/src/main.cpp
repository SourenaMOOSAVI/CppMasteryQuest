#include "cli.h"
#include "file_io.h"
#include "data_processing.h"
#include "statistics.h"
#include <iostream>
#include <vector>

// Function to print a vector
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main(int argc, char* argv[]) {
    CLI cli(argc, argv);

    // Read input file
    std::vector<int> data = readDataFromFile(cli.getInputFile());

    // Perform operations based on user input
    if (cli.shouldSort()) sortAscending(data);
    if (cli.shouldDeduplicate()) removeDuplicates(data);
    if (cli.shouldTransform()) squareValues(data);

    // Compute statistics if requested
    if (cli.shouldComputeStats()) {
        double mean = calculateMean(data);
        double median = calculateMedian(data);
        std::vector<int> mode = calculateMode(data);
        int range = calculateRange(data);

        std::cout << "Statistics:\n";
        std::cout << "Mean: " << mean << "\n";
        std::cout << "Median: " << median << "\n";
        std::cout << "Mode: ";
        printVector(mode);
        std::cout << "\n";
        std::cout << "Range: " << range << "\n";
    }

    // Write output file if specified
    if (!cli.getOutputFile().empty()) {
        writeDataToFile(cli.getOutputFile(), data);
    }

    return 0;
}
