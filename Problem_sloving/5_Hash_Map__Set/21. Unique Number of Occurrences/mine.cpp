#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdbool.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> counters;      
        unordered_map<int, bool> checker;

        // unordered_map<int, unordered_map<int, bool>> countCheckMap;      
        
        for(int i=0; i<arr.size(); i++){
            // counters.emplace(arr[i], ++counters[arr[i]]); same as the following 
            // emplace does not change the initial value
            counters[arr[i]]++;
        }

        for(auto it = counters.begin(); it != counters.end(); it++){
            
            if (checker[it->second] == true){
                return false;
            }

            checker[it->second] = true; // Mark this occurrence count as seen
        }

        return true;
    }
};


int main() {
    Solution solution;

    // Test case 1
    vector<int> test1 = {1, 2, 2, 1, 1, 3};
    cout << "Test case 1: " << (solution.uniqueOccurrences(test1) ? "True" : "False") << endl;

    // Test case 2
    vector<int> test2 = {1, 2};
    cout << "Test case 2: " << (solution.uniqueOccurrences(test2) ? "True" : "False") << endl;

    // Test case 3
    vector<int> test3 = {3, 5, -2, -2, 3, 3};
    cout << "Test case 3: " << (solution.uniqueOccurrences(test3) ? "True" : "False") << endl;

    // Test case 4
    vector<int> test4 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Test case 4: " << (solution.uniqueOccurrences(test4) ? "True" : "False") << endl;

    return 0;
}
