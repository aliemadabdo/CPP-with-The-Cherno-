// THE WAY I THINKED
// start with rotten (not visited) oranges
// We may set the rotten and visited oranges with value 3 [canceled]
// If we have more than one rotten orange we will neeed to count in parallel with a vector of BFS 
// I have asked chatGPT if the problem may start with many rotten oranges and this was his answer:
// Yes, the Rotting Oranges problem can definitely have more than one rotten orange at the 
// beginning. The algorithm should handle this case seamlessly because we add all initially 
// rotten oranges to the queue at the start of the BFS. This ensures that the rotting 
// process happens simultaneously for all rotten oranges, simulating multiple spreading 
// sources in the grid.
// That was insightful, we do not need any paralizations we will only push all rotten nodes at the start.
// Number of minutes represents the levels needed until we reach all nodes.
// If their are any unreachable nodes return -1.
// At the end, apply a linear search for any node with value 1, if found return -1.


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;

        queue<vector<int>> bfs;
        int length = grid.size(), width = grid[0].size(), totalMinutes = 0;
        bool hasAnyFresh = false;

        for (int i=0; i<length; i++){
            for (int j=0; j<width; j++){
                if (grid[i][j] == 2) bfs.push({i,j,0}); 
                else if (grid[i][j] == 1) hasAnyFresh = true;
            }
        }

        if(!hasAnyFresh) return 0;
        if(bfs.empty()) return -1;

        while(!bfs.empty()){
            int i = bfs.front()[0];
            int j = bfs.front()[1];
            int minutes = bfs.front()[2];

            if(minutes > totalMinutes) totalMinutes = minutes;
            bfs.pop();
    
            if (i < length-1 && grid[i+1][j] == 1) {
                bfs.push({i+1, j, minutes+1});
                grid[i+1][j] = 2; // mark as visited
            }
            if (i > 0 && grid[i-1][j] == 1){
                bfs.push({i-1, j, minutes+1});
                grid[i-1][j] = 2; // mark as visited
            }
            if (j < width-1 && grid[i][j+1] == 1){
                bfs.push({i, j+1, minutes+1});
                grid[i][j+1] = 2; // mark as visited
            }            
            if (j > 0 && grid[i][j-1] == 1){
                bfs.push({i, j-1, minutes+1});
                grid[i][j-1] = 2; // mark as visited
            }
        }

        for (int i=0; i<length; i++){
            for (int j=0; j<width; j++){
                if (grid[i][j] == 1) return -1; 
            }
        }

        return totalMinutes;
                
    }
};

int main() {
    Solution solution;

    // Test case 1: Simple case with one rotten orange
    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << "Test Case 1: " << solution.orangesRotting(grid1) << endl;  // Expected output: 4

    // Test case 2: Case where all oranges are already rotten
    vector<vector<int>> grid2 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    cout << "Test Case 2: " << solution.orangesRotting(grid2) << endl;  // Expected output: 0

    // Test case 3: Case where it's impossible to rot all oranges
    vector<vector<int>> grid3 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };
    cout << "Test Case 3: " << solution.orangesRotting(grid3) << endl;  // Expected output: -1

    // Test case 4: Case with no rotten oranges at the start
    vector<vector<int>> grid4 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    cout << "Test Case 4: " << solution.orangesRotting(grid4) << endl;  // Expected output: -1

    // Test case 5: Case where grid is empty
    vector<vector<int>> grid5 = {};
    cout << "Test Case 5: " << solution.orangesRotting(grid5) << endl;  // Expected output: -1

    return 0;
}
