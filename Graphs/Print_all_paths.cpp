#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<queue>
#include<utility>
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

    void print_paths(int V, int E, int src, int dest, vb &visited, vi path){
        visited[src] = true;
        if(src == dest){
            path.push_back(src);
            visited[src] = false;
            for(int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }
          
            cout << '\n';
            return;
        }
        
            path.push_back(src);
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                print_paths(V, E, neighbour.first, dest, visited, path);
            }
        }
        visited[src] = false;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w, src, dest;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest;
    vb visited(V, false);
    vi path;
    g.print_paths(V, E, src, dest, visited, path);
}