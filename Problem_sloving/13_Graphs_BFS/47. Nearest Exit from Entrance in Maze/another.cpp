// chat gpt level-based solution seams to be more complex in time and readability

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        
        // Directions for moving in the maze: up, down, left, right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Initialize the BFS queue
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        
        // Mark the entrance as visited
        maze[entrance[0]][entrance[1]] = '+';
        
        // BFS to find the nearest exit
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            
            // Process the current level
            for (int k = 0; k < size; k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Explore in all four possible directions
                for (auto& dir : directions) {
                    int newI = i + dir.first;
                    int newJ = j + dir.second;
                    
                    // Check if the new position is within bounds and is an open path
                    if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && maze[newI][newJ] == '.') {
                        // If the new position is on the boundary and not the entrance, it's an exit
                        if (newI == 0 || newI == m - 1 || newJ == 0 || newJ == n - 1) {
                            return steps;
                        }
                        // Mark the cell as visited and add it to the queue
                        maze[newI][newJ] = '+';
                        q.push({newI, newJ});
                    }
                }
            }
        }
        
        // No exit found
        return -1;
    }
};

int main() {
    Solution solution;

    // Example 1: Simple Maze with a reachable exit
    vector<vector<char>> maze1 = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };
    vector<int> entrance1 = {1, 0}; // Starting point at (1, 0)

    int result1 = solution.nearestExit(maze1, entrance1);
    cout << "The shortest path to the nearest exit in maze1 is: " << result1 << endl;

    // Example 2: Maze with no exit reachable
    vector<vector<char>> maze2 = {
        {'+', '+', '+', '+'},
        {'+', '.', '.', '+'},
        {'+', '+', '+', '+'}
    };
    vector<int> entrance2 = {1, 1}; // Starting point at (1, 1)

    int result2 = solution.nearestExit(maze2, entrance2);
    cout << "The shortest path to the nearest exit in maze2 is: " << result2 << endl;

    // Example 3: Larger Maze
    vector<vector<char>> maze3 = {
        {'.', '+', '+', '+', '+'},
        {'.', '.', '.', '+', '.'},
        {'.', '+', '.', '.', '.'},
        {'+', '.', '+', '+', '+'},
        {'.', '.', '.', '+', '+'}
    };
    vector<int> entrance3 = {2, 2}; // Starting point at (2, 2)

    int result3 = solution.nearestExit(maze3, entrance3);
    cout << "The shortest path to the nearest exit in maze3 is: " << result3 << endl;

    return 0;
}
