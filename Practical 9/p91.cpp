#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int next : adj[node])
        {
            if (!visited[next])
            {
                DFSUtil(next, visited);
            }
        }
    }

public:
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start)
    {
        vector<bool> visited(V, false);

        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int next : adj[node])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of buildings: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of roads: ";
    cin >> E;

    cout << "Enter roads (u v):" << endl;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
