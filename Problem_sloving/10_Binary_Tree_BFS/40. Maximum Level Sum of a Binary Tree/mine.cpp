#include <iostream>
#include <queue>  // For BFS(level order traversal)
#include <limits.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1, level = 1, maxLevelVal = INT_MIN;
        queue<TreeNode*> bfs;

        bfs.push(root);

        while(!bfs.empty()){
            int levelSize = bfs.size();
            int levelVal = 0;
            
            for(int i=0; i < levelSize; i++){
                TreeNode* node = bfs.front();
                bfs.pop();

                levelVal += node->val; 

                if(node->left) bfs.push(node->left);
                if(node->right) bfs.push(node->right);
            }

            if(levelVal > maxLevelVal){
                maxLevelVal = levelVal;
                maxLevel = level;
            }

            level++;
        } 
        return maxLevel;
    }
};


int main() {
    // Creating the binary tree:
    //       1
    //     /   \
    //    7     0
    //   / \   / \
    //  7  -8  6  1

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(1);

    Solution sol;
    int result = sol.maxLevelSum(root);

    // Output the level with the maximum sum
    cout << "Level with the maximum sum: " << result << endl;

    return 0;
}