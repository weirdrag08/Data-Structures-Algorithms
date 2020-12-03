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

   void display(){
       for(int i = 0; i < vertices; i++){
           cout << i << "==> {";
           for(int j : l[i]){
               cout << j << ", ";
           }
           cout << " }" << '\n';
       }
   } 
};

int main(){
    int v;
    cin >> v;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.display();
}