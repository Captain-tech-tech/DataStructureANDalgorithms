
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

#include <iostream>
using namespace std;
#define I 32767  // Represents infinity: no edge exists
const int N = 7;

// Weighted adjacency matrix.
// Vertices are numbered 1 through 7.
// cost[u][v] = I means there is no direct edge between u and v.
int cost[N + 1][N + 1] = {
    {I,  I,  I,  I,  I,  I,  I,  I},
    {I,  0, 25,  I,  I,  I,  5,  I},
    {I, 25,  0, 12,  I, 10,  I,  I},
    {I,  I, 12,  0,  8,  I,  I,  I},
    {I,  I,  I,  8,  0, 16, 14,  I},
    {I,  I, 10,  I, 16,  0, 18, 20},
    {I,  5,  I,  I, 14, 18,  0,  I},
    {I,  I,  I,  I,  I, 20,  I,  0}
};

// near[v] = nearest MST vertex connected to v.
// near[v] = 0 means v is already included in the MST.
int near[N + 1];

// t[0][i] and t[1][i] store the endpoints of MST edge i.
int t[2][N - 1];

void Prim() {
    int u = 0, v = 0;
    int minCost = I;

    // STEP 1: Find the minimum-weight edge in the whole graph.
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (cost[i][j] < minCost) {
                minCost = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    // The first MST edge is the globally minimum edge.
    t[0][0] = u;
    t[1][0] = v;

    // Mark both endpoints as included in the MST.
    near[u] = 0;
    near[v] = 0;

    // STEP 2: Initialize near[] for every other vertex.
    for (int i = 1; i <= N; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v]) {
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
    }

    // STEP 3: Select the remaining N - 2 MST edges.
    for (int i = 1; i < N - 1; i++) {
        minCost = I;
        int k = 0;

        // Find the nearest outside vertex to the current MST.
        for (int j = 1; j <= N; j++) {
            if (near[j] != 0 &&
                cost[j][near[j]] < minCost) {
                minCost = cost[j][near[j]];
                k = j;
            }
        }

        // Add edge (k, near[k]) to the MST.
        t[0][i] = k;
        t[1][i] = near[k];

        // Mark k as included in the MST.
        near[k] = 0;

        // Update nearest MST vertex for every remaining vertex.
        for (int j = 1; j <= N; j++) {
            if (near[j] != 0 &&
                cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // STEP 4: Print the Minimum Spanning Tree.
    int totalCost = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 0; i < N - 1; i++) {
        int a = t[0][i];
        int b = t[1][i];

        cout << a << " -- " << b
             << " : weight = " << cost[a][b] << '\n';

        totalCost += cost[a][b];
    }

    cout << "\nTotal MST cost = " << totalCost << '\n';
}

int main() {
    // Initially no vertices are marked as included.
    for (int i = 1; i <= N; i++) {
        near[i] = -1;  // -1 means not initialized yet
    }

    Prim();
    return 0;
}










