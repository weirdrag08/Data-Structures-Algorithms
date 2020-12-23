#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Graph{
public: 
    unordered_map<int, list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int distance){
        gmap[src].push_back(make_pair(dest, distance));
        gmap[dest].push_back(make_pair(src, distance));
    }

    void dijkstra(int V, int E, Graph g){
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        bool *visited = new bool[V];
        int *distance = new int[V];

        for(int i = 0; i < V; i++){
            if(i == 0){
                distance[i] = 0;
            }
            else{
                distance[i] = INT_MAX;
            }
            visited[i] = false;
        }
        int vtx = 0;
        pq.push(make_pair(distance[vtx], vtx));
        for()    
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}