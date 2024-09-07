#include <iostream>
#include <vector>
#include <queue>  // For BFS
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;

        queue<TreeNode*> bfs;
        bfs.push(root);


        while(!bfs.empty()){
            int levelSize = bfs.size();
            TreeNode* rightNode = nullptr;

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = bfs.front();
                bfs.pop();

                rightNode = node;

                if(node->left) bfs.push(node->left);
                if(node->right) bfs.push(node->right);
            }

            if(rightNode) result.emplace_back(rightNode->val);
        }
        return result;
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
