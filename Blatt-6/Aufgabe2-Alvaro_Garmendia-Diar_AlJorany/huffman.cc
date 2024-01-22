#include "huffman.hh"
#include <algorithm>
#include <string>

// Function to count character frequency
std::map<char, int> countCharacterFrequency(const std::string &text) {
    std::map<char, int> frequencyMap;
    for (char c: text) {
        frequencyMap[c]++;
    }
    return frequencyMap;
}
