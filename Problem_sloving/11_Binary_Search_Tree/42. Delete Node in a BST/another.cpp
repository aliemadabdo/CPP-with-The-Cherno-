// This is the requierd solution with T.C = O(log(n))

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Main function to delete a node with the given key
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root; // If root is null, return null

        // Search for the node to delete
        if (key < root->val) {
            // Key is in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // Key is in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Node with the key is found
            if (!root->left && !root->right) {
                // Case 1: Node has no children (leaf node)
                delete root;
                return nullptr;
            } else if (!root->left) {
                // Case 2: Node has only right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                // Case 2: Node has only left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Case 3: Node has two children
                // Find the in-order successor (smallest in the right subtree)
                TreeNode* temp = findMin(root->right);
                // Copy the value of the successor to the current node
                root->val = temp->val;
                // Delete the successor
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};
