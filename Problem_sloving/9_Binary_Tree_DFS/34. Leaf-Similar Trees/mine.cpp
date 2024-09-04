#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getTreeLeaves(TreeNode* root, vector<int>* leaves){
    bool hasLeftNode = false, hasRightNode = false;
    
    if(root->left){
        hasLeftNode = true;
        getTreeLeaves(root->left, leaves);
    }

    if(root->right){
        hasRightNode = true;
        getTreeLeaves(root->right, leaves);
    }

    if(!hasLeftNode && !hasRightNode){
        leaves->emplace_back(root->val);
    }
}

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        if(!root1 || !root2) return false;
        
        vector<int> leaves1, leaves2;

        getTreeLeaves(root1, &leaves1);
        getTreeLeaves(root2, &leaves2);

        return leaves1 == leaves2;

    }
};

int main() {
    Solution solution;

    // Test Case 1: Identical trees
    TreeNode* root1_1 = new TreeNode(3);
    root1_1->left = new TreeNode(5);
    root1_1->right = new TreeNode(1);
    root1_1->left->left = new TreeNode(6);
    root1_1->left->right = new TreeNode(2);
    root1_1->right->left = new TreeNode(9);
    root1_1->right->right = new TreeNode(8);
    root1_1->left->right->left = new TreeNode(7);
    root1_1->left->right->right = new TreeNode(4);

    TreeNode* root1_2 = new TreeNode(3);
    root1_2->left = new TreeNode(5);
    root1_2->right = new TreeNode(1);
    root1_2->left->left = new TreeNode(6);
    root1_2->left->right = new TreeNode(2);
    root1_2->right->left = new TreeNode(9);
    root1_2->right->right = new TreeNode(8);
    root1_2->left->right->left = new TreeNode(7);
    root1_2->left->right->right = new TreeNode(4);

    cout << "Test Case 1: ";
    cout << (solution.leafSimilar(root1_1, root1_2) ? "Pass" : "Fail") << endl;

    // Test Case 2: Different leaves
    TreeNode* root2_1 = new TreeNode(3);
    root2_1->left = new TreeNode(5);
    root2_1->right = new TreeNode(1);
    root2_1->left->left = new TreeNode(6);
    root2_1->right->right = new TreeNode(2);
    root2_1->right->right->right = new TreeNode(4);

    TreeNode* root2_2 = new TreeNode(3);
    root2_2->left = new TreeNode(5);
    root2_2->right = new TreeNode(1);
    root2_2->right->right = new TreeNode(2);
    root2_2->right->right->left = new TreeNode(9);
    root2_2->right->right->right = new TreeNode(8);

    cout << "Test Case 2: ";
    cout << (solution.leafSimilar(root2_1, root2_2) ? "Pass" : "Fail") << endl;

    // Test Case 3: Empty trees
    TreeNode* root3_1 = nullptr;
    TreeNode* root3_2 = nullptr;

    cout << "Test Case 3: ";
    cout << (solution.leafSimilar(root3_1, root3_2) ? "Pass" : "Fail") << endl;

    // Test Case 4: One tree empty, one non-empty
    TreeNode* root4_1 = new TreeNode(1);
    TreeNode* root4_2 = nullptr;

    cout << "Test Case 4: ";
    cout << (solution.leafSimilar(root4_1, root4_2) ? "Pass" : "Fail") << endl;

    // Test Case 5: Trees with single node
    TreeNode* root5_1 = new TreeNode(1);
    TreeNode* root5_2 = new TreeNode(1);

    cout << "Test Case 5: ";
    cout << (solution.leafSimilar(root5_1, root5_2) ? "Pass" : "Fail") << endl;

    // Test Case 6: Large trees with identical leaves
    TreeNode* root6_1 = new TreeNode(3);
    root6_1->left = new TreeNode(5);
    root6_1->right = new TreeNode(1);
    root6_1->left->left = new TreeNode(6);
    root6_1->left->right = new TreeNode(2);
    root6_1->right->left = new TreeNode(9);
    root6_1->right->right = new TreeNode(8);
    root6_1->left->right->left = new TreeNode(7);
    root6_1->left->right->right = new TreeNode(4);

    TreeNode* root6_2 = new TreeNode(3);
    root6_2->left = new TreeNode(5);
    root6_2->right = new TreeNode(1);
    root6_2->left->left = new TreeNode(6);
    root6_2->left->right = new TreeNode(7);
    root6_2->right->left = new TreeNode(4);
    root6_2->right->right = new TreeNode(2);
    root6_2->right->right->left = new TreeNode(9);
    root6_2->right->right->right = new TreeNode(8);

    cout << "Test Case 6: ";
    cout << (solution.leafSimilar(root6_1, root6_2) ? "Pass" : "Fail") << endl;

    // Test Case 7: Trees with different structures but same leaves
    TreeNode* root7_1 = new TreeNode(1);
    root7_1->left = new TreeNode(2);
    root7_1->right = new TreeNode(3);
    root7_1->left->left = new TreeNode(4);
    root7_1->right->left = new TreeNode(5);

    TreeNode* root7_2 = new TreeNode(6);
    root7_2->left = new TreeNode(4);
    root7_2->right = new TreeNode(5);

    cout << "Test Case 7: ";
    cout << (solution.leafSimilar(root7_1, root7_2) ? "Pass" : "Fail") << endl;

    // Clean up memory (optional if using smart pointers)
    // Please delete allocated nodes as needed

    return 0;
}

