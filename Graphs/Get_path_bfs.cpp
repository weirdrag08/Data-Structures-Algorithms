#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<climits>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

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

    vi* get_path_bfs(int V, int E, int src, int dest, vb *visited){
        if(src == dest){
            vi *base_arr = new vi();
            base_arr-> push_back(src);
            return base_arr;
        }

        queue<int> q;
        vi parent(V);
        vi *path = new vi();
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        bool found = false;
        q.push(src);
        visited-> at(src) = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited-> at(neighbour.first)){
                    q.push(neighbour.first);
                    parent[neighbour.first] = front;
                    visited-> at(neighbour.first) = true;
                    if (neighbour.first == dest){
                        found = true;
                        break;
                    }
                }
            }
            if(found){
                int i = dest;
                for(; parent[i] != i;){
                    path-> push_back(i);
                    i = parent[i];
                }
                path-> push_back(i);
                return path;
            }
        }
       path = NULL;
       return path;
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
    vi *path = g.get_path_bfs(V, E, src, dest, visited);
    if(path != NULL){
        for(int i = 0; i < path-> size(); i++){
            cout << path-> at(i) << " ";
        }
        cout << '\n';
    }
}