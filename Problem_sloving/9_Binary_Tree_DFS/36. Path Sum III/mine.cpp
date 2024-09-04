#include <iostream>
#include <stack>

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

    int getNodePaths(TreeNode* root, int targetSum){
        if(!root) return 0;

        int nodePaths = 0;

        targetSum -= root->val;
        if(targetSum == 0) return 1;

        nodePaths += getNodePaths(root->left, targetSum);
        nodePaths += getNodePaths(root->right, targetSum);

        return nodePaths; 
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int paths = 0;
        stack<TreeNode*> tree;

        tree.push(root);
        while(!tree.empty()){ // DFS LOOP to search for each node
            TreeNode* subRoot = tree.top();
            tree.pop();

            paths += getNodePaths(subRoot, targetSum); // DFS Recursion to get number of paths which meats the target sum from this node

            if(subRoot->right) tree.push(subRoot->right);    
            if(subRoot->left) tree.push(subRoot->left);    
        }

        return paths;
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


