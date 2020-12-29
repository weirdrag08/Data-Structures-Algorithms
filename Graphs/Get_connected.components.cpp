#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<utility>
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
private:
    vi* get_connected_components_helper(int src, vb &visited){
        visited[src] = true;
        vi *connected_components = new vi();
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                visited[neighbour.first] = true;
                connected_components = get_connected_components_helper(neighbour.first, visited);
            }
        }
        connected_components->push_back(src);
        return connected_components;
    }
public: 
    void get_connected_components(int V, int E, Graph g){
        vb visited(V, false);
        vi *output;
        cout << "[";
        int i = 0;
        for(; i < V; i++){
            if(!visited[i]){
                output = get_connected_components_helper(i, visited);
                cout << "[";
                for(int j = output-> size() - 1; j >= 0; j--){
                    if(j != 0){
                        cout << output->at(j) << ", ";
                    }
                    else{
                        cout << output-> at(j);
                    }
                }
              
            }
        }
        
        cout << "]" << '\n';
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
    g.get_connected_components(V, E, g);
}