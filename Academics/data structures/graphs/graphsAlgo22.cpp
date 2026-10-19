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

#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class Edge
{
public:
    int v;  // neighbor value
    int wt; // weight value

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
    
};


// Bellman ford algorithm
void bellmanFord(int src, vector<vector<Edge>> g, int V) 
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0; i<V-1; i++) 
    {
        for(int u=0; u<V; u++) 
        { // u -----> v
            for(Edge e : g[u]) 
            {
                if(dist[e.v] > dist[u] + e.wt) 
                {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int i=0; i<V; i++) 
        cout << dist[i] << " ";
    cout << endl;
}



int main()
{
    int V = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(4,-1));
    g[1].push_back(Edge(2,-4));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(4,4));

    bellmanFord(0, g, V);

    return 0;
}


