#include<iostream>
#include<list>
#include<unordered_map>
#include<utility>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

#define INFI 10e8
#define INF 10e7
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pi;

class Graph{
public: 
    unordered_map<int, list<pi> >gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true){
            gmap[src].push_back(mp(dest, weight));
            if(bidir){
                gmap[dest].push_back(mp(src, weight));
            }
    }

    void bfs_with_path(int V, int E, Graph g, int src){
        queue<int> q;
        q.push(src);
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        visited[src] = true;
        string path[V];
        path[src] = to_string(src) + "@" + to_string(src); 
        cout << path[src] << '\n';
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    path[neighbour.first] = path[front] + to_string(neighbour.first);
                    path[neighbour.first][0] = neighbour.first + '0';
                    cout << path[neighbour.first] << '\n';
                }
            }
        }
    }    
};


int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w, src;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src;
    g.bfs_with_path(V, E, g, src);
}