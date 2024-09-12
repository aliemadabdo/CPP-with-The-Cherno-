/*ONLY 10/71 PASSES [ 61 FAILED !!! ] */
/*NOTE: This solution has a problem with traversing the graph itself */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    enum index{
        src=0, dest
    };

public:

    int DFS(vector<vector<int>>& connections, vector<bool>& isVisited, int city, int destination){
        cout << endl;
        if(city >= connections.size()) return 0;
        
        cout << "isVisited city: " << isVisited[city] << " , " << "isVisited Destination: "  << isVisited[destination] <<  endl;
        cout << "[" << connections[city][0] << "," << connections[city][1] << "]" << endl;
        cout << "city: " << city << " , " << "Destination: "  << destination <<  endl;
        
        if(isVisited[city] || (isVisited[destination] && (destination!=0) )) return 0;

        if(connections[city][dest] == destination){
            cout << "Rotation: NO" << endl;
            isVisited[city] = true;
            return DFS(connections, isVisited, city+1, connections[city][src]);
        }
        else if(connections[city][src] == destination){
            cout << "Rotation: YES" << endl;
            isVisited[city] = true;
            return 1 + DFS(connections, isVisited, city+1, connections[city][dest]);
        }
        else {
            cout << "Destination not found" << endl;
            return 0; 
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        /* DFS may fit */
        int reorders = 0, destination = 0;
        vector<bool> isVisited(n-1, false);

        for(int city=0; city<n-1; city++){
            if(!isVisited[city]){
                reorders += DFS(connections, isVisited, city, destination); 
            }

        }
        return reorders; 
    }
};


int main() {
    Solution solution;

    // Test case 1
    int n1 = 5;
    vector<vector<int>> connections1 = {{0, 1}, {1, 2}, {2, 3}, {4, 0}};
    cout << "Reorders for test case 1: " << solution.minReorder(n1, connections1) << endl;

    // Test case 2
    int n2 = 4;
    vector<vector<int>> connections2 = {{1, 0}, {1, 2}, {3, 2}};
    cout << "Reorders for test case 2: " << solution.minReorder(n2, connections2) << endl;

    // Test case 3
    int n3 = 3;
    vector<vector<int>> connections3 = {{0, 1}, {2, 0}};
    cout << "Reorders for test case 3: " << solution.minReorder(n3, connections3) << endl;

    return 0;
}