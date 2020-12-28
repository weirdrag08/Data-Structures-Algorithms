#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
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

    vi* get_path_dfs(int V, int E, int src, int dest, vb *visited){
        
        visited-> at(src) = true;
        if(src == dest){
            vi *base_arr = new vi();
            base_arr-> push_back(src);
            return base_arr;
        }

            vi *recursive_path = NULL;
        for(auto neighbour : gmap[src]){
            if(!visited-> at(neighbour.first)){
                visited-> at(neighbour.first) = true;
                recursive_path = get_path_dfs(V, E, neighbour.first, dest, visited);
                if(recursive_path != NULL){
                    break;
                }
            }
        }
       if(recursive_path != NULL){
           recursive_path-> push_back(src);
       }
       return recursive_path;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int V, E, u, v, w, src, dest;
    cin >> V >> E;
    vb *visited = new vb(V, false);
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest;
    vi *path = g.get_path_dfs(V, E, src, dest, visited);
    for(int i = path-> size() - 1; i >= 0; i--){
        cout << path-> at(i) << " ";
    }
    cout << '\n';
}