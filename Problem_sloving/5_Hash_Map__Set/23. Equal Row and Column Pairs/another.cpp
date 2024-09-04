/*
### Explanation of Optimizations

1. **Hashing Rows and Columns:**
   - We use a string-based hash map to count occurrences of row and column patterns. The `toKey` function converts each row or column into a string key which allows easy comparison and counting.
   
2. **Efficient Column Construction:**
   - Instead of building columns in a separate loop, we directly construct column vectors and convert them to keys.

3. **Counting Matching Pairs:**
   - Instead of comparing every row with every column, we count occurrences and then compute matches based on the counts. This reduces the complexity to linear time with respect to the number of rows and columns.

### Complexity

- **Time Complexity:** \(O(n^2)\) due to iterating over rows and columns and constructing keys.
- **Space Complexity:** \(O(n^2)\) for storing row and column hashes.
*/

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
        std::cout << std::endl;
    }
}

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rowMap;
        unordered_map<string, int> colMap;
        int n = grid.size(); // Number of rows and columns (assuming a square grid)
        string rowKey, colKey;

        // Function to convert vector to string for easy comparison
        auto toKey = [](const vector<int>& vec) -> string {
            string key;
            for (int num : vec) {
                key += to_string(num) + ",";
            }
            return key;
        };

        // Count occurrences of each row
        for (int i = 0; i < n; ++i) {
            rowKey = toKey(grid[i]);
            ++rowMap[rowKey];
        }

        // Count occurrences of each column
        for (int j = 0; j < n; ++j) {
            vector<int> col(n);
            for (int i = 0; i < n; ++i) {
                col[i] = grid[i][j];
            }
            colKey = toKey(col);
            ++colMap[colKey];
        }

        // Calculate the number of equal row-column pairs
        int result = 0;
        for (const auto& [key, rowCount] : rowMap) {
            if (colMap.find(key) != colMap.end()) {
                result += rowCount * colMap[key];
            }
        }

        return result;
    }
};

int main() {
    // Initialize a 2D vector (grid)
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
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
