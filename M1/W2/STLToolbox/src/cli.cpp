#include "cli.h"
#include <iostream>
#include <stdexcept> // Include for throwing runtime exceptions

CLI::CLI(int argc, char* argv[]) : sort(false), deduplicate(false), computeStats(false), transform(false) {
    if (argc < 2) {
        displayHelp();
        throw std::runtime_error("No arguments provided. Use --help for usage information.");
    }
    
    for (int i = 1; i < argc; ++i) {
        arguments.emplace_back(argv[i]);
    }
    parseArguments();
}

void CLI::parseArguments() {
    for (const auto& arg : arguments) {
        if (arg == "--sort") {
            sort = true;
        } else if (arg == "--deduplicate") {
            deduplicate = true;
        } else if (arg == "--stats") {
            computeStats = true;
        } else if (arg == "--transform") {
            transform = true;
        } else if (arg.rfind("--input=", 0) == 0) {
            inputFile = arg.substr(8); // Extract value after "--input="
            if (inputFile.empty()) {
                throw std::runtime_error("Invalid --input argument. File path cannot be empty.");
            }
        } else if (arg.rfind("--output=", 0) == 0) {
            outputFile = arg.substr(9); // Extract value after "--output="
            if (outputFile.empty()) {
                throw std::runtime_error("Invalid --output argument. File path cannot be empty.");
            }
        } else if (arg == "--help") {
            displayHelp();
        } else {
            throw std::runtime_error("Unknown argument: " + arg + ". Use --help for usage information.");
        }
    }

    // Ensure required arguments are provided
    if (inputFile.empty()) {
        throw std::runtime_error("Missing required argument: --input=<file>");
    }
}

std::string CLI::getInputFile() const { 
    return inputFile; 
}

std::string CLI::getOutputFile() const { 
    return outputFile; 
}

bool CLI::shouldSort() const { 
    return sort; 
}

bool CLI::shouldDeduplicate() const { 
    return deduplicate; 
}

bool CLI::shouldComputeStats() const { 
    return computeStats; 
}

bool CLI::shouldTransform() const { 
    return transform; 
}

void CLI::displayHelp() const {
    std::cout << "Usage: ./data_analyzer [options]\n"
              << "Options:\n"
              << "--sort            Sort the data\n"
              << "--deduplicate     Remove duplicates\n"
              << "--stats           Compute statistics (mean, median, mode, range)\n"
              << "--transform       Apply transformations (e.g., square each value)\n"
              << "--input=<file>    Input file path (required)\n"
              << "--output=<file>   Output file path\n"
              << "--help            Show this help message\n";
    std::exit(0);
}
