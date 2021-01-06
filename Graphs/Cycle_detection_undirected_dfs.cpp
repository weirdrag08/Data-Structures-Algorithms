#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<utility>
#include<queue>
#include<string>
#include<stack>
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

    void addEdge(int src, int dest, int weight, bool bidir = false){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    } 
private:
    bool is_cyclic_helper(int src, vb &visited, vi &parent){
            visited[src] = true;
            bool recursive_cycle = false;
            for(auto neighbour : gmap[src]){
                if(visited[neighbour.first] && parent[neighbour.first] != src){
                    recursive_cycle = true;
                    return recursive_cycle;
                }
                 if(!visited[neighbour.first]){
                    parent[neighbour.first] = src;
                    recursive_cycle = is_cyclic_helper(neighbour.first, visited, parent);
                    if(recursive_cycle){
                        break;
                    }
                }
            }
          return recursive_cycle;  
    }

public:
    void is_cyclic(int V, int E){
        vb visited(V, false);
        vi parent(V);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        bool cycle = false;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                int src = i;
                cycle = is_cyclic_helper(i, visited, parent);
                if(cycle){
                    break;
                }
            }
        }
        if(cycle){
            cout << "true" << '\n';
        }
        else{
            cout << "false" << '\n';
        }
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int V, E, u, v, w;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.is_cyclic(V, E);
}