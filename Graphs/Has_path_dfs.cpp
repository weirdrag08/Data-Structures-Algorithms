#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
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

    bool has_path_dfs(int src, int dest, vb *visited){
        visited-> at(src) = true;
        if(src == dest){
            return true;
        }

        bool recursive_path = false;
        for(auto neighbour : gmap[src]){
           if(!visited-> at(neighbour.first)){
               recursive_path = has_path_dfs(neighbour.first, dest, visited);
           }
            if(recursive_path){
                break;
            }
        }
        if(recursive_path){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w, src, dest;
    cin >> V >> E;
    vb *visited = new vb(V, false);
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest;
    bool has_path = g.has_path_dfs(src, dest, visited);
    if(has_path){
        cout << "true" << '\n';
    }
    else{
        cout << "false" << '\n';
    }
}