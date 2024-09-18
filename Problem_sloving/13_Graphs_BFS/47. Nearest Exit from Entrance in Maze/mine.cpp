// We can use BFS to find the shortest path in a graph.
// From the entry point we start the search until we find an exit or the graph ends (return -1).
// The idea is just about implementing the bfs.
// The trversal could be by adding +or- 1 to rows or cols and push them to the queue (not stack).
// No recursion needed in this approach (may be implemented as another solution).
// We can know the end if i = 0 or m-1 or j = 0 or n-1
// How to count for the path length (equivelant to graph level)?
// We will just push it within the queue of vector instead of just using a pair for index.
 
#include <iostream>
#include <vector>
#include <queue>
#include <utility>  // For std::pair and std::make_pair

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        if(entrance.empty()) return -1;
        
        queue<vector<int>> index;
        int pathLength = 0, length = maze.size(), width = maze[0].size();

        index.push({entrance[0],entrance[1], pathLength});
        maze[entrance[0]][entrance[1]] = '+'; // mark as visited

        while(!index.empty()){
            int i = index.front()[0];
            int j = index.front()[1];
            pathLength = index.front()[2];
            index.pop();

            if((i == 0 || i == length-1 || j == 0 || j == width-1) && !(i == entrance[0] && j == entrance[1])) return pathLength;
            

            if (i < length-1 && maze[i+1][j] == '.') {
                index.push({i+1, j, pathLength+1});
                maze[i+1][j] = '+'; // mark as visited
            }
            if (i > 0 && maze[i-1][j] == '.'){
                index.push({i-1, j, pathLength+1});
                maze[i-1][j] = '+'; // mark as visited
            }
            if (j < width-1 && maze[i][j+1] == '.'){
                index.push({i, j+1, pathLength+1});
                maze[i][j+1] = '+'; // mark as visited
            }            
            if (j > 0 && maze[i][j-1] == '.'){
                index.push({i, j-1, pathLength+1});
                maze[i][j-1] = '+'; // mark as visited
            }
        }

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
