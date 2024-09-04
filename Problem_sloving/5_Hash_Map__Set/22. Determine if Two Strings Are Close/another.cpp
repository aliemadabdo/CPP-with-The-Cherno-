#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdbool.h>

using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) {
        return false;
    }

    unordered_map<char, int> word1Map, word2Map;

    // Build frequency maps
    for (char c : word1) word1Map[c]++;
    for (char c : word2) word2Map[c]++;

    // Check if both maps have the same keys (characters)
    if (word1Map.size() != word2Map.size()) {
        return false;
    }
    for (auto &entry : word1Map) {
        if (word2Map.find(entry.first) == word2Map.end()) {
            return false;
        }
    }

    // Now check if they have the same frequency distribution
    unordered_map<int, int> freqCount1, freqCount2;
    for (auto &entry : word1Map) freqCount1[entry.second]++;
    for (auto &entry : word2Map) freqCount2[entry.second]++;

    // Compare frequency maps
    return freqCount1 == freqCount2;
}
