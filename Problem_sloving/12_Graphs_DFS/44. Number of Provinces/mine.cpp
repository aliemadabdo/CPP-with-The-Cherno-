/*
This solution efficiently solves the Number of Provinces problem using DFS. 
By marking cities as visited and traversing all connected components,
we can easily count the number of provinces. The time complexity is O(N^2), 
making it suitable for moderate-sized graphs like those encountered in this problem.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    void connectGraph_DFS(vector<vector<int>>& isConnected, vector<bool>& isVisited, int city){
        for(int neighbour=city; neighbour<isConnected.size(); neighbour++){
            if(isConnected[city][neighbour]){
                if(!isVisited[neighbour]){
                    isVisited[neighbour] = true;
                    connectGraph_DFS(isConnected, isVisited, neighbour);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfCities = isConnected.size();

        int provinces = 0;
        vector<bool> isVisited(numOfCities, false);

        for(int city=0; city<numOfCities; city++){
            if(!isVisited[city]){
                connectGraph_DFS(isConnected, isVisited, city);
                provinces++;
            }
        }               

        return provinces;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case: adjacency matrix for 15 cities
    vector<vector<int>> isConnected = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    // Call the findCircleNum function and print the result
    cout << "Number of Provinces: " << solution.findCircleNum(isConnected) << endl;

    return 0;
}