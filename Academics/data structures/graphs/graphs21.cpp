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

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
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
    return 0;
}







