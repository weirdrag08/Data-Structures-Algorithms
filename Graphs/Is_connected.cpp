#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<queue>
#include<climits>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7


typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;

class Graph{
public:
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }
private:
    void is_connected_helper(int src, vb &visited){
        visited[src] = true;
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                visited[neighbour.first] = true;
                is_connected_helper(neighbour.first, visited);
            }
        }
    }

public:
    bool is_connected(int V, int E, Graph g){
        vb visited(V, false);
        int src = 0;
        is_connected_helper(src, visited);
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    bool connected = g.is_connected(V, E, g);
    if(connected){
        cout << "true" << '\n';
    }
    else{
        cout << "false" << '\n';
    }
}