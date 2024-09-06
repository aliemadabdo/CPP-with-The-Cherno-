// This approach to fine but the another is simpler
// This is for the least common ancestor

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// In-order traversal to print the tree
void inorderPrint(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // First recur on the left subtree
    inorderPrint(root->left);
    
    // Then print the value of the node
    std::cout << root->val << " ";
    
    // Finally, recur on the right subtree
    inorderPrint(root->right);
}

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

class Solution {
public:

    unordered_map<int, TreeNode*> getAncestors(vector<TreeNode*> &vector, int index){
        unordered_map<int, TreeNode*> ancestors;

        ancestors[index] = vector[index];

        while(index){
            index = (index-1)/2; // get the previous ancestor
            ancestors[index] = vector[index];
        }

        return ancestors;
    }

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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vectorizedTree;
        unordered_map<int, TreeNode*> pAncestors, qAncestors;
        treeToVector(root, vectorizedTree, 0);
        int minAncestor = 1000000000, minAncestorIndex = 0;

        for(int i=0; i<vectorizedTree.size(); i++){
            
            if(!vectorizedTree[i]) continue;

            if(vectorizedTree[i]->val == p->val){
                pAncestors = getAncestors(vectorizedTree, i);
            }
            else if(vectorizedTree[i]->val == q->val){
                qAncestors = getAncestors(vectorizedTree, i);
            }
        }

        for(auto itr = pAncestors.begin(); itr != pAncestors.end(); itr++){
            if (itr->second == qAncestors[itr->first] && itr->second->val < minAncestor){
                minAncestor = itr->second->val;
                minAncestorIndex = itr->first;
            } else break;
        }

        return pAncestors[minAncestorIndex];

    }
};

int main() {

    Solution solution;
    // Test Case 1: Basic Test Case
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode* p1 = root1->left; // Node with value 5
    TreeNode* q1 = root1->left->right->right; // Node with value 4
    TreeNode* lca1 = solution.lowestCommonAncestor(root1, p1, q1);
    cout << "LCA of 5 and 4: " << (lca1 ? lca1->val : -1) << endl;
    // Clean up memory...

    // Test Case 2: Test Case with Common Ancestor
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(2);
    root2->right->right = new TreeNode(8);
    root2->left->right->left = new TreeNode(7);
    TreeNode* p2 = root2->left->right->left; // Node with value 7
    TreeNode* q2 = root2->right->right; // Node with value 8
    TreeNode* lca2 = solution.lowestCommonAncestor(root2, p2, q2);
    cout << "LCA of 7 and 8: " << (lca2 ? lca2->val : -1) << endl;
    // Clean up memory...

    // Test Case 3: Test Case with Root as LCA
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->left->left = new TreeNode(4);
    root3->left->right = new TreeNode(5);
    TreeNode* p3 = root3->left->left; // Node with value 4
    TreeNode* q3 = root3->left->right; // Node with value 5
    TreeNode* lca3 = solution.lowestCommonAncestor(root3, p3, q3);
    cout << "LCA of 4 and 5: " << (lca3 ? lca3->val : -1) << endl;
    // Clean up memory...

    // Test Case 4: Test Case with Same Node for p and q
    TreeNode* root4 = new TreeNode(10);
    root4->left = new TreeNode(5);
    root4->right = new TreeNode(15);
    root4->left->left = new TreeNode(3);
    root4->left->right = new TreeNode(7);
    TreeNode* p4 = root4->left; // Node with value 5
    TreeNode* q4 = root4->left; // Node with value 5 (same as p)
    TreeNode* lca4 = solution.lowestCommonAncestor(root4, p4, q4);
    cout << "LCA of 5 and 5: " << (lca4 ? lca4->val : -1) << endl;
    // Clean up memory...

    // Test Case 5: Test Case with Non-Existing Nodes
    TreeNode* root5 = new TreeNode(3);
    root5->left = new TreeNode(5);
    root5->right = new TreeNode(1);
    root5->left->left = new TreeNode(6);
    root5->left->right = new TreeNode(2);
    TreeNode* p5 = root5->left; // Node with value 6
    TreeNode* q5 = new TreeNode(10); // Node with value 10 (not in the tree)
    TreeNode* lca5 = solution.lowestCommonAncestor(root5, p5, q5);
    cout << "LCA of 6 and 10: " << (lca5 ? lca5->val : -1) << endl;
    // Clean up memory...

    // Test Case 6: Test Case with Large Tree
    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->right = new TreeNode(3);
    root6->left->left = new TreeNode(4);
    root6->left->right = new TreeNode(5);
    root6->right->left = new TreeNode(6);
    root6->right->right = new TreeNode(7);
    root6->left->left->left = new TreeNode(8);
    root6->right->right->left = new TreeNode(9);
    root6->right->right->right = new TreeNode(10);
    TreeNode* p6 = root6->left->left->left; // Node with value 8
    TreeNode* q6 = root6->right->right->right; // Node with value 10
    TreeNode* lca6 = solution.lowestCommonAncestor(root6, p6, q6);
    cout << "LCA of 8 and 10: " << (lca6 ? lca6->val : -1) << endl;
    // Clean up memory...

    // Test Case 7: Test Case with Single Node
    TreeNode* root7 = new TreeNode(1);
    TreeNode* p7 = root7; // Node with value 1
    TreeNode* q7 = root7; // Node with value 1 (same as p)
    TreeNode* lca7 = solution.lowestCommonAncestor(root7, p7, q7);
    cout << "LCA of 1 and 1: " << (lca7 ? lca7->val : -1) << endl;
    // Clean up memory...

    // Test Case 8: Test Case with Left-Heavy Tree
    TreeNode* root8 = new TreeNode(1);
    root8->left = new TreeNode(2);
    root8->left->left = new TreeNode(3);
    root8->left->left->left = new TreeNode(4);
    TreeNode* p8 = root8->left; // Node with value 2
    TreeNode* q8 = root8->left->left->left; // Node with value 4
    TreeNode* lca8 = solution.lowestCommonAncestor(root8, p8, q8);
    cout << "LCA of 2 and 4: " << (lca8 ? lca8->val : -1) << endl;
    // Clean up memory...

    // Test Case 9: Test Case with Right-Heavy Tree
    TreeNode* root9 = new TreeNode(1);
    root9->right = new TreeNode(2);
    root9->right->right = new TreeNode(3);
    root9->right->right->right = new TreeNode(4);
    TreeNode* p9 = root9->right; // Node with value 2
    TreeNode* q9 = root9->right->right->right; // Node with value 4
    TreeNode* lca9 = solution.lowestCommonAncestor(root9, p9, q9);
    cout << "LCA of 2 and 4: " << (lca9 ? lca9->val : -1) << endl;
    // Clean up memory...

    // Test Case 10: Test Case with Empty Tree
    TreeNode* root10 = nullptr;
    TreeNode* p10 = nullptr;
    TreeNode* q10 = nullptr;
    TreeNode* lca10 = solution.lowestCommonAncestor(root10, p10, q10);
    cout << "LCA of nullptr and nullptr: " << (lca10 ? lca10->val : -1) << endl;

    return 0;
}