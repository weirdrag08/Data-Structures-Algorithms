#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<queue>
#include<vector>
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

    bool has_path_bfs(int V, int E, int src, int dest){
        if(src == dest){
            return true;
        }
        queue<int> q;
        vb visited(V, false);
        q.push(src);
        visited[src] = true;
        bool found = false;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited[neighbour.first]){
                    if(neighbour.first == dest){
                        found = true;
                        return found;
                    }
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
        return false;
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
    bool has_path = g.has_path_bfs(V, E, src, dest);
    if(has_path){
        cout << "true" << '\n';
    }
    else{
        cout << "false" << '\n';
    }
}