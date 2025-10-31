#include "Analyzer.h"
#include "utils.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace da {

Analyzer::Analyzer(std::string_view filename)
    : filename_(filename) {}

std::vector<std::string> Analyzer::tokenize(const std::string& line) const {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        auto cleaned = cleanWord(token);
        if (!cleaned.empty()) tokens.push_back(std::move(cleaned));
    }
    return tokens;
}

void Analyzer::analyze() {
    wordCount_.clear();
    totalWords_ = 0;

    std::ifstream ifs(filename_);
    if (!ifs.is_open()) {
        std::cerr << "Error: cannot open file '" << filename_ << "'\n";
        return;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        auto words = tokenize(line);
        for (const auto& w : words) ++wordCount_[w];
        totalWords_ += words.size();
    }
}

void Analyzer::printResults(std::size_t topN) const {
    if (totalWords_ == 0 || wordCount_.empty()) {
        std::cout << "No words found in file.\n";
        return;
    }

    // Total & unique
    std::cout << "Total words: " << totalWords_ << "\n";
    std::cout << "Unique words: " << wordCount_.size() << "\n";

    // Average length: sum(length * freq) / totalWords
    double totalLen = std::accumulate(
        wordCount_.begin(), wordCount_.end(), 0.0,
        [](double acc, const auto& p) {
            return acc + static_cast<double>(p.first.size()) * p.second;
        }
    );
    double avgLen = (totalWords_ > 0) ? (totalLen / static_cast<double>(totalWords_)) : 0.0;
    std::cout << "Average length: " << std::fixed << std::setprecision(2) << avgLen << "\n";

    // Most frequent element
    auto maxIt = std::max_element(
        wordCount_.begin(), wordCount_.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first > b.first; // tie-breaker arbitrary
        }
    );
    if (maxIt != wordCount_.end()) {
        std::cout << "Most frequent word: \"" << maxIt->first << "\" ("
                  << maxIt->second << " times)\n";
    }

    // Create sortable vector and sort by freq desc, then word asc
    std::vector<std::pair<std::string,int>> freq;
    freq.reserve(wordCount_.size());
    for (const auto& kv : wordCount_) freq.emplace_back(kv.first, kv.second);

    std::sort(freq.begin(), freq.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second; // more freq first
            return a.first < b.first; // lexicographic tie-breaker
        });

    // Print top-N
    std::size_t n = std::min(topN, freq.size());
    std::cout << "\nTop " << n << " words (sorted):\n";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << std::setw(2) << (i + 1) << ". "
                  << "\"" << freq[i].first << "\" — "
                  << freq[i].second << " times\n";
    }
}

std::unordered_map<std::string,int> Analyzer::results() const {
    return wordCount_;
}

} // namespace da
