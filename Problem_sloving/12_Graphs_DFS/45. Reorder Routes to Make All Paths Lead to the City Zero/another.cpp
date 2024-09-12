/* This is the only solution that passes the TLE error */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Adjacency list for original and reverse graph
        unordered_map<int, vector<pair<int, bool>>> adjList;

        // Fill the adjacency list with roads
        // Pair: (connected city, isOriginalDirection)
        for (auto& connection : connections) {
            adjList[connection[0]].emplace_back(connection[1], true);  // original direction (0 -> 1)
            adjList[connection[1]].emplace_back(connection[0], false); // reverse direction (1 -> 0)
        }

        vector<bool> visited(n, false);
        return dfs(0, adjList, visited);
    }

private:
    int dfs(int node, unordered_map<int, vector<pair<int, bool>>>& adjList, vector<bool>& visited) {
        visited[node] = true;
        int reorderCount = 0;

        // Explore neighbors
        for (auto& neighbor : adjList[node]) {
            int nextCity = neighbor.first;
            bool isOriginalDirection = neighbor.second;

            if (!visited[nextCity]) {
                // If the road is in the original direction, we need to reorder it
                if (isOriginalDirection) reorderCount++;

                // Recursively visit the next city
                reorderCount += dfs(nextCity, adjList, visited);
            }
        }

        return reorderCount;
    }
};

int main() {
    Solution solution;

    // Test case 1
    int n1 = 6;
    vector<vector<int>> connections1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << "Test case 1 result: " << solution.minReorder(n1, connections1) << endl;  // Expected: 3

    // Test case 2
    int n2 = 5;
    vector<vector<int>> connections2 = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    cout << "Test case 2 result: " << solution.minReorder(n2, connections2) << endl;  // Expected: 2

    // Test case 3
    int n3 = 3;
    vector<vector<int>> connections3 = {{1, 0}, {2, 0}};
    cout << "Test case 3 result: " << solution.minReorder(n3, connections3) << endl;  // Expected: 0

    // Test case 4
    int n4 = 4;
    vector<vector<int>> connections4 = {{0, 1}, {1, 2}, {3, 2}};
    cout << "Test case 4 result: " << solution.minReorder(n4, connections4) << endl;  // Expected: 2

    // Test case 5
    int n5 = 5;
    vector<vector<int>> connections5 = {{4, 3}, {3, 2}, {2, 1}, {1, 0}};
    cout << "Test case 5 result: " << solution.minReorder(n5, connections5) << endl;  // Expected: 4

    return 0;
}
