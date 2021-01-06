#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
#include<string>
#include<unordered_set>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unordered_set<int> usi;

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
    bool is_bipartite_helper(int src, vb &visited){
        queue<int> q;
        usi set1, set2;
        q.push(src);
        set1.insert(src);
        visited[src] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(visited[neighbour.first]){
                    if((set1.find(front) != set1.end() && set1.find(neighbour.first) != set1.end()) || (set2.find(front) != set2.end() && set2.find(neighbour.first) != set2.end())){
                            return false;
                    }
                }
                else{
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    if(set1.find(front) != set1.end()){
                        set2.insert(neighbour.first);
                    }
                    else{
                        set1.insert(neighbour.first);
                    }
                }
            }
        }
        return true;
    }

public:
    void is_bipartite(int V, int E){
        vb visited(V, false);
        bool bipartite = true;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
               bipartite = is_bipartite_helper(i, visited);
               if(!bipartite){
                   break;
               }
            }
        }
        if(bipartite){
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
    g.is_bipartite(V, E);
}