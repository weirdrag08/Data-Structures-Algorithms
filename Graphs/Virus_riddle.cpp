#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
#include<unordered_set>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef unordered_set<int> usi;
class Graph{

    unordered_map<int, list<pi> > gmap;

public:
    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    void hamiltonian_helper(int cells, int start, int dest, string path, usi &visited){
        path += to_string(start);
        visited.insert(start);
        if(start == dest && visited.size() == cells){
           for(int i = 0; i < path.size(); i++){
               cout << path[i] << " ";
           }
           cout << '\n';
           return;
        }
        for(auto neighbour : gmap[start]){
            if(visited.find(neighbour.first) == visited.end()){
                hamiltonian_helper(cells, neighbour.first, dest, path, visited);
            }
        }
        visited.erase(start);
        return;
    }

public:
    void hamiltonian(int cells, int edges, int start, int dest){
        usi visited;
        string path = "";
        hamiltonian_helper(cells, start, dest, path, visited);
    }

};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int cells, edges, u , v, start, dest;
    cin >> cells >> edges; // * cells = 16, edges = 21
    for(int i = 0; i < edges; i++){
        cin >> u >> v;
        g.addEdge(u, v, INFI);
    }
    cin >> start >> dest;
    g.hamiltonian(cells, edges, start, dest);
}