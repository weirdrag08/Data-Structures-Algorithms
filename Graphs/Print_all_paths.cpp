#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
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


    vector<int>* print_all_paths_helper(int V, int E, int src, int dest, vb &visited){
    //  1-> 2<->3--> 5   
    //      |   |    ^ 
    //      v   |    |
    //      |    --> 4
    //      v
    //      6-> 5
   visited[src] = true; 
    if (src == dest){
        vi *base_arr = new vi();
        base_arr-> push_back(src);
        return base_arr;
        }
        vi *recursive_path = NULL;
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                visited[neighbour.first] = true;
                    recursive_path = print_all_paths_helper(V, E, neighbour.first, dest, visited);
                if(recursive_path){
                    break;
                }
            }
        }
        if(recursive_path){
            recursive_path-> push_back(src);
        }
        return recursive_path;
    }


    void print_all_paths(int V, int E, int src, int dest){
       for(int i = 0 ; i < V; i++){   
            vb visited(V, false);
            vector<int> *path = print_all_paths_helper(V, E, i, dest, visited);
            if(path){
                for(int j = path-> size() - 1; j >= 0; j--){
                    cout << path-> at(i);
                }
                cout << '\n';
            }
       }
    }

};
int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, src, dest, u, v, w;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest;
    g.print_all_paths(V, E, src, dest);
}




// FOR:
// vb vis

// func(i, dest, vis);

// [!, !, , , , , , , , , , ,]