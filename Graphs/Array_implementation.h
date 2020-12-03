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
