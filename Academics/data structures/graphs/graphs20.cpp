
// BFS algorithm

#include <iostream>
#include <queue>
using namespace std;

const int N = 7;

// adjacency matrix (vertices are numbered 1 to 7)
int A[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0}, // unused row 0
    {0, 0, 1, 1, 1, 0, 0, 0}, // vertex 1
    {0, 1, 0, 1, 0, 0, 0, 0}, // vertex 2
    {0, 1, 1, 0, 1, 1, 0, 0}, // vertex 3
    {0, 1, 0, 1, 0, 1, 0, 0}, // vertex 4
    {0, 0, 0, 1, 1, 0, 1, 1}, // vertex 5
    {0, 0, 0, 0, 0, 1, 0, 0}, // vertex 6
    {0, 0, 0, 0, 0, 1, 0, 0}  // vertex 7
};

bool visited[N + 1] = {false};

void BFS(int start) {
    queue<int> q;

    // visit and enqueue the starting vertex
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        // check all possible neighbors of u
        for (int v = 1; v <= N; v++) {
            if (A[u][v] == 1 && !visited[v]) {
                visited[v] = true;  // mark before enqueueing
                q.push(v);
            }
        }
    }
}

int main() {
    cout << "BFS traversal: ";
    BFS(1);
    cout << '\n';

    return 0;
}







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















