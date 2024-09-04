Yes, you can solve the problem using a hash map (unordered_map in C++) to store the cumulative sum of nodes along the path, which allows you to efficiently find the number of paths that sum to the target value. This method reduces the time complexity by avoiding the repeated exploration of subtrees.

### Approach:

- Use a hash map to store the cumulative sums encountered as you traverse the tree. The key is the cumulative sum, and the value is the number of times this sum has been encountered.
- At each node, calculate the current cumulative sum.
- To find the number of valid paths that sum to the target, check if `(current cumulative sum - targetSum)` exists in the map.
- Update the hash map with the current cumulative sum.
- Recursively traverse the left and right subtrees.
- After exploring both subtrees, backtrack by removing the current cumulative sum from the hash map to avoid affecting other paths.

### Code Implementation:

```cpp
#include <unordered_map>

class Solution {
public:
    int pathSumHelper(TreeNode* root, long long cumulativeSum, int targetSum, unordered_map<long long, int>& prefixSums) {
        if (!root) return 0;

        // Update the current cumulative sum by adding the current node's value
        cumulativeSum += root->val;

        // Calculate the number of valid paths ending at the current node
        int numPaths = prefixSums[cumulativeSum - targetSum];

        // If the current cumulative sum equals targetSum, there's an additional valid path from the root
        if (cumulativeSum == targetSum) {
            numPaths++;
        }

        // Increment the count of the current cumulative sum in the map
        prefixSums[cumulativeSum]++;

        // Recurse through the left and right children
        numPaths += pathSumHelper(root->left, cumulativeSum, targetSum, prefixSums);
        numPaths += pathSumHelper(root->right, cumulativeSum, targetSum, prefixSums);

        // Backtrack: remove the current cumulative sum from the map as we're done exploring this path
        prefixSums[cumulativeSum]--;

        return numPaths;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSums;  // Map to store cumulative sums and their counts
        return pathSumHelper(root, 0, targetSum, prefixSums);
    }
};
```

### Explanation:

1. **prefixSums Map**: This stores the cumulative sums as keys and their occurrence counts as values. It allows us to quickly determine if there’s a subpath that sums to `targetSum`.

2. **cumulativeSum Calculation**: As you traverse each node, you update the `cumulativeSum` by adding the current node's value.

3. **Finding Valid Paths**: The key insight is that if the difference `(cumulativeSum - targetSum)` exists in `prefixSums`, it indicates that there's a valid path that sums to `targetSum`.

4. **Backtracking**: After exploring both subtrees, the count of the current `cumulativeSum` is decremented to ensure that it does not affect other paths as you backtrack.

### Time Complexity:
- **O(N)**, where N is the number of nodes in the tree. Each node is visited once.

### Space Complexity:
- **O(N)** in the worst case due to the hash map storing the cumulative sums.

This approach is more efficient than the initial one, especially for larger trees, as it avoids redundant calculations and makes the process more streamlined with the use of a hash map.