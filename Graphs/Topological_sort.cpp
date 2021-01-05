#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>
#include<stack>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef stack<int> si;

class Graph{
public: 
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, bool bidir = true,  int weight = INT_MAX){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }
private:
    void topological_sort_helper(int src, vb &visited, si &top_order){
        visited[src] = true;
        for(auto neighbour : gmap[src]){
            if(!visited[neighbour.first]){
                topological_sort_helper(neighbour.first, visited, top_order);
            }
        }
        top_order.push(src);
        return;
    }
public:    
    void topological_sort(int V, int E){
        vb visited(V, false);
        si top_order;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                topological_sort_helper(i, visited, top_order);
            }
        }
        while(!top_order.empty()){
            cout << top_order.top() << '\n';
            top_order.pop();
        }
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int V, E, u, v;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        g.addEdge(u, v, false);
    }
    g.topological_sort(V, E);
}