/* Stopped solving this problem due to:
 high time and memory complexity i used 
 and the need for exploring more about the adjecancy list graph
 in addation for taking too much time (2 days)
 
 what i have leant:
 - creating graph
 - dealing with string-based graphs
 - dfs with graphs
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    double dfs(const string& start, const string& end, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string> isVisited){
        if (graph.find(start) == graph.end()) return -1.0;
        if (start == end) return 1.0;
        
        isVisited.insert(start);
        
        for (const auto& neighbor : graph[start]) {
            const string& next = neighbor.first;
            double value = neighbor.second;
            
            if (isVisited.find(next) == isVisited.end()) {
                double result = dfs(next, end, graph, isVisited);
                if (result != -1.0) {
                    return result * value;
                }
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct the graph adjacency matrix
        // search for queries elements in the matrix 
        // if not found at all or found but not in the same graph then write -1 to the result vector
        // else write the result of the operation in the result vector

        // how to construct this graph, and do we realy need this conversion?
        // how to search in the matrix efficintly
        // how to calculate the result of the query if found

        // // after the first row is filled we can allocate the rest of the columns
        
        // //But first we need a map the string values to matrix indices
        // unordered_map <string, int> locations;
        // int numOfEqns = equations.size();
        
        // for(int i=0; i<numOfEqns; i++){
        //     for(int j=0; j<2; j++)
        //         locations[equations[i][j]] = i*numOfEqns + j;    
        // }

        // // or we shall just use 2*equations.size() square matrix 
        
        // // This will be weighted directed graph 
        // vector<vector<int>> connections(2*numOfEqns, vector<int>(2*numOfEqns, 0));
        
        // for (int i=0; i<2*numOfEqns; i++ ){
        //     for (int j=0; j<numOfEqns; j++ ){
        //         for(int k=0; k<2; k++){
                    
        //             connections[locations[equations[i][k]]][locations[equations[j][k]]] = values[j]; 

        //             connections[locations[equations[i][k]]][locations[equations[j][0]]] = 1/values[j];

        //         }
        //     }
        // }

        // Graph to store the equations
        unordered_map<string, vector<pair<string, double>>> graph; // you have to think abou the pair from the first 
                                                                   // any reused letters are now unique by its weight     
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double value = values[i];
            graph[A].emplace_back(B, value);
            graph[B].emplace_back(A, 1.0 / value);
        }

        vector<double> result;
        for (const auto& query : queries) {
            string C = query[0];
            string D = query[1];
            
            // If either variable doesn't exist in the graph
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                result.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double res = dfs(C, D, graph, visited);
                result.push_back(res);
            }
        }

        return result;


    }
};

// 

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