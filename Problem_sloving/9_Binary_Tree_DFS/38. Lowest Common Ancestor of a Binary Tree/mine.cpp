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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> tree;

        
        tree.emplace_back(root->val);
        int i = 0;
        do
        {   
            /* Apply dfs with index to the vector for till you find both nodes*/
            root = root->left;
            tree.emplace(tree.begin() + i, root->val);

        } while ( (root->val != p->val) && (root->val != q->val) );

    }
};