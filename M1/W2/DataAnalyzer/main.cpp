#include <iostream>
#include <string>
#include <optional>
#include "Analyzer.h"

using namespace da;

void print_usage(const char* prog) {
    std::cout << "Usage: " << prog << " --input <file> [--top N]\n";
}

int main(int argc, char** argv) {
    std::string inputFile;
    size_t topN = 10;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--input" && i + 1 < argc) {
            inputFile = argv[++i];
        } else if (arg == "--top" && i + 1 < argc) {
            try {
                topN = static_cast<size_t>(std::stoul(argv[++i]));
            } catch (...) {
                std::cerr << "Invalid number for --top\n";
                return 1;
            }
        } else if (arg == "-h" || arg == "--help") {
            print_usage(argv[0]);
            return 0;
        } else {
            std::cerr << "Unknown argument: " << arg << "\n";
            print_usage(argv[0]);
            return 1;
        }
    }

    if (inputFile.empty()) {
        std::cerr << "Missing --input <file>\n";
        print_usage(argv[0]);
        return 1;
    }

    Analyzer analyzer(inputFile);
    analyzer.analyze();
    analyzer.printResults(topN);

    return 0;
}
