#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<climits>
#include<queue>
#include<stack>
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

private:
    void hamiltonian_helper(int src, int origin, int V, int count, vb &visited, string path){
        visited[src] = true;
        path += to_string(src);
        bool call = false;
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                call = true;
                hamiltonian_helper(neighbour.first, origin, V, count + 1, visited, path);
            }
        }
        if(!call && count == V){
            bool hamiltonian_cycle = false;
            for(auto neighbour : gmap[src]){
                if(neighbour.first == origin){
                    hamiltonian_cycle = true;
                    break;
                }
            }
            if(hamiltonian_cycle){
                cout << path << "*" << '\n';
            }
            else{
                cout << path << "." << '\n';
            }
        }
        visited[src] = false;
    }

public:
    void hamiltonian(int V, int E, int origin){
        vb visited(V, false);
        string path = "";
        int count = 1;
        hamiltonian_helper(origin, origin, V, count, visited, path);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int V, E, u, v, w, origin;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> origin;
    g.hamiltonian(V, E, origin);
}