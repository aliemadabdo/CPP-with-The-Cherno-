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

int getGoodNodes(TreeNode* root, int max){
    if(!root) return 0;

    int goodNodesCount  = 0;

    if(root->val >= max){
        goodNodesCount ++;
        max = root->val;
    }

    goodNodesCount  += getGoodNodes(root->left, max);
    goodNodesCount  += getGoodNodes(root->right, max);

    return goodNodesCount;
}

class Solution {
public:
    int goodNodes(TreeNode* root) {    
        return getGoodNodes(root, root->val);
    }
};

// Main function to test the code
int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    // Create a solution object
    Solution sol;

    // Call the goodNodes function and print the result
    int result = sol.goodNodes(root);
    cout << "Number of good nodes: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}