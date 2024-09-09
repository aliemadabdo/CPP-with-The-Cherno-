# Binary Search Tree (BST)

A **binary search tree (BST)** is a type of binary tree where each node follows a specific ordering rule:

- The **left subtree** of a node contains only nodes with values **less than** the node's value.
- The **right subtree** of a node contains only nodes with values **greater than** the node's value.
- Both the left and right subtrees must also be binary search trees.

### Key Operations
1. **Insertion**: 
   Insert an element by traversing the tree, comparing the element with the nodes, and placing it in the correct position to maintain the BST property.
   
2. **Search**:
   Search for an element by comparing it to the node values and moving left or right accordingly.

3. **Deletion**:
   To delete a node, there are three cases:
   - Node is a **leaf**: Simply remove the node.
   - Node has **one child**: Replace the node with its child.
   - Node has **two children**: Replace the node with its in-order successor (the smallest node in the right subtree).

### Example

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);
    
    if (key < root->data) 
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    
    return root;
}

bool search(Node* root, int key) {
    if (root == nullptr) return false;
    
    if (key == root->data) return true;
    
    if (key < root->data) 
        return search(root->left, key);
    else
        return search(root->right, key);
}
```

### Time Complexity
- **Search/Insertion/Deletion**: O(h), where **h** is the height of the tree. In the best case (balanced BST), h = O(log n), but in the worst case (unbalanced), h = O(n).

