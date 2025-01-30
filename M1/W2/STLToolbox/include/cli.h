#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>

class CLI {
public:
    CLI(int argc, char* argv[]);

    // Methods to parse and retrieve user options
    std::string getInputFile() const;
    std::string getOutputFile() const;
    bool shouldSort() const;
    bool shouldDeduplicate() const;
    bool shouldComputeStats() const;
    bool shouldTransform() const;

    void displayHelp() const;

private:
    std::vector<std::string> arguments;
    std::string inputFile;
    std::string outputFile;
    bool sort;
    bool deduplicate;
    bool computeStats;
    bool transform;

    void parseArguments();
};

#endif // CLI_H
