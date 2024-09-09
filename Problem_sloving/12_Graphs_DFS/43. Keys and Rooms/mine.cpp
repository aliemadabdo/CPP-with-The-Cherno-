#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false), allVisited(rooms.size(), true);
         // If you know the maximum needed size for the queue,
        // then using a std::vector with reserve() becomes a very 
        // efficient option because it allows you to avoid costly reallocations
        // BUT you will not be able to use pop in vector-based queue
        
        queue<int> keys;

        keys.push(0);

        while(!keys.empty()){
            int key = keys.front();
            keys.pop();

            if(!visited[key]) {
                visited[key] = true;
                
                for (int i=0; i<rooms[key].size(); i++){
                    if(!visited[rooms[key][i]]) keys.push(rooms[key][i]);
                }
            }
        }

        if(visited == allVisited ) return true;

        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: All rooms can be visited
    vector<vector<int>> rooms1 = {{1}, {2}, {3}, {}};
    if (solution.canVisitAllRooms(rooms1)) {
        cout << "All rooms can be visited in test case 1!" << endl;
    } else {
        cout << "Not all rooms can be visited in test case 1." << endl;
    }

    // Test case 2: Not all rooms can be visited
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    if (solution.canVisitAllRooms(rooms2)) {
        cout << "All rooms can be visited in test case 2!" << endl;
    } else {
        cout << "Not all rooms can be visited in test case 2." << endl;
    }

    return 0;
}