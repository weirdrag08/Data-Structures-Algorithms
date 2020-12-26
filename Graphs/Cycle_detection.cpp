#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<list>
#include<algorithm>
using namespace std;

#define mp make_pair
#define INFI 10e8

typedef pair<int, int> pi;
typedef vector<int> vi;

class Graph{
public: 
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = false){
            gmap[src].push_back(mp(dest, weight));
            if(bidir){
                gmap[dest].push_back(mp(src, weight));
            }
    } 
private:
    bool detect_cycle_helper(int src, Graph g, bool *visited){

        if(visited[src]){
            return 1;
        }
        visited[src] = true;
        bool recursive_cycle = false;
            for(auto neighbour : gmap[src]){
                if(visited[neighbour.first]){
                    return 1;
                }
                recursive_cycle = detect_cycle_helper(neighbour.first, g, visited);
                if(recursive_cycle){
                    return 1;
                }
            }
        return recursive_cycle;    
    }
public:
    void detect_cycle(int V, int E, Graph g){
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        bool cycle = false;

        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                cycle = detect_cycle_helper(i, g, visited);
                if(cycle){
                    break;
                }
            }
        }
        if (cycle)
        {
            cout << "1" << '\n';
        }
        else
        {
            cout << "0" << '\n';
        }
    }

};

int main(){
    int tc;
    cin >> tc;
    for(int j = 0; j < tc; j++){
        std::ios_base::sync_with_stdio(false);
        Graph g;
        int V, E, u, v;
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            g.addEdge(u, v, 10);
        }
        g.detect_cycle(V, E, g);
    }
}

// bool detect_cycle_helper(int src, vector<int> adj[], bool *visited)
// {

//     if (visited[src])
//     {
//         return 1;
//     }
//     visited[src] = true;
//     bool recursive_cycle = false;
//     for (auto neighbour : adj[src])
//     {
//         if (visited[neighbour])
//         {
//             return 1;
//         }
//         recursive_cycle = detect_cycle_helper(neighbour, adj, visited);
//         if (recursive_cycle)
//         {
//             return 1;
//         }
//     }
//     return recursive_cycle;
// }

// bool *visited = new bool[V];
// for (int i = 0; i < V; i++)
// {
//     visited[i] = false;
// }
// bool cycle = false;

// for (int i = 0; i < V; i++)
// {
//     if (visited[i] == false)
//     {
//         cycle = detect_cycle_helper(adj ,i, visited);
//         if (cycle)
//         {
//             break;
//         }
//     }
// }
// if (cycle)
// {
//     cout << "1" << '\n';
// }
// else
// {
//     cout << "0" << '\n';
// }
// }
