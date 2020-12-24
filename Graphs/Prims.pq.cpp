#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
#include<utility>
using namespace std;

class Graph{
public:    
    unordered_map<int, list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int weight){
        // * [u, {v, w}]
        gmap[src].push_back(make_pair(dest, weight));
        gmap[dest].push_back(make_pair(src, weight));
    }

    void prims(int V, int E, Graph g, int s){
        // * priority_queue<datatype, vector<datatype>, greater<datatype> >;
        priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > pq;
        bool *visited = new bool[V];
        int *weight = new int[V];
        for(int i = 0; i < V; i++){
            if(i == s){
                weight[i] = 0;
            }
            else{
                weight[i] = INT_MAX;
            }
            visited[i] = false;
        }
        int src = s;
        pq.push(make_pair(weight[src], src));
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            if(visited[top.second] == true){
                continue;
            }
            visited[top.second] = true;
            for(auto neighbour : gmap[top.second]){
                if(visited[neighbour.first] == false){
                    int child = neighbour.first;
                    int child_from_vtx = neighbour.second;

                    if (child_from_vtx < weight[child])
                    {
                        weight[child] = child_from_vtx;
                        cout << "Parent: " << top.second + 1 << "  Child: " << child + 1 << "  Weight: " << weight[child] << '\n';
                        pq.push(make_pair(weight[child], child));
                    }
                }
           }
        }
        int sum = 0;
        for(int i = 0; i < V; i++){
            sum += weight[i];
        }
        cout << sum << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        Graph g;
        int V, E, u, v, w, s;
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v >> w;
            g.addEdge(u - 1, v - 1, w);
        }
        cin >> s;
        s -= 1;
        g.prims(V, E, g, s);
    
}