#include <iostream>

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
    int pathSum(TreeNode* root, int targetSum) {
        
    }
};

int main() {
    // Create a test binary tree:
    //        10
    //       /  \
    //      5   -3
    //     / \    \
    //    3   2   11
    //   / \   \
    //  3  -2   1
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 8;
    int result = solution.pathSum(root, targetSum);
    
    cout << "Number of paths with sum " << targetSum << ": " << result << endl;

    // Clean up the memory
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}


