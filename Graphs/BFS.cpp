#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<int> > gmap;

    void addEdge(int src, int dest, bool bidir = true){
        gmap[src].push_back(dest);
        if(bidir){
            gmap[dest].push_back(src);
        }
    } 

    void bfs(int V, int E, int src){
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> distance(V, -1);
        distance[src] = 0; 
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();   
            for(int neighbour : gmap[front]){
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    distance[neighbour] = distance[front] + 1;
                }
            }
        }
        for(int i = 0; i < V; i++){

            if(i == src){
                continue;
            }

            if(distance[i] != -1){
                cout << (6 * distance[i]) << " ";
            }
            else{
                cout << distance[i] << " ";
            }
        }
    }

};


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        Graph g;
        int V, E, u, v, src;
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            g.addEdge(u - 1, v - 1);
        }
        cin >> src;
        src -= 1;
        g.bfs(V, E, src);
        cout << '\n';
    }
}