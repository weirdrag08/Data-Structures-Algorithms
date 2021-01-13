#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *l;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        l = new list<int>[vertices];
    }

    void addEdge(int u, int v, bool bidir = true)
    {
        l[u].push_back(v);
        if (bidir)
        {
            l[v].push_back(u);
        }
    }

    void dfs(int src, bool *visited){
        if(visited[src]){
            return;
        }
        cout << src << "-> ";
        visited[src] = true;
        for(int neighbour : l[src]){
            dfs(neighbour, visited);
        }
    }
};

int main(){
    int V, E, u, v, src;
    cin >> V >> E;
    Graph g(V);
    bool *visited = new bool[V];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
   for(int i = 0; i < E; i++){
       cin >> u >> v;
       g.addEdge(u, v);
   }
    cin >> src;
    g.dfs(src, visited);
    cout << '\n';
}
