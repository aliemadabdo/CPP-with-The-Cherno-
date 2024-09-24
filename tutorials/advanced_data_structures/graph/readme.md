
# **Graph Operations Cheat Sheet**

### **Table of Contents**

1. **Graph Construction**
   - **Adjacency Matrix**
     - Description
     - Code Example
   - **Adjacency List**
     - Description
     - Code Example
   - **Edge List**
     - Description
     - Code Example

2. **Graph Operations**
   - **Insertion**
     - Adjacency Matrix
     - Adjacency List
     - Edge List
   - **Deletion**
     - Adjacency Matrix
     - Adjacency List
     - Edge List
   - **Movement**
     - Adjacency Matrix
     - Adjacency List
     - Edge List

3. **Graph Traversal**
   - **Breadth-First Search (BFS)**
     - Description
     - Code Example
   - **Depth-First Search (DFS)**
     - Description
     - Code Example

4. **Shortest Path Algorithms**
   - **Dijkstra’s Algorithm**
     - Description
     - Code Example
   - **Bellman-Ford Algorithm**
     - Description
     - Code Example

5. **Minimum Spanning Tree (MST)**
   - **Kruskal’s Algorithm**
     - Description
     - Code Example
   - **Prim’s Algorithm**
     - Description
     - Code Example

6. **Graph Properties**
   - **Cycle Detection**
     - Description
     - Code Example
   - **Topological Sort**
     - Description
     - Code Example

#### **1. Graph Construction**

**Adjacency Matrix**
- **Description**: A 2D array where `matrix[i][j]` indicates the presence of an edge between vertices `i` and `j`.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : adjMatrix(vertices, std::vector<int>(vertices, 0)) {}

        void addEdge(int u, int v) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;  // For undirected graph
        }

        void printGraph() {
            for (const auto& row : adjMatrix) {
                for (int cell : row) {
                    std::cout << cell << " ";
                }
                std::cout << std::endl;
            }
        }

    private:
        std::vector<std::vector<int>> adjMatrix;
    };
    ```

**Adjacency List**
- **Description**: An array of lists where each list contains the neighbors of a vertex.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <list>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // For undirected graph
        }

        void printGraph() {
            for (int i = 0; i < adjList.size(); ++i) {
                std::cout << i << ": ";
                for (int neighbor : adjList[i]) {
                    std::cout << neighbor << " ";
                }
                std::cout << std::endl;
            }
        }

    private:
        std::vector<std::list<int>> adjList;
    };
    ```

**Edge List**
- **Description**: A list of all edges, each represented by a pair of vertices.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <iostream>

    class Graph {
    public:
        void addEdge(int u, int v) {
            edges.push_back({u, v});
        }

        void printEdges() {
            for (const auto& edge : edges) {
                std::cout << edge.first << " -- " << edge.second << std::endl;
            }
        }

    private:
        std::vector<std::pair<int, int>> edges;
    };
    ```

---

#### **2. Graph Traversal**

**Breadth-First Search (BFS)**
- **Description**: Visits vertices level by level starting from a source vertex.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <list>
    #include <queue>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void BFS(int start) {
            std::vector<bool> visited(adjList.size(), false);
            std::queue<int> q;
            visited[start] = true;
            q.push(start);

            while (!q.empty()) {
                int vertex = q.front();
                q.pop();
                std::cout << vertex << " ";

                for (int neighbor : adjList[vertex]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }

    private:
        std::vector<std::list<int>> adjList;
    };
    ```

**Depth-First Search (DFS)**
- **Description**: Visits vertices deeply before backtracking.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <list>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void DFS(int start) {
            std::vector<bool> visited(adjList.size(), false);
            DFSUtil(start, visited);
        }

    private:
        void DFSUtil(int vertex, std::vector<bool>& visited) {
            visited[vertex] = true;
            std::cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    DFSUtil(neighbor, visited);
                }
            }
        }

        std::vector<std::list<int>> adjList;
    };
    ```

---

#### **3. Shortest Path Algorithms**

**Dijkstra’s Algorithm**
- **Description**: Finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative weights.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <queue>
    #include <iostream>
    #include <climits>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v, int weight) {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});  // For undirected graph
        }

        void dijkstra(int start) {
            std::vector<int> dist(adjList.size(), INT_MAX);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                for (const auto& neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }

            for (int i = 0; i < dist.size(); ++i) {
                std::cout << "Distance from " << start << " to " << i << " is " << dist[i] << std::endl;
            }
        }

    private:
        std::vector<std::list<std::pair<int, int>>> adjList;
    };
    ```

**Bellman-Ford Algorithm**
- **Description**: Finds the shortest path from a source vertex to all other vertices in a weighted graph, including negative weights.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <iostream>
    #include <climits>

    class Graph {
    public:
        Graph(int vertices) : V(vertices) {}

        void addEdge(int u, int v, int weight) {
            edges.push_back({u, v, weight});
        }

        void bellmanFord(int start) {
            std::vector<int> dist(V, INT_MAX);
            dist[start] = 0;

            for (int i = 0; i < V - 1; ++i) {
                for (const auto& edge : edges) {
                    int u = edge[0];
                    int v = edge[1];
                    int weight = edge[2];
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }

            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    std::cout << "Graph contains a negative weight cycle" << std::endl;
                    return;
                }
            }

            for (int i = 0; i < V; ++i) {
                std::cout << "Distance from " << start << " to " << i << " is " << dist[i] << std::endl;
            }
        }

    private:
        int V;
        std::vector<std::vector<int>> edges;
    };
    ```

---

#### **4. Minimum Spanning Tree (MST)**

**Kruskal’s Algorithm**
- **Description**: Finds the Minimum Spanning Tree (MST) by adding edges in increasing weight.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <algorithm>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : V(vertices) {}

        void addEdge(int u, int v, int weight) {
            edges.push_back({weight, u, v});
        }

        void kruskal() {
            std::sort(edges.begin(), edges.end());
            std::vector<int> parent(V, -1);

            auto find = [&](int u) {
                if (parent[u] == -1) return u;
                return parent[u] = find(parent[u]);
            };

            auto unionSet = [&](int u, int v) {
                int root_u = find(u);
                int root_v = find(v);
                if (root_u != root_v) parent[root_u] = root_v;
            };

            for (const auto& edge : edges) {
                int weight = edge[0];
                int u = edge[1];
                int v = edge[2];
                if (find(u) != find(v))

                {
                    unionSet(u, v);
                    std::cout << u << " -- " << v << " == " << weight << std::endl;
                }
            }
        }
    private:
        int V;
        std::vector<std::vector<int>> edges;
    };
    ```

**Prim’s Algorithm**
- **Description**: Finds the Minimum Spanning Tree (MST) by growing a tree one edge at a time from a starting vertex.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <queue>
    #include <iostream>
    #include <climits>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v, int weight) {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});  // For undirected graph
        }

        void prim(int start) {
            std::vector<int> key(adjList.size(), INT_MAX);
            std::vector<int> parent(adjList.size(), -1);
            std::vector<bool> inMST(adjList.size(), false);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

            key[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();
                inMST[u] = true;

                for (const auto& neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;

                    if (!inMST[v] && weight < key[v]) {
                        key[v] = weight;
                        pq.push({key[v], v});
                        parent[v] = u;
                    }
                }
            }

            for (int i = 1; i < adjList.size(); ++i) {
                std::cout << parent[i] << " -- " << i << " == " << key[i] << std::endl;
            }
        }

    private:
        std::vector<std::list<std::pair<int, int>>> adjList;
    };
    ```

---

#### **5. Graph Properties**

**Cycle Detection**
- **Description**: Check if a graph contains a cycle.
- **Code Example (DFS-based)**:

    ```cpp
    #include <vector>
    #include <list>
    #include <iostream>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // For undirected graph
        }

        bool isCyclic() {
            std::vector<bool> visited(adjList.size(), false);
            for (int i = 0; i < adjList.size(); ++i) {
                if (!visited[i] && isCyclicUtil(i, visited, -1)) {
                    return true;
                }
            }
            return false;
        }

    private:
        bool isCyclicUtil(int v, std::vector<bool>& visited, int parent) {
            visited[v] = true;
            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    if (isCyclicUtil(neighbor, visited, v)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    return true;
                }
            }
            return false;
        }

        std::vector<std::list<int>> adjList;
    };
    ```

**Topological Sort (for Directed Acyclic Graphs)**
- **Description**: Ordering of vertices in a DAG such that for every directed edge `u -> v`, vertex `u` comes before `v`.
- **Code Example**:

    ```cpp
    #include <vector>
    #include <list>
    #include <iostream>
    #include <stack>

    class Graph {
    public:
        Graph(int vertices) : adjList(vertices) {}

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
        }

        void topologicalSort() {
            std::vector<bool> visited(adjList.size(), false);
            std::stack<int> Stack;

            for (int i = 0; i < adjList.size(); ++i) {
                if (!visited[i]) {
                    topologicalSortUtil(i, visited, Stack);
                }
            }

            while (!Stack.empty()) {
                std::cout << Stack.top() << " ";
                Stack.pop();
            }
        }

    private:
        void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
            visited[v] = true;

            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    topologicalSortUtil(neighbor, visited, Stack);
                }
            }

            Stack.push(v);
        }

        std::vector<std::list<int>> adjList;
    };
    ```
