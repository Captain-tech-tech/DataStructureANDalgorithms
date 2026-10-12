
// BFS algorithm

// #include <iostream>
// #include <queue>
// using namespace std;

// const int N = 7;

// // adjacency matrix (vertices are numbered 1 to 7)
// int A[N + 1][N + 1] = {
//     {0, 0, 0, 0, 0, 0, 0, 0}, // unused row 0
//     {0, 0, 1, 1, 1, 0, 0, 0}, // vertex 1
//     {0, 1, 0, 1, 0, 0, 0, 0}, // vertex 2
//     {0, 1, 1, 0, 1, 1, 0, 0}, // vertex 3
//     {0, 1, 0, 1, 0, 1, 0, 0}, // vertex 4
//     {0, 0, 0, 1, 1, 0, 1, 1}, // vertex 5
//     {0, 0, 0, 0, 0, 1, 0, 0}, // vertex 6
//     {0, 0, 0, 0, 0, 1, 0, 0}  // vertex 7
// };

// bool visited[N + 1] = {false};

// void BFS(int start) {
//     queue<int> q;

//     // visit and enqueue the starting vertex
//     visited[start] = true;
//     q.push(start);

//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         cout << u << " ";

//         // check all possible neighbors of u
//         for (int v = 1; v <= N; v++) {
//             if (A[u][v] == 1 && !visited[v]) {
//                 visited[v] = true;  // mark before enqueueing
//                 q.push(v);
//             }
//         }
//     }
// }

// int main() {
//     cout << "BFS traversal: ";
//     BFS(1);
//     cout << '\n';

//     return 0;
// }







// // Depth first search
// #include <iostream>
// using namespace std;

// const int N = 7;

// int A[N + 1][N + 1] = {
//     {0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 1, 1, 1, 0, 0, 0},
//     {0, 1, 0, 1, 0, 0, 0, 0},
//     {0, 1, 1, 0, 1, 1, 0, 0},
//     {0, 1, 0, 1, 0, 1, 0, 0},
//     {0, 0, 0, 1, 1, 0, 1, 1},
//     {0, 0, 0, 0, 0, 1, 0, 0},
//     {0, 0, 0, 0, 0, 1, 0, 0}
// };

// bool visited[N + 1] = {false};

// void DFS(int u) {
//     if (visited[u]) {
//         return;
//     }

//     cout << u << " ";
//     visited[u] = true;

//     //explore each neighbor of u
//     for (int v = 1; v <= N; v++) {
//         if (A[u][v] == 1 && !visited[v]) {
//             DFS(v);
//         }
//     }
// }

// int main() {
//     cout << "DFS traversal: ";
//     DFS(1);
//     cout << '\n';

//     return 0;
// }












// Prims algorithm for finding minimum cost spanning tree
// 2D array is used for graphs representation (cost adjacency matrix)
// 2D array is used for storing spanning tree
// 1D array (near) is also used for finding the next nearer (min cost vertex) 

// #include <iostream>
// using namespace std;
// #define I 32767  // Represents infinity: no edge exists
// const int N = 7;

// // Weighted adjacency matrix.
// // Vertices are numbered 1 through 7.
// // cost[u][v] = I means there is no direct edge between u and v.
// int cost[N + 1][N + 1] = {
//     {I,  I,  I,  I,  I,  I,  I,  I},
//     {I,  I, 25,  I,  I,  I,  5,  I},
//     {I, 25,  I, 12,  I,  I,  I, 10},
//     {I,  I, 12,  I,  8,  I,  I,  I},
//     {I,  I,  I,  8,  I, 16,  I, 14},
//     {I,  I, I,  I, 16,   I, 20, 18},
//     {I,  5,  I,  I, 14, 20,  I,  I},
//     {I,  I,  10,  I,  14, 28,  I,  I}
// };

// // near[v] = nearest MST vertex connected to v.
// // near[v] = 0 means v is already included in the MST.
// int near[N + 1];

// // t[0][i] and t[1][i] store the endpoints of MST edge i.
// int t[2][N - 1];

// void Prim() {
//     int u = 0, v = 0;
//     int minCost = I;

//     // STEP 1: Find the minimum-weight edge in the whole graph.
//     for (int i = 1; i <= N; i++) {
//         for (int j = i + 1; j <= N; j++) {
//             if (cost[i][j] < minCost) {
//                 minCost = cost[i][j];
//                 u = i;
//                 v = j;
//             }
//         }
//     }

//     // The first MST edge is the globally minimum edge.
//     t[0][0] = u;
//     t[1][0] = v;

//     // Mark both endpoints as included in the MST.
//     near[u] = 0;
//     near[v] = 0;

//     // STEP 2: Initialize near[] for every other vertex.
//     for (int i = 1; i <= N; i++) {
//         if (near[i] != 0) {
//             if (cost[i][u] < cost[i][v]) {
//                 near[i] = u;
//             } else {
//                 near[i] = v;
//             }
//         }
//     }

//     // STEP 3: Select the remaining N - 2 MST edges.
//     for (int i = 1; i < N - 1; i++) {
//         minCost = I;
//         int k = 0;

//         // Find the nearest outside vertex to the current MST.
//         for (int j = 1; j <= N; j++) {
//             if (near[j] != 0 &&
//                 cost[j][near[j]] < minCost) {
//                 minCost = cost[j][near[j]];
//                 k = j;
//             }
//         }

//         // Add edge (k, near[k]) to the MST.
//         t[0][i] = k;
//         t[1][i] = near[k];

//         // Mark k as included in the MST.
//         near[k] = 0;

//         // Update nearest MST vertex for every remaining vertex.
//         for (int j = 1; j <= N; j++) {
//             if (near[j] != 0 &&
//                 cost[j][k] < cost[j][near[j]]) {
//                 near[j] = k;
//             }
//         }
//     }

//     // STEP 4: Print the Minimum Spanning Tree.
//     int totalCost = 0;

//     cout << "Edges in the Minimum Spanning Tree:\n";
//     for (int i = 0; i < N - 1; i++) {
//         int a = t[0][i];
//         int b = t[1][i];

//         cout << a << " -- " << b
//              << " : weight = " << cost[a][b] << '\n';

//         totalCost += cost[a][b];
//     }

//     cout << "\nTotal MST cost = " << totalCost << '\n';
// }

// int main() {
//     // Initially no vertices are marked as included.
//     for (int i = 1; i <= N; i++) {
//         near[i] = -1;  // -1 means not initialized yet
//     }

//     Prim();
//     return 0;
// }






// Kruskal's algorithm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Represents one weighted edge in the graph.
struct Edge {
    int u;
    int v;
    int weight;
};

// Disjoint Set Union (Union-Find) data structure.
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Initially, every vertex is its own component.
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of a component.
    // Path compression makes future searches faster.
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }

        return parent[x];
    }

    // Join two different components.
    // Union by rank keeps the trees shallow.
    bool Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        // Same representative means they are already connected.
        // Adding this edge would create a cycle.
        if (rootX == rootY) {
            return false;
        }

        // Attach the shorter tree below the taller tree.
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

void Kruskal(int n, vector<Edge>& edges) {
    // Step 1: Sort all edges by increasing weight.
    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });

    DSU dsu(n);

    vector<Edge> mst;
    int totalCost = 0;

    // Step 2: Consider edges from smallest to largest.
    for (const Edge& edge : edges) {

        // Add an edge only if it connects different components.
        if (dsu.Union(edge.u, edge.v)) {
            mst.push_back(edge);
            totalCost += edge.weight;

            // A spanning tree has exactly n - 1 edges.
            if ((int)mst.size() == n - 1) {
                break;
            }
        }
    }

    // Step 3: Display the result.
    if ((int)mst.size() != n - 1) {
        cout << "The graph is disconnected; no spanning tree exists.\n";
        cout << "A minimum spanning forest was found instead.\n";
    }

    cout << "\nEdges selected by Kruskal's algorithm:\n";

    for (const Edge& edge : mst) {
        cout << edge.u << " -- " << edge.v
             << " : weight = " << edge.weight << '\n';
    }

    cout << "\nTotal cost = " << totalCost << '\n';
}

int main() {
    const int n = 7;

    // Each edge is stored once because the graph is undirected.
    vector<Edge> edges = {
        {1, 6, 5},
        {3, 4, 8},
        {2, 7, 10},
        {2, 3, 12},
        {4, 7, 14},
        {4, 5, 16},
        {5, 7, 18},
        {5, 6, 20},
        {1, 2, 25}
    };
    Kruskal(n, edges);

    return 0;
}









