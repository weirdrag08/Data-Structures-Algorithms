#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<climits>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;


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

typedef vector<Edge> ve;

bool compare(const Edge &e1, const Edge &e2){
    return e1.distance < e2.distance;
}

int parent_finder(int child, vi *parent){
    if(parent-> at(child) == child){
        return child;
    }
    while(parent-> at(child) != child){
        child = parent-> at(child);
    }
    return child;
}

void minimum_wire(int V, int E, ve *edges){
    sort(edges-> begin(), edges-> end(), compare);
    ve *mst = new ve(V - 1);
    vi *parent = new vi(V);
    for (int i = 0; i < parent->size(); i++){
        parent->at(i) = i;
    }
    int u, v, count = 0;

    for(int i = 0; i < E; i++){
        if(count == V - 1){
            break;
        }
        Edge new_edge = edges-> at(i);
        u = new_edge.src;
        v = new_edge.dest;

        int parent1 = parent_finder(u, parent);
        int parent2 = parent_finder(v, parent);

        if(parent1 != parent2){
            parent-> at(parent1) = parent2;
            mst-> at(count) = new_edge;
            count++;
        }
    }
    for(int i = 0; i < mst-> size(); i++){
        cout << "[" << mst-> at(i).dest << "-" << mst-> at(i).src << "@" << mst-> at(i).distance << "]" << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int V, E, u, v, d;
    cin >> V >> E;
    ve *edges = new ve(E);
    for(int i = 0; i < edges-> size(); i++){
        cin >> u >> v >> d;
        edges->at(i).src = u;
        edges-> at(i).dest = v;
        edges-> at(i).distance = d;
    }
    minimum_wire(V, E, edges);
}