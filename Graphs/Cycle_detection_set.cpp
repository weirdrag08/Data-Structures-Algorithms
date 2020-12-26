#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<utility>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int, int> vi;
typedef unordered_set<int> usi;

#define mp make_pair
#define INFI 10e8 

class Graph{
public: 
    unordered_map<int, list<int> > gmap;

    void addEdge(int src, int dest, bool bidir = true){
        gmap[src].push_back(dest);
        if(bidir){
            gmap[dest].push_back(src);
        }
    }

private:
    bool detect_cycle_helper(int src, Graph g, usi &visited){
    
        bool recursive_cycle = false;
        for(auto neighbour : gmap[src]){
            if (visited.find(neighbour) != visited.end())
            {
                return 1;
            }
           recursive_cycle = detect_cycle_helper(neighbour, g, visited);
           if(recursive_cycle == 1){
               return 1;
           }
        }
        return 0;
    }
public:
    void detect_cycle(int V, int E, Graph g){
        usi visited; 
        bool cycle = false;
        for(auto node : gmap){
            if(visited.find(node.first) == visited.end()){
                visited.insert(node.first);
                cycle = detect_cycle_helper(node.first, g, visited);
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
    Graph g;
    int V, E, u, v, w;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v);
    }
    g.detect_cycle(V, E, g);
}
