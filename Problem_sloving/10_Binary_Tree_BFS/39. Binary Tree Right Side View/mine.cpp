// Pass 212/216 test case but fails due to Memory Limit Exceeded error.
// Cause:  The vectorizedTree grows exponentially with the depth of the tree
//         due to the 2^level calculations, which can lead to excessive memory usage. 

#include <iostream>
#include <vector>
#include <math.h>

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
private:
    
    // Function to print a vector of TreeNode pointers
    void printVector(const std::vector<TreeNode*>& vectorizedTree) {
        std::cout << "Tree in vector form: ";
        for (const auto& node : vectorizedTree) {
            if (node != nullptr) {
                std::cout << node->val << " "; // Print the value if node is not null
            } else {
                std::cout << "null "; // Print 'null' if the node is nullptr
            }
        }
        std::cout << std::endl;
    }

public:

    void treeToVector(TreeNode* node, vector<TreeNode*> &vectorizedTree, int index){
        if(!node) return;

        if(index >= vectorizedTree.size()){
            vectorizedTree.resize(index+1, nullptr);
        }

        vectorizedTree[index] = node;

        if(node->left){
            treeToVector(node->left, vectorizedTree, 2*index+1);
        }
        if(node->right){
            treeToVector(node->right, vectorizedTree, 2*index+2);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        vector<TreeNode*> vectorizedTree;
        
        if(!root) return rightSide;
        
        treeToVector(root, vectorizedTree, 0);

        int vectorSize = vectorizedTree.size();
        int level = 0, selectedNode = vectorizedTree[0]->val;
        int levelStart = pow(2,level)-1;
        int levelEnd = pow(2,level+1)-1;


        while(levelStart < vectorSize){ 
            for(int i=levelStart; i < levelEnd; i++){
                if(i >= vectorSize) break;

                if(vectorizedTree[i] != nullptr){
                    selectedNode = vectorizedTree[i]->val;
                }
            }
            
            rightSide.emplace_back(selectedNode);
            
            level++;
            levelStart = pow(2,level)-1;
            levelEnd = pow(2,level+1)-1;

        }
        return rightSide;
    }
};


int main() {
    // Creating the binary tree:
    //       1
    //     /   \
    //    2     3
    //     \      \
    //      5      4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> rightSideView = sol.rightSideView(root);

    // Output the right side view
    cout << "Right side view of the tree: ";
    for (int val : rightSideView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}