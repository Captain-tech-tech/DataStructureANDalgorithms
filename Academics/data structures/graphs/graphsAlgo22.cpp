// Flood fill algorithm
// Flood Fill Algorithm is used to change the color of a connected area in a grid or image.
// It starts from a given cell (starting pixel) and checks its neighboring cells.
// It changes the color of all connected cells that have the same original color.
// It can move in four directions: up, down, left, and right (sometimes diagonally too).
// This process continues recursively using DFS or BFS until all connected cells with the original color are filled.
// Example: The Paint Bucket tool in MS Paint uses the flood fill concept to color a connected area.





// Topological Sorting using Kahn's Algorithm
// Kahn's Algorithm is a BFS-based approach used to find the topological ordering of a DAG (Directed Acyclic Graph). 
// It uses the concept of indegree and a queue.

// Indegree = Number of incoming edges to a node.

// Indegree → Queue → Process node → Decrease neighbors' indegrees → Add new zero-indegree nodes.
// Time complexity:O(V+E)
// Space complexity: O(V), excluding the graph's storage.

// Algorithm approach (step by step)
// Step 1: Calculate indegree
// - Calculate the indegree of every node by counting its incoming edges.

// Step 2: Add nodes to the queue
// Insert all nodes with indegree 0 into the queue.
// These nodes have no prerequisites, so they can appear first in the topological order.

// Step 3: Process the queue
// Remove a node from the front of the queue.
// Add it to the topological sort result.

// Step 4: Update neighboring nodes
// For every outgoing edge from the removed node, decrease the indegree of its neighbor by 1.
// This is because the edge's source has now been processed.

// Step 5: Add new zero-indegree nodes
// - If any neighbor's indegree becomes 0, push it into the queue.

// Step 6: Repeat
// - Continue until the queue becomes empty.

// Step 7: Check for a cycle
// If the result contains all vertices, topological sorting is possible.
// If some vertices are missing, the graph contains a cycle.







// Dijkstra's algorithm
// use for finding the shortest path from source to all vertices for weighted graph
// It works with weighted graphs.
// It uses a greedy approach (it is a greedy algorithm): choose the unprocessed node with the smallest known distance.
// It works only when edge weights are non-negative.
// It commonly uses a min-priority queue (min-heap) to process the nearest node first.

// Edge relaxation : Edge relaxation means checking whether we can reach a neighboring node through the current node 
// with a shorter distance than the distance we already know.

// #include<iostream>
// #include<list>
// #include<vector>
// #include<climits>
// #include<queue>
// using namespace std;

// class Edge
// {
// public:
//     int v;  // neighbor value
//     int wt; // weight value

//     Edge(int v, int wt)
//     {
//         this->v = v;
//         this->wt = wt;
//     }
    
// };

//     // in directed graph : E can be maximum V(V-1)
//     // int undirected graph : E can be maximum (V(V-1))/2
// void dijkstra(int src, vector<vector<Edge>> &g, int V)  // TC: O((E+V).logV) or O(E.logV)
// {
//     vector<int> dist(V, INT_MAX);
//     dist[src] = 0;

//     // Min-priority queue storing pairs of <distance, vertex>
//     priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
//     // in priority queue, every operation is O(logn), so here it is O(logV)

//     // < dist[u], u >
//     pq.push({0, src});

//     while(pq.size() > 0)
//     {
//         int u = pq.top().second;
//         int d = pq.top().first;
//         pq.pop();

//         // skip processing if we already found a shorter path to u
//         if (d > dist[u]) continue;

//         for(Edge e: g[u])
//         {
//             if(dist[e.v] > dist[u] + e.wt)  // edge relaxation step
//             {
//                 dist[e.v] = dist[u] + e.wt;
//                 pq.push({dist[e.v], e.v});
//             }
//         }
//     }

//     for(int i=0;i<V;i++)
//     {
//         cout<<dist[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     int V = 6;

//     vector<vector<Edge>> g(V);

//     g[0].push_back(Edge(1,2));
//     g[0].push_back(Edge(2,4));

//     g[1].push_back(Edge(2,1));
//     g[1].push_back(Edge(3,7));

//     g[2].push_back(Edge(4,3));

//     g[3].push_back(Edge(5,1));

//     g[4].push_back(Edge(3,2));
//     g[4].push_back(Edge(5,5));

//     dijkstra(0, g, V);

//     return 0;
// }






// Bellman Ford algorithm
// it is dynamic programming based algorithm

// #include<iostream>
// #include<list>
// #include<vector>
// #include<climits>
// #include<queue>
// using namespace std;

// class Edge
// {
// public:
//     int v;  // neighbor value
//     int wt; // weight value

//     Edge(int v, int wt)
//     {
//         this->v = v;
//         this->wt = wt;
//     }
    
// };


// // Bellman ford algorithm
// void bellmanFord(int src, vector<vector<Edge>> g, int V) 
// {
//     vector<int> dist(V, INT_MAX);
//     dist[src] = 0;

//     for(int i=0; i<V-1; i++) 
//     {
//         for(int u=0; u<V; u++) 
//         { // u -----> v
//             for(Edge e : g[u]) 
//             {
//                 if(dist[e.v] > dist[u] + e.wt) 
//                 {
//                     dist[e.v] = dist[u] + e.wt;
//                 }
//             }
//         }
//     }

//     for(int i=0; i<V; i++) 
//         cout << dist[i] << " ";
//     cout << endl;
// }



// int main()
// {
//     int V = 5;
//     vector<vector<Edge>> g(V);

//     g[0].push_back(Edge(1,2));
//     g[0].push_back(Edge(2,4));

//     g[1].push_back(Edge(4,-1));
//     g[1].push_back(Edge(2,-4));

//     g[2].push_back(Edge(3,2));

//     g[3].push_back(Edge(4,4));

//     bellmanFord(0, g, V);

//     return 0;
// }







// TC: O(ElogV), SC: O(V+E)
// Prim's Algorithm for Minimum Spanning Tree (MST) 
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int primMST(int V, vector<vector<pair<int, int>>> adj) {
//     vector<bool> inMST(V, false);
    
//     // min heap storing pairs of {weight, vertex}
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     int mstCost = 0;

//     pq.push({0, 0}); // {wt, vertex}

//     while(pq.size() > 0) {
//         auto p = pq.top();
//         int wt = p.first;
//         int u = p.second;
//         pq.pop();

//         if(!inMST[u]) {
//             inMST[u] = true;
//             mstCost += wt;

//             for(int i = 0; i < adj[u].size(); i++) {
//                 int v = adj[u][i].first;
//                 int w = adj[u][i].second;

//                 pq.push({w, v});
//             }
//         }
//     }

//     return mstCost;
// }

// int main() {
//     int V = 4;
//     vector<vector<pair<int, int>>> adj(V);

//     // Undirected weighted graph
//     adj[0].push_back({1, 10}); // v, wt
//     adj[1].push_back({0, 10}); // u, wt

//     adj[0].push_back({3, 30});
//     adj[3].push_back({0, 30});

//     adj[0].push_back({2, 15});
//     adj[2].push_back({0, 15});

//     adj[1].push_back({3, 40});
//     adj[3].push_back({1, 40});

//     adj[2].push_back({3, 50});
//     adj[3].push_back({2, 50});

//     cout << "Minimum cost of MST = " << primMST(V, adj) << endl;

//     return 0;
// }







// disjoint set union (DSU)
// #include <iostream>
// #include <vector>

// using namespace std;

// class DisjointSet 
// {
//     int n;
//     vector<int> par;
//     vector<int> rank;

// public:
//     // initialization (for i = 0 to n)
//     DisjointSet(int n) {
//         this->n = n;
//         par.resize(n + 1);
//         rank.resize(n + 1, 0);
//         for (int i = 0; i <= n; i++) 
//         {
//             par[i] = i;
//         }
//     }

//     // find(x) function
//     int find(int x) 
//     {
//         if (par[x] == x) 
//         {
//             return x;
//         }
//         // recursive step 
//         // return find(par[x]);  // (1) way
        
//         // path compression optimization : it helps in shallow tree and avoid skewed tree(skewed tree is not optimized)
//         //it can be change this to 'return par[x] = find(par[x]);' to enable path compression, which makes it much faster!
//         return par[x] = find(par[x]);  // (2) way
//     }

//     // union(a, b) function
//     void unionByRank(int a, int b) 
//     {
//         int parA = find(a);
//         int parB = find(b);

//         // if parents are the same, they are already in the same set
//         if (parA == parB) 
//         {
//             return;
//         }

//         // Case 1: Ranks are equal
//         if (rank[parA] == rank[parB]) 
//         {
//             par[parB] = parA;
//             rank[parA]++;
//         }
//         // Case 2: Rank of A is greater
//         else if (rank[parA] > rank[parB]) 
//         {
//             par[parB] = parA;
//         }
//         // Case 3: Rank of B is greater
//         else 
//         {
//             par[parA] = parB;
//         }
//     }

//     // additional function for values printing (not part of data structure)
//     void getInfo()
//     {
//         for(int i=0;i<n;i++)
//         {
//             cout<<par[i]<<" ";
//         }

//         cout<<endl;
//         for(int i=0;i<n;i++)
//         {
//             cout<<rank[i]<<" ";
//         }
//         cout<<endl;
//     }
// };

// int main() 
// {
//     DisjointSet dsu(6);

//     dsu.unionByRank(0, 2);
//     cout << "Find(2): " << dsu.find(2) << endl; // Output: 0

//     dsu.unionByRank(1, 3);
//     dsu.unionByRank(2, 5);
//     dsu.unionByRank(0, 3);

//     cout << "Find(2) after merges: " << dsu.find(2) << endl; // Output: 0
    
//     dsu.unionByRank(0, 4);

//     dsu.getInfo();

//     return 0;
// }






// Kruskal's algorithm
// #include <iostream>
// #include <vector>
// #include <algorithm> 

// using namespace std;

// class Edge 
// {
// public:
//     int u, v, wt;

//     Edge(int u, int v, int wt) 
//     {
//         this->u = u;
//         this->v = v;
//         this->wt = wt;
//     }

//     // Operator overload to sort edges by weight automatically
//     bool operator<(const Edge &other) const 
//     {
//         return this->wt < other.wt;
//     }
// };

// class Graph 
// {
// public:
//     int V;
//     vector<Edge> edges;
//     vector<int> par, rank;

//     Graph(int V) 
//     {
//         this->V = V;
//         for (int i = 0; i < V; i++) 
//         {
//             par.push_back(i);
//             rank.push_back(0);
//         }
//     }

//     void addEdge(int u, int v, int wt) 
//     {
//         edges.push_back(Edge(u, v, wt));
//     }

//     // Find function with Path Compression
//     int find(int x) 
//     {
//         if (par[x] == x) 
//         {
//             return x;
//         }
//         return par[x] = find(par[x]);
//     }

//     // Union function
//     void unionByRank(int a, int b) 
//     {
//         int parA = find(a);
//         int parB = find(b);

//         if (parA == parB) return;

//         if (rank[parA] > rank[parB]) 
//         {
//             par[parB] = parA;
//         } else if (rank[parA] < rank[parB]) 
//         {
//             par[parA] = parB;
//         } else 
//         {
//             par[parB] = parA;
//             rank[parA]++;
//         }
//     }

//     // Kruskal's Algorithm with Count Optimization
//     void kruskal() // O(E log E)
//     { 
//         sort(edges.begin(), edges.end()); 
//         int mstCost = 0;
//         int count = 0; // Tracks the number of edges added to the MST

//         // OPTIMIZATION: Loop breaks early once count reaches V-1
//         for (int i = 0; i < edges.size() && count < V - 1; i++) 
//         {
//             Edge e = edges[i];

//             int parU = find(e.u);
//             int parV = find(e.v);

//             if (parU != parV) 
//             { // No cycle detected
//                 unionByRank(e.u, e.v);
//                 mstCost += e.wt;
//                 count++;     // increment edge count
//                 cout << "Included Edge: " << e.u << " - " << e.v << " (w: " << e.wt << ")" << endl;
//             }
//         }

//         cout << "MST Cost: " << mstCost << endl;
//     }
// };

// int main() {
//     Graph graph(4);

//     graph.addEdge(0, 1, 10);
//     graph.addEdge(0, 2, 6);
//     graph.addEdge(0, 3, 5);
//     graph.addEdge(1, 3, 15);
//     graph.addEdge(2, 3, 4);

//     graph.kruskal();

//     return 0;
// }







// Tarjan's algorithm 

// using tarjan's algorithm for finding the articulation points in a graph
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// class Graph {
// public:
//     vector<vector<int>> adj;
//     int V;
//     int time;
//     vector<int> dt;   // Discovery time
//     vector<int> low;  // Lowest reachable discovery time

//     Graph(int V) {
//         this->V = V;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v) {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void dfs(int u, int parU, set<int>& criticalPoints) {
//         dt[u] = low[u] = ++time;
//         int children = 0;

//         for (int i = 0; i < adj[u].size(); i++) {
//             int v = adj[u][i];

//             if (v == parU) continue;

//             if (dt[v] != -1) {
//                 // Back-edge found: update low-link value using neighbor's discovery time
//                 low[u] = min(low[u], dt[v]);
//             } else {
//                 // Unvisited node found: explore it via DFS
//                 children++;
//                 dfs(v, u, criticalPoints);

//                 // Update low-link value after subtree return
//                 low[u] = min(low[u], low[v]);

//                 // Condition 1 for Articulation Point: Non-root node
//                 if (parU != -1 && low[v] >= dt[u]) {
//                     criticalPoints.insert(u);
//                 }
//             }
//         }

//         // Condition 2 for Articulation Point: Root node with more than 1 independent child
//         if (parU == -1 && children > 1) {
//             criticalPoints.insert(u);
//         }
//     }

//     int articulationPoints() {
//         time = 0;
//         dt.assign(V, -1);   // -1 indicates an unvisited node
//         low.assign(V, -1);

//         set<int> criticalPoints;

//         // Loop handles disconnected graphs or multiple graph components
//         for (int i = 0; i < V; i++) {
//             if (dt[i] == -1) {
//                 dfs(i, -1, criticalPoints);
//             }
//         }

//         // Print the articulation points
//         for (auto val : criticalPoints) {
//             cout << val << " ";
//         }
//         cout << endl;

//         return criticalPoints.size();
//     }
// };

// int main() {
//     // Example test case mimicking the driver setup in the screenshots
//     Graph graph(6);
    
//     graph.addEdge(1, 0);
//     graph.addEdge(1, 2);
//     graph.addEdge(4, 3);
//     // Adding optional edges to form an actual component like the instructor's terminal output 
//     graph.addEdge(2, 0);
//     graph.addEdge(0, 3);
//     graph.addEdge(3, 5);

//     cout << "Articulation points: ";
//     int count = graph.articulationPoints();
//     cout << "Total count: " << count << endl;

//     return 0;
// }








// kosaraju's algorithm
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// class Graph {
// public:
//     vector<vector<int>> adj;
//     int V;

//     Graph(int V) {
//         this->V = V;
//         adj.resize(V);
//     }

//     void addEdge(int u, int v) {
//         adj[u].push_back(v);
//     }

//     // Helper function for Step 1: Standard DFS to fill the stack by finishing times
//     void topoSort(int curr, vector<bool> &vis, stack<int> &s) {
//         vis[curr] = true;
//         for(int neigh : adj[curr]) {
//             if(!vis[neigh]) {
//                 topoSort(neigh, vis, s);
//             }
//         }
//         s.push(curr);
//     }

//     // Helper function for Step 3: DFS traversal on the reversed (transpose) graph
//     void dfs(int curr, vector<bool> &vis, vector<vector<int>> &transpose) {
//         vis[curr] = true;
//         cout << curr << " ";
//         for(int neigh : transpose[curr]) {
//             if(!vis[neigh]) {
//                 dfs(neigh, vis, transpose);
//             }
//         }
//     }

//     // Core Kosaraju Algorithm
//     void kosaraju() {
//         // Step 1 - Find pseudo-topological order based on finish times
//         stack<int> s;
//         vector<bool> vis(V, false);
//         for(int i = 0; i < V; i++) {
//             if(!vis[i]) {
//                 topoSort(i, vis, s);
//             }
//         }

//         // Step 2 - Create the Transpose Graph (reverse all edge directions)
//         vector<vector<int>> transpose(V);
//         for(int u = 0; u < V; u++) {
//             vis[u] = false; // Reset visited array for the next step
//             for(int v : adj[u]) {
//                 transpose[v].push_back(u); // Original: u -> v, Transpose: v -> u
//             }
//         }

//         // Step 3 - Perform DFS on Transpose Graph using order from Stack
//         cout << "Printing the SCC: \n";
//         while(s.size() > 0) {
//             int curr = s.top();
//             s.pop();

//             if(!vis[curr]) {
//                 dfs(curr, vis, transpose); // Prints one complete SCC
//                 cout << endl;
//             }
//         }
//     }
// };

// int main() {
//     Graph graph(5);
//     graph.addEdge(0, 2);
//     graph.addEdge(0, 3);
//     graph.addEdge(1, 0);
//     graph.addEdge(2, 1);
//     graph.addEdge(3, 4);

//     graph.kosaraju();

//     return 0;
// }












// Floyd warshall algorithm
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    void floydWarshall() {
        const int INF = 1e9;

        vector<vector<int>> dist(V, vector<int>(V, INF));

        for(int i = 0; i < V; i++) {
            dist[i][i] = 0;
        }

        for(int u = 0; u < V; u++) {
            for(auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = wt;
            }
        }

        // core logic
        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // print
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }

        // check for neg weighted cycles
        for(int i = 0; i < V; i++) {
            if(dist[i][i] < 0) {
                cout << "Negative weighted cycle exists \n";
            }
        }
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 11);
    graph.addEdge(1, 2, 2);
    graph.addEdge(3, 1, -8);
    graph.addEdge(2, 3, 3);

    graph.floydWarshall();

    return 0;
}



















































