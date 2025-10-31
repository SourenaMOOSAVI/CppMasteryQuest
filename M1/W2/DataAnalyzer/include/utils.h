#pragma once
#include <string>

namespace da {

/**
 * @brief Remove punctuation and normalize case for a token/word.
 * Keeps alphanumeric characters only and converts to lowercase.
 */
std::string cleanWord(const std::string& word);

} // namespace da
