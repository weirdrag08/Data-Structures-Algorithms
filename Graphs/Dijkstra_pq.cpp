#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int distance){
        gmap[src].push_back(make_pair(dest, distance));
        gmap[dest].push_back(make_pair(src, distance));
    }

    void dijkstra(int V, int E, Graph g){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        bool *visited = new bool[V];
        int *distance = new int[V];

        for(int i = 0; i < V; i++){
            if(i == 0){
                distance[i] = 0;
            }
            else{
                distance[i] = INT_MAX;
            }
            visited[i] = false;
        }
        int src = 0;
        pq.push(make_pair(distance[src], src));
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            if(visited[top.second] == true){
                continue;
            }
            visited[top.second] = true;
             
            for(auto neighbour : gmap[top.second]){
                int child = neighbour.first;
                int child_from_vtx = neighbour.second;
                int child_from_src = top.first + neighbour.second;
                
                if(child_from_src < distance[child]){
                    distance[child] = child_from_src;
                    pq.push(make_pair(distance[child], child));
                }  
            }
        }
        for(int i = 0; i < V; i++){
            if(distance[i] == INT_MAX){
                 cout << "Vertex: " << i << " ==> " << "∞" << '\n';   
            }
            else{
               cout << "Vertex: " << i << " ==> " << distance[i] << '\n';
            }
        } 
    }
};

int main(){
    // * break the sync between c++ and c I/O functions --> for faster input, use it (Generally when input file is very large)
    std::ios_base::sync_with_stdio(false); 
    // * untie cin and cout (Not important as such)
    cin.tie(NULL);
    Graph g;
    int V, E, u, v, d;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }
    g.dijkstra(V, E, g);
}