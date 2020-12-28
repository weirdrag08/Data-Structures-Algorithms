#include<iostream>
#include<unordered_map>
#include<list>
#include<climits>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
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

    void addEdge(int src, int dest, int distance, bool bidir = true){
        gmap[src].push_back(mp(dest, distance));
        if(bidir){
            gmap[dest].push_back(mp(src, distance));
        }
    }

    void shortest_path(int V, int E, Graph g, int src){
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vb visited(V,false);
        vi distance(V, INT_MAX);
        string path[V];
        for(int i = 0; i < V; i++){
            path[i] = "";  
        }

        distance[src] = 0;

        pq.push(mp(distance[src], src));
        path[src] = to_string(src);
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            if(visited[top.second]){
                continue;
            }
            visited[top.second] = true;

// * to print in order the vertices came out of the pq 
           cout << top.second << " via " << path[top.second] << " @ " << distance[top.second] << '\n';

            for(auto neighbour : gmap[top.second]){
                if(!visited[neighbour.first]){
                    int child = neighbour.first;
                    int child_from_vtx = neighbour.second;
                    int child_from_src = top.first + neighbour.second;

// * equality operator is involved so that we can update the newest/latest distance which is equal to the previous one stored as the current distance.(TEST CASE GIVEN BELOW)
                    if(child_from_src <= distance[child]){
                        distance[child] = child_from_src;
                        pq.push(mp(distance[child], child));
                        path[child] = path[top.second] + to_string(child);
                    }
                }
            }
        }
// * to print the vertices in a sorted manner

        for(int i = 0; i < V; i++){
            cout << i << " via " << path[i] << " @ " << distance[i] << '\n';
        }
    }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, d, src;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }
    cin >> src;
    g.shortest_path(V, E, g, src);
}
// ? Test case 1
/*
7 9 
0 1 10 
1 2 10 
2 3 10 
0 3 40 
3 4 2 
4 5 3 
5 6 3 
4 6 8 
2 5 5 
0
*/

// ? Test case 2

/*
7 9 
0 1 10 
1 2 10 
2 3 10 
0 3 40 
3 4 2 
4 5 3 
5 6 3 
4 6 8 
2 5 5 
2
*/