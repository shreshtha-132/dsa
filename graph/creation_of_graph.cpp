#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map<int,list<int>> adj;
        void insert_edge(int u,int v, bool directed)
        {
            adj[u].push_back(v);
            
            // check if directed , then dont add m[v].push_back(u)
            
            
            if(directed==0)
            {
                adj[v].push_back(u);
            }
            
        }
        void show()
        {
            for(auto i:adj)
            {
                cout << i.first << "--> ";
                for(auto j: i.second)
                {
                    cout << j << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int n;
    cout << "enter number of nodes" << endl;
    cin >> n;
    
    int m;
    cout << "enter number of edges" << endl;
    cin >> m;
    
    
    Graph g;
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cout << "enter your connected nodes" << endl;
        cin >> u >> v;
        bool dir;
        cout << "enter 1 if directed else 0" << endl;
        cin >> dir;
        g.insert_edge(u,v,dir);
    }
    
    g.show();
    
}