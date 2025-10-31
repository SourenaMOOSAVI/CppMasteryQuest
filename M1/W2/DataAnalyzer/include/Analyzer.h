#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace da {

class Analyzer {
public:
    explicit Analyzer(std::string_view filename);
    void analyze();                                   // parse + compute
    void printResults(std::size_t topN = 10) const;   // formatted output
    std::unordered_map<std::string,int> results() const; // for testing

private:
    std::string filename_;
    std::unordered_map<std::string,int> wordCount_;
    std::size_t totalWords_ = 0;

    std::vector<std::string> tokenize(const std::string& line) const;
};

} // namespace da
