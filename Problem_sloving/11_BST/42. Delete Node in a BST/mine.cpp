
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

    TreeNode* getKey(TreeNode* root, int key) {
        TreeNode *current = root;

        while(current){
            if(key < current->val) current = current->left;            
            else if(key > current->val) current = current->right;            
            else{
                return current;
            }
        }

        return nullptr; // key not found
    }
    
    TreeNode* getKeyParent(TreeNode* root, int key) {
        TreeNode* current = root;

        if (!current || current->val == key) return nullptr; // No parent if root is the key

        while (current) {
            // Check if the current node's left or right child is the target node
            if (current->left && current->left->val == key) {
                return current; // Found the parent
            }
            if (current->right && current->right->val == key) {
                return current; // Found the parent
            }

            // Continue traversing the tree
            if (key < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return nullptr; // Parent not found, meaning key doesn't exist in the tree
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        // Empty tree
        if (!root) return root; 

        TreeNode* nodeToDelete = getKey(root, key);

        // Key not found
        if(!nodeToDelete) return root;

        // One node tree - Key found
        if(nodeToDelete == root && !nodeToDelete->left && !nodeToDelete->right) return nullptr;

        TreeNode* nodeToDeleteParent = getKeyParent(root, nodeToDelete->val);

        TreeNode *replacedNode, *replacedNodeParent;
        // More than one node trees
        while(nodeToDelete){

            if(nodeToDelete->right){
                replacedNode = nodeToDelete->right; // get the initial replacement node
                replacedNodeParent = nodeToDelete; // get the initial replacement node parent
                
                //get min and min parent
                if(replacedNode->left){ // to let the parent catch the path
                        replacedNode = replacedNode->left; // get the next replacement node
                        replacedNodeParent = replacedNodeParent->right; // get the next replacement node parent
                  
                    // itirate over the rest of the nodes to get the one to replace and its parent
                    while(replacedNode->left){ 
                        replacedNode = replacedNode->left;
                        replacedNodeParent = replacedNodeParent->left;
                    }
                }
                nodeToDelete->val = replacedNode->val; // The replacement step
                nodeToDelete = replacedNode; // Get the new key step
                nodeToDeleteParent = replacedNodeParent;
            }

            else if(nodeToDelete->left){
                replacedNode = nodeToDelete->left;
                replacedNodeParent = nodeToDelete;
                
                //get max and max parent
                if(replacedNode->right){ // to let the parent catch the path
                        replacedNode = replacedNode->right;
                        replacedNodeParent = replacedNodeParent->left;
                 
                    while(replacedNode->right){
                        replacedNode = replacedNode->right;
                        replacedNodeParent = replacedNodeParent->right;
                    }
                }
                nodeToDelete->val = replacedNode->val;
                nodeToDelete = replacedNode;
                nodeToDeleteParent = replacedNodeParent;

            }
            // last node deletion (no replacement needed).
            else{ 
                if(nodeToDeleteParent->left == nodeToDelete) 
                    nodeToDeleteParent->left = nullptr;
                else 
                    nodeToDeleteParent->right = nullptr;
                
                return root; // or just break; 
            }

        }

        return root;
    }
};

// Function to do in-order traversal of the tree
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Create a binary search tree
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    // Print the tree before deletion
    cout << "In-order traversal before deletion: ";
    inorder(root);
    cout << endl;

    Solution solution;
    // Delete the node with key 80
    solution.deleteNode(root, 80);

    // Print the tree after deletion
    cout << "In-order traversal after deletion: ";
    inorder(root);
    cout << endl;

    // Clean up memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}