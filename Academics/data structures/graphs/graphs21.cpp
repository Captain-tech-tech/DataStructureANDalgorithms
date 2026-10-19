// graphs is simply a network of nodes
// directed graphs
// undirected graphs
// weighted graphs
// unweighted graphs
// connected graphs
// unconnected graphs



// undirected graph, adjacency list representation
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int V;
    // dynamic list of integers
    list<int> *l;    // int *arr;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool isDirected = false)
    {
        l[u].push_back(v); // u points to v
        if (!isDirected) {
            l[v].push_back(u); // v only points back to u if it is UNDIRECTED
        }
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" : ";
            for(int neigh:l[i])
                cout<<neigh<<" ";
            cout<<endl;
        }
    }

    // O(V+E)
    bool isCycleUndirectedDFS(int src, int par, vector<bool>&vis)// using DFS logic  // source vertex, parent and visited array
    {
        vis[src] = true;
        
        list<int> neighbors = l[src];

        for(int v:neighbors)
        {
            if(!vis[v])
            {
                if(isCycleUndirectedDFS(v, src, vis))
                {
                    return true;
                }
            }
            else if(v != par)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle()
    {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(isCycleUndirectedDFS(i,-1,vis))
                    return true;
        }
        return false;
    }


    bool isCycleUndirBFS(int src, vector<bool>&vis)
    {
        queue<pair<int,int>>q;
        q.push({src,-1});

        vis[src] = true;

        while(!q.empty())
        {
            int u = q.front().first;
            int parU = q.front().second;

            q.pop();
            list<int>neighbors = l[u];
            for(int v:neighbors)
            {
                if(!vis[v])
                {
                    q.push({v,u});
                    vis[v] = true;
                }
                else if(v != parU)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool iscycle()
    {
        vector<bool>vis(V,false);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(isCycleUndirBFS(i,vis))
                    return true;
        }
        return false;
    }

    bool isCycleDirectedDFS(int curr, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[curr] = true;

        recPath[curr] = true;

        for(int v : l[curr])
        {
            if(!vis[v])
            {
                if(isCycleDirectedDFS(v, vis, recPath))
                    return true;
            }
            else if(recPath[v])
                return true;
        }
        recPath[curr] = false;
        return false;
    }

    bool iscycleD()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(isCycleDirectedDFS(i, vis, recPath))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // topological sorting : it can be applied on directed acyclic graph (DAG)
    // it is linear ordering of all the vertices such that every directed edge u-->v, vertex u comes before v in the order (it is dfs based)
    // there can be multiple valid topological orderings
    // it is used to solve dependency based problems 
    // steps:
    // first the dependent of a vertex are push in the stack and then the vertex itself
    // then one by one elements are pop from the stack and store in an array(containing the topological sorted number)

    //  5 ------> 0 <------ 4
    // |                    |
    // v                    v
    // 2                   1
    //  \                  ^
    //   v                /
    //    3 --------------
    // Edges:
    // 5 -> 0
    // 4 -> 0
    // 5 -> 2
    // 2 -> 3
    // 3 -> 1
    // 4 -> 1
    // Possible Topological Sorts:
    // 1) 4, 2, 3, 5, 1, 0
    // 2) 5, 4, 0, 2, 3, 1
    // 3) 5, 4, 2, 0, 3, 1

    void dfs(int curr, vector<bool> &vis, stack<int> &s)
    {
        vis[curr] = true;

        for(int v : l[curr])
            if(!vis[v])
                dfs(v, vis, s);
        
        s.push(curr);
    }

    void topoSort()   // O(V+E)
    {
        vector<bool>vis(V,false);
        stack<int>s;

        for(int i=0;i<V;i++)
            if(!vis[i])
                dfs(i, vis, s);

        while(s.size()>0)
        {
            cout<<s.top()<<"  ";
            s.pop();
        }
        cout<<endl;
    }

    // topological sorting using kahn's algorithm
    void ktopoSort()
    {
        vector<int>res;
        // calculate indegree
        vector<int> indeg(V, 0);
        for(int u=0;u<V;u++)
        {
            for(int v: l[u])
                indeg[v]++;
        }

        // 0 indeg --> enqueue
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }

        // bfs
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            res.push_back(curr);

            for(int v:l[curr])
            {
                indeg[v]--;
                if(indeg[v]==0)
                    q.push(v);
            }
        }

        // Check if a cycle exists
        if (res.size() != V) 
        {
        cout << "Error: The graph contains a cycle! Topological sort is impossible." << endl;
        return;
        }

        // print result if it's a valid DAG
        for(int val:res)
            cout<<val<<"  ";
        cout<<endl;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    g.print();

    cout<<"Cycle : "<<g.iscycle()<<endl;

    Graph gg(4);
    gg.addEdge(1, 0);
    gg.addEdge(0, 2);
    gg.addEdge(2, 3);
    gg.addEdge(3, 0);

    cout<<"cycle finding in directed graph : "<<gg.iscycleD()<<endl;

    // directed acyclic graph for topological sorting
    Graph gts(6);
    gts.addEdge(3, 1);
    gts.addEdge(2, 3);
    gts.addEdge(4, 0);
    gts.addEdge(4, 1);
    gts.addEdge(5, 0);
    gts.addEdge(5, 3);

    cout<<"topo sort: ";
    gts.topoSort();

    Graph gkts(6);
    gkts.addEdge(3, 1, true); // <--- Notice the 'true' here!
    gkts.addEdge(2, 3, true);
    gkts.addEdge(4, 0, true);
    gkts.addEdge(4, 1, true);
    gkts.addEdge(5, 0, true);
    gkts.addEdge(5, 3, true);

    cout << "Topological Sort (Kahn's): ";
    gkts.ktopoSort();
    return 0;
}










