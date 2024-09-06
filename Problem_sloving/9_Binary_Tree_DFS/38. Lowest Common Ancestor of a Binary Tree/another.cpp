// NOTE: i used different approach based on the discription
// This is for the deepest common ancestor

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
        if (root == nullptr || p == nullptr || q == nullptr) return nullptr;

        // Base case
        if (root == p || root == q) return root;

        // Recursively find the LCA in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not null, root is the LCA
        if (left != nullptr && right != nullptr) return root;

        // If one of them is null, return the non-null child
        return (left != nullptr) ? left : right;
    }
};