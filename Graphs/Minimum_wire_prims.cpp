#include<iostream>
#include<unordered_map>
#include<list>
#include<climits>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<string>
using namespace std;

#define mp make_pair
#define INF 10e7
#define INFI 10e8

typedef pair<int, int> pi;
typedef vector<int> vi;


class Graph{
public: 
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }  

    void minimum_wire(int V, int E, Graph g){
        bool *visited = new bool[V];
        int *distance = new  int[V];
        string path[V];
        priority_queue<pi, vector<pi>, greater<pi> > pq;


        for(int i = 0; i < V; i++){
            visited[i] = false;
            distance[i] = INT_MAX;
            path[i] = "";
        }

        int src = 0;
        distance[src] = 0;
        pq.push(mp(distance[src], src));
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            if(visited[top.second]){
                continue;
            }
            visited[top.second] = true;
            // * For printing in order in which the vertices came out of the pq!
            // cout << path[top.second] << '\n';

            for(auto neighbour : gmap[top.second]){
                if(!visited[neighbour.first]){
                    int child = neighbour.first;
                    int child_from_vtx = neighbour.second;

                    if(child_from_vtx < distance[child]){
                        distance[child] = child_from_vtx;
                        path[child] = "[" + to_string(child) + "-" + to_string(top.second) + "@" + to_string(neighbour.second) + "]";
                        pq.push(mp(distance[child], child));
                    }
                }
            }
        }
// * For printing in the order of vertices        
        for(int i = 0; i < V; i++){
            if(path[i] == ""){
                continue;
            }
            cout << path[i] << '\n';
        }

    }  
};


int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, d;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }
    g.minimum_wire(V, E, g);
}