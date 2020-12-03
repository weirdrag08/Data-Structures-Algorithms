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
    int v;
    cin >> v;
    Graph g(v);
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.dfs(0, visited);
    cout << '\n';
}
