#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct the graph adjacency matrix
        // search for queries elements in the matrix 
        // if not found at all or found but not in the same graph then write -1 to the result vector
        // else write the result of the operation in the result vector

        // how to construct this graph, and do we realy need this conversion?
        // how to search in the matrix efficintly
        // how to calculate the result of the query if found

        // after the first row is filled we can allocate the rest of the columns
        
        //But first we need a map the string values to matrix indices
        unordered_map <string, int> locations;

        for(int i=0; i<equations.size(); i++){
            // if not found i++
            locations[equations[i][0]] = i;
            // if not found i++
            locations[equations[i][1]] = i;    
        }

        int numOfstrings = locations.size();
        // This will be weighted directed graph 
        vector<vector<int>> connections(numOfstrings, vector<int>(numOfstrings, 0));
        
        for (int i=0; i<numOfstrings; i++ ){
            for (int j=0; j<numOfstrings; j++ ){
                
                connections[locations[equations[i][0]]][locations[equations[i][1]]] = values[i];
                connections[locations[equations[i][1]]][locations[equations[i][0]]] = 1/values[i];

            }
        }


    }
};

// Main function to test the calcEquation function
int main() {
    Solution sol;

    // Test case 1
    vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result1 = sol.calcEquation(equations1, values1, queries1);

    cout << "Test Case 1 Results: ";
    for (double r : result1) {
        cout << r << " ";
    }
    cout << endl;

    // Test case 2
    vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};

    vector<double> result2 = sol.calcEquation(equations2, values2, queries2);

    cout << "Test Case 2 Results: ";
    for (double r : result2) {
        cout << r << " ";
    }
    cout << endl;

    // Test case 3
    vector<vector<string>> equations3 = {{"a", "b"}};
    vector<double> values3 = {0.5};
    vector<vector<string>> queries3 = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};

    vector<double> result3 = sol.calcEquation(equations3, values3, queries3);

    cout << "Test Case 3 Results: ";
    for (double r : result3) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}