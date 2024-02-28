To implement Depth-First Search (DFS), you can make a few modifications to your `Graph` class. Here's the updated code with a DFS implementation:

```cpp
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
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

    void dfs(int start)
    {
        vector<bool> visited(adj.size(), false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            cout << current << " ";

            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    s.push(neighbor);
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
    cout << "Enter starting node for DFS: ";
    cin >> start_node;

    cout << "DFS traversal starting from node " << start_node << ": ";
    g.dfs(start_node);

    return 0;
}
```

In this code, I've replaced the `queue` with a `stack` for DFS, and the traversal order is now depth-first. The DFS function uses a stack to keep track of the nodes to visit. It continues until the stack is empty, exploring deeper into the graph before backtracking.