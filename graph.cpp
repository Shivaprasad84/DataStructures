#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int>* adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_graph(vector<int> adj[], int v)
{
    for(int i = 0; i < v; ++i)
    {
        cout << "Adjacency of " << i << ": ";
        for(auto x : adj[i])
        {
            cout << x << "-->";
        }
        cout << endl;
    }
}

int main()
{
    int vertices = 5;
    vector<int> adj[vertices];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    print_graph(adj, vertices);
}
