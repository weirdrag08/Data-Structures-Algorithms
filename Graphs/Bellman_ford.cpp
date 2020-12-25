#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
#include<utility>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
//typedef vector<Edge> ve;
#define mp make_pair
#define INF 10e7 

class Edge{
public: 
    int src;
    int dest;
    int distance;

    Edge(){

    }

    Edge(int src, int dest, int distance){
        this-> src = src;
        this-> dest = dest;
        this-> distance = distance;
    }    
};

void bellman_ford(int V, int E, Edge *Edges){
    vi distance(V, INF);
    distance[0] = 0;
    for(int i = 0; i < V - 1; i++){
        cout << "Iteration: " << i << ": " << '\n' << '\n'; 
        for(int j = 0; j < E; j++){
            if(distance[Edges[j].src] + (Edges[j].distance) < distance[Edges[j].dest]){
                    cout << "Vertex: " << Edges[j].src << "  Dest: " << Edges[j].dest << "  Old Value: " << distance[Edges[j].dest] << "  New Value: " << distance[Edges[j].src] + Edges[j].distance << '\n';
                    distance[Edges[j].dest] = (distance[Edges[j].src] + Edges[j].distance);
            }
        }
        cout << '\n' << '\n';
    }
    bool cycle = false;
    vi resultant_distance(V, INT_MAX);
    resultant_distance[0] = 0;
    for(int i = 0; i < E; i++){
        if(distance[Edges[i].src] + (Edges[i].distance) < distance[Edges[i].dest]){
            cycle = true;
            distance[Edges[i].dest] = distance[Edges[i].src] + Edges[i].distance;
            resultant_distance[Edges[i].dest] = INT_MIN;
        }
        else{
            resultant_distance[Edges[i].dest] = distance[Edges[i].dest];
        }
    }
    if(cycle){
        cout << "Negative Cycle Present" << '\n' << '\n';
    }
    else{
        cout << "Negative Cycle Absent" << '\n' << '\n';
    }
    cout << "Current Distance of Each Vertex: " << '\n' << '\n';

    for(int i = 0; i < V; i++){
        cout << "Vertex: " << i << "  Distance ==> "<< resultant_distance[i] << '\n';
    }
}

int main(){
     std::ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    for(int j = 0; j < tc; j++){
        int V, E, u, v, d;
        cin >> V >> E;
        Edge *Edges = new Edge[E];
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v >> d;
            Edge new_edge(u, v, d);
            Edges[i] = new_edge;
        }
        bellman_ford(V, E, Edges);
    }
}