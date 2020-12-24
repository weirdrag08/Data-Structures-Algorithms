#include <iostream>
#include <map>
#include <list>
#include<queue>
#include<unordered_map>
using namespace std;

template <typename all>
class Graph
{
    map<all, list<all> > gmap;

public:
    void addEdge(all u, all v, bool bidir = true)
    {
        gmap[u].push_back(v);
        if (bidir)
        {
            gmap[v].push_back(u);
        }
    }
    void bfs(all src){
        unordered_map<all, int> visited;
        queue<all> q;
        q.push(src);
        visited[src] = 1;
        cout << "{";
        while(!q.empty()){
            all front = q.front();
            cout << front << ", ";
            q.pop();
            for(auto neighbour : gmap[front]){
                if(visited.count(neighbour) == 0){
                q.push(neighbour);
                visited[neighbour] = 1;
                }
            }
        }
        cout << "}" << '\n'; 
    }
};

int main()
{   
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph<int> g;
    int V, E, u, v, src;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cin >> src;
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 5);
    // g.addEdge(3, 4);
    // g.addEdge(2, 4);

    g.bfs(src);
}