#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
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
    bool is_cyclic_helper(int src, vb &visited, vi &parent){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        bool cycle = false;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){

                if(visited[neighbour.first] && parent[front] != neighbour.first){
                    cycle = true;
                    break;
                }

                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    parent[neighbour.first] = front;
                    visited[neighbour.first] = true;
                }
            }
            if(cycle){
               return cycle;
            }
        }
        return cycle;
    }

public:
    void is_cyclic(int V, int E){
        vb visited(V, false);
        vi parent(V);
        bool cycle = false;
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
               cycle = is_cyclic_helper(i, visited, parent);
               if(cycle){
                   break;
               }
            }
        }
        cout << boolalpha << cycle << '\n';
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