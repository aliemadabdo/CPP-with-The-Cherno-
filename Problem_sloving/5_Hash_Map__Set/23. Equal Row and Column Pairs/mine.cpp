#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to print a 2D vector (matrix)
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl; // Move to the next line after printing a row
    }
}

// Function to print a hash map where the value is a vector
template <typename KeyType, typename ValueType>
void printMap(const unordered_map<KeyType, ValueType>& map) {
    for (const auto& pair : map) {
        cout << "Key " << pair.first << ": ";
        for (const auto& val : pair.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int result = 0;
        unordered_map<int, vector<int>> rowsMap;
        unordered_map<int, vector<int>> colsMap;

        // cout << "grid size 2d: " << grid.size() << "| row in grid size 1d: " << grid[0].size() << "\n";
        
        // store all rows and cols in hash maps [O(n^2)]
        for(int i=0; i<grid.size(); i++){

            rowsMap[i] = grid[i];
            vector<int> col;
            
            for(int j=0; j<grid[0].size(); j++){
                col.push_back(grid[j][i]);
            }

            colsMap[i] = col;

        }

        // printMap(rowsMap);
        // printMap(colsMap);

        // compare each value of both maps to each other [O(n^2)]
        for(auto it_r = rowsMap.begin(); it_r != rowsMap.end(); it_r++){
            for(auto it_c = colsMap.begin(); it_c != colsMap.end(); it_c++){
                if(it_r->second == it_c->second ){
                    result++;
                }
            }
        }

        return result;      
    }
};


int main() {
    // Initialize a 2D vector (grid)
    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 5, 6},
        {3, 8, 9}
    };

    // Create a Solution object
    Solution solution;

    // Print the grid
    cout << "Original Grid:" << endl;
    printMatrix(grid);

    // Call equalPairs and print the result
    int result = solution.equalPairs(grid);
    cout << "Number of equal row-column pairs: " << result << endl;

    return 0;
}