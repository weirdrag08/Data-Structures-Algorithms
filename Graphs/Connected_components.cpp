#include<iostream>
#include<list>
using namespace std;

class Graph{
    int vertices;
    list<int> *l;

public:
    Graph(int vertices){
        this-> vertices = vertices;
        l = new list<int>[vertices];
    }

   void addEdge(int u, int v, bool bidir = true){
            l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }

  void connected_components_helper(int src, bool *visited){
      if(visited[src]){
          return;
      }
      cout << src << ", ";
      visited[src] = true;
      for(int neighbour : l[src]){
          if(!visited[neighbour]){
              connected_components_helper(neighbour, visited);
          }
      }
  }

  void connected_components(int src){
      bool *visited = new bool[vertices];
      for(int i = 0; i < vertices; i++){
          visited[i] = false;
      }
      for(int i = 0; i < vertices; i++){
          if(!visited[i]){
              connected_components_helper(i, visited);
              cout << '\n';
          }
      }
  }
};

int main(){
    int vertices, edges, u, v;
    cin >> vertices >> edges;
    Graph g(vertices);
    for(int i = 0; i < edges; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.connected_components(0);
}