Here's a quick documentation about Depth-First Search (DFS) in a README format:

---

# Depth-First Search (DFS)

## Overview

Depth-First Search (DFS) is an algorithm used for traversing or searching tree or graph data structures. The algorithm starts at a root node and explores as far as possible along each branch before backtracking.

## Characteristics

- **Deep Exploration:** DFS explores each branch of the tree or graph as deeply as possible before moving on to the next branch.
- **Backtracking:** When DFS encounters a node with no unvisited adjacent nodes, it backtracks to the most recent node with unexplored neighbors.
- **Stack-Based:** DFS can be implemented either recursively using the call stack or iteratively using an explicit stack.

## Applications

- **Tree Traversal:** DFS is used for in-order, pre-order, and post-order traversals of a binary tree.
- **Path Finding:** Used in maze-solving and finding paths in graphs.
- **Topological Sorting:** DFS is used in directed acyclic graphs (DAGs) to find a topological order.
- **Cycle Detection:** DFS can be used to detect cycles in a graph.

## Implementation

### Recursive Implementation

```cpp
void dfs(TreeNode* root) {
    if (root == nullptr) return;

    // Process the current node
    cout << root->val << " ";

    // Recursively visit left and right children
    dfs(root->left);
    dfs(root->right);
}
```

### Iterative Implementation

```cpp
void dfs(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();

        // Process the current node
        cout << node->val << " ";

        // Push right and left children onto the stack
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}
```

## Example Usage

Given a binary tree:

```
        1
       / \
      2   3
     / \
    4   5
```

The DFS traversal order is `1 -> 2 -> 4 -> 5 -> 3`.

## Complexity

- **Time Complexity:** `O(V + E)` where `V` is the number of vertices (nodes) and `E` is the number of edges.
- **Space Complexity:** `O(V)` due to the stack used for backtracking.

## References

- [Depth-First Search - Wikipedia](https://en.wikipedia.org/wiki/Depth-first_search)
- [GeeksforGeeks - DFS](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)

---

This README provides a concise overview of DFS, including its characteristics, applications, and implementation details.