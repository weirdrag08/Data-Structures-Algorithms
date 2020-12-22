#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

// class vertex{
// public:     
//     pair<int, int> p;
    

//     vertex(int value){
//         this-> p.first = INT_MAX; 
//         this-> p.second = value;
//     }

// };

pair<int, int> vtx_finder(priority_queue<pair<int, int>> pq)
{
    pair<int, int> top = pq.top();
    pq.pop();
    return top;
}

class Graph{
public:     
    unordered_map<int , list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int weight){
          
            pair<int, int> new_pair_dest;
            new_pair_dest.first = dest;
            new_pair_dest.second = weight;
            gmap[src].push_back(new_pair_dest);

           pair<int, int> new_pair_src;
           new_pair_src.first = src;
           new_pair_src.second = weight;
           gmap[dest].push_back(new_pair_src);
    }

    void djikstra_optimised(int V, int E, Graph g, priority_queue<pair<int, int>> pq, int *distance)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        int count = 0;
        while (count < V)
        {
            pair<int, int> vtx = vtx_finder(pq);
            int value = vtx.second;
            for (auto neighbour : gmap[value])
            {

            }
        }
    }
};




int main(){
    Graph g;
    priority_queue<pair<int, int> > pq;
    int V, E, u, v, w;
    cin >> V >> E;
    int *distance = new int[V];

    for(int i = 0;  i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    pair<int, int> p;
    for(int i = 0; i < V; i++){
        if(i == 0){
            distance[i] = 0;
            p.first = 0;
            p.second = i;
        }
        else{
            p.first = INT_MAX;
            p.second = i;
            distance[i] = INT_MAX;
        }
        pq.push(p);
    }

//    while(!pq.empty()){
//        pair<int, int> top = pq.top();
//        cout << "Value: " << (-1) * top.second << "     " <<  "Distance==> " << (-1) * top.first << '\n';
//        pq.pop();
//    }
    g.djikstra_optimised(V, E, g, pq, distance);

}