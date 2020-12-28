#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;


class triplet{
public:
    int vtx;
    string path;
    int distance;   

    triplet(){
        this-> vtx = -1;
        this-> path = "";
        this-> distance = INT_MAX;
    }

    triplet(int vtx, string path, int distance){
        this-> vtx = vtx;
        this-> path = path;
        this-> distance = distance;
    }

};

struct compare{
    bool operator()(const triplet &t1, const triplet &t2){
        return t1.distance > t2.distance;
    }
};

class Graph{
public:
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int distance, bool bidir = true){
        gmap[src].push_back(mp(dest, distance));

        if(bidir){
            gmap[dest].push_back(mp(src, distance));
        }
    }
    // * Triplet class ==>  {vtx, "path", distance}

    void shortest_distance(int V, int E, Graph g, int src){
        priority_queue<triplet, vector<triplet>, compare> pq;
        vb visited(V, false);
        triplet src_triplet(src, to_string(src), 0);
        pq.push(src_triplet);
        while(!pq.empty()){
            triplet top = pq.top();
            pq.pop();
            if(visited[top.vtx]){
                continue;
            }
            visited[top.vtx] = true;
            cout << top.vtx << " via " << top.path << " @ " << top.distance << '\n';
            for(auto neighbour : gmap[top.vtx]){
                    if(!visited[neighbour.first]){
                        int child = neighbour.first;
                        int child_from_vtx = neighbour.second;
                        int child_from_src = top.distance + neighbour.second;
                        triplet child_triplet(child, top.path + to_string(child), child_from_src);
                       // cout << "Vertex: " << child_triplet.vtx << "  path: " << child_triplet.path << "  distance ==>  " << child_triplet.distance << '\n';
                        pq.push(child_triplet);
                   }
            }
        }
    }   
};


int main(){
   std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int V, E, u, v, d, start;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }
    cin >> start;
    g.shortest_distance(V, E, g, start);
}