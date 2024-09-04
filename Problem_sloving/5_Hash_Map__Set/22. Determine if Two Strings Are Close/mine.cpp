#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdbool.h>

using namespace std;

template <typename K, typename V>
void printMap(const unordered_map<K, V>& m) {
    for (const auto& pair : m) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

template <typename T>
void printUnorderedMultiset(const unordered_multiset<T>& ms) {
    for (const auto& elem : ms) {
        cout << elem << " ";
    }
    cout << endl;
}

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()){
            return false;
        }
        
        unordered_map<char, int> word1Map;
        unordered_map<char, int> word2Map;
        unordered_multiset<int> word2ValuesSet;

        for(int i=0; i<word1.size(); i++){
            word1Map[word1[i]]++;
        }

        cout << "1st word:";
        printMap(word1Map);
        
        for(int i=0; i<word2.size(); i++){
            if(word1Map.find(word2[i]) == word1Map.end()){
                return false;
            }
            word2Map[word2[i]]++;
        }

        cout << "2nd word:";
        printMap(word2Map);

        for(auto it = word2Map.begin(); it != word2Map.end(); it++){
            word2ValuesSet.insert(it->second);
        }
        

        for(auto itr = word1Map.begin(); itr != word1Map.end(); itr++){
            cout << "is " << itr->second << " in: \n";
            printUnorderedMultiset(word2ValuesSet);

            auto found = word2ValuesSet.find(itr->second);
            
            if( found == word2ValuesSet.end()){
                return false;
            }
            else{
                word2ValuesSet.erase(found);
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<pair<string, string>> testCases = {
        {"abc", "bca"},
        {"aabbcc", "abcabc"},
        {"abc", "def"},
        {"abc", "ab"},
        {"abb", "bba"},
        {"abcd", "abdd"}
    };

    for(auto& testCase : testCases) {
        bool result = solution.closeStrings(testCase.first, testCase.second);
        cout << "Are \"" << testCase.first << "\" and \"" << testCase.second << "\" close strings? " 
             << (result ? "Yes" : "No") << endl;
    }

    return 0;
}