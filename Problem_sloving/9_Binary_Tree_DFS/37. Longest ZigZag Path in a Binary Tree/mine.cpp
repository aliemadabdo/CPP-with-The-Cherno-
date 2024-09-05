#include <iostream>
#include <stack>

using namespace std;

// constexpr bool LEFT = false;
// constexpr bool RIGHT = true;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    enum directions {
        LEFT = 0, RIGHT
    };

public:

    void maxZigZag(TreeNode* node, directions direction, int &maxZigZagLength, int zigZagLength){
        if(!node) return;

        maxZigZagLength = max(maxZigZagLength, zigZagLength);

        if(node->left){
            if(direction == LEFT){
                maxZigZag(node->left, RIGHT, maxZigZagLength, zigZagLength+1);
            } 
            else{
                maxZigZag(node->left, RIGHT, maxZigZagLength, 1); // zigZagLength is 1 because we are coming from root actually
            }
        }
        
        if(node->right){
            if(direction == RIGHT){
                maxZigZag(node->right, LEFT, maxZigZagLength, zigZagLength+1);
            } 
            else{
                maxZigZag(node->right, LEFT, maxZigZagLength, 1);
            }
        }
    }

    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        
        int max = 0;

        maxZigZag(root, RIGHT, max, 0);
        maxZigZag(root, LEFT, max, 0);

        return max;
    }
};


int main() {
    // Creating a test binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->left->right->left->right = new TreeNode(7);

    Solution solution;
    int result = solution.longestZigZag(root);
    
    cout << "Longest ZigZag path length: " << result << endl;

    // Clean up memory
    delete root->left->right->left->right;
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}