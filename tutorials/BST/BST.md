# Binary Search Tree Cheat Sheet

#### Definition
- **BST Property**: 
  - For every node:
    - Left subtree values < Node value
    - Right subtree values > Node value

#### Structure
```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
```

#### Key Operations

1. **Insertion**
   ```cpp
   Node* insert(Node* root, int key) {
       if (root == nullptr) return new Node(key);
       if (key < root->data) root->left = insert(root->left, key);
       else if (key > root->data) root->right = insert(root->right, key);
       return root;
   }
   ```

2. **Search**
   ```cpp
   bool search(Node* root, int key) {
       if (root == nullptr) return false;
       if (key == root->data) return true;
       if (key < root->data) return search(root->left, key);
       else return search(root->right, key);
   }
   ```

3. **Deletion**
   ```cpp
   Node* deleteNode(Node* root, int key) {
       if (root == nullptr) return nullptr;
       
       if (key < root->data)
           root->left = deleteNode(root->left, key);
       else if (key > root->data)
           root->right = deleteNode(root->right, key);
       else {
           // Node with only one child or no child
           if (root->left == nullptr) {
               Node* temp = root->right;
               delete root;
               return temp;
           } else if (root->right == nullptr) {
               Node* temp = root->left;
               delete root;
               return temp;
           }
           
           // Node with two children
           Node* temp = minValueNode(root->right);
           root->data = temp->data;
           root->right = deleteNode(root->right, temp->data);
       }
       return root;
   }

   Node* minValueNode(Node* node) {
       Node* current = node;
       while (current && current->left != nullptr)
           current = current->left;
       return current;
   }
   ```

4. **In-order Traversal** (sorted order)
   ```cpp
   void inorder(Node* root) {
       if (root != nullptr) {
           inorder(root->left);
           std::cout << root->data << " ";
           inorder(root->right);
       }
   }
   ```

5. **Pre-order Traversal** (root, left, right)
   ```cpp
   void preorder(Node* root) {
       if (root != nullptr) {
           std::cout << root->data << " ";
           preorder(root->left);
           preorder(root->right);
       }
   }
   ```

6. **Post-order Traversal** (left, right, root)
   ```cpp
   void postorder(Node* root) {
       if (root != nullptr) {
           postorder(root->left);
           postorder(root->right);
           std::cout << root->data << " ";
       }
   }
   ```

#### Time Complexity
- **Average Case** (balanced BST): O(log n)
- **Worst Case** (unbalanced BST): O(n)

#### Space Complexity
- **In-order/Pre-order/Post-order Traversal**: O(h), where **h** is the height of the tree (due to recursion stack).
