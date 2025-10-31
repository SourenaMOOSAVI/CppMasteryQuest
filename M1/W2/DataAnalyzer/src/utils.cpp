#include "utils.h"
#include <algorithm>
#include <cctype>

namespace da {

std::string cleanWord(const std::string& word) {
    std::string out;
    out.reserve(word.size());
    for (unsigned char c : word) {
        if (std::isalnum(c)) out.push_back(static_cast<char>(std::tolower(c)));
    }
    return out;
}

} // namespace da
