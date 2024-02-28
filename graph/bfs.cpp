#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void insert_edge(int u, int v, bool directed)
    {
        adj[u].push_back(v);

        if (!directed)
        {
            adj[v].push_back(u);
        }
    }

    void show()
    {
        for (auto i : adj)
        {
            cout << i.first << "--> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start)
    {
        vector<bool> visited(adj.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter your connected nodes: ";
        cin >> u >> v;

        bool dir;
        cout << "Enter 1 if directed else 0: ";
        cin >> dir;

        g.insert_edge(u, v, dir);
    }

    cout << "Graph representation:" << endl;
    g.show();

    int start_node;
    cout << "Enter starting node for BFS: ";
    cin >> start_node;

    cout << "BFS traversal starting from node " << start_node << ": ";
    g.bfs(start_node);

    return 0;
}
