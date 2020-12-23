#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<climits>
#include<utility>
using namespace std::chrono;
using namespace std;

class Graph{
public: 
    // * [vertex, {dest, weight}]
    unordered_map<int, list<pair<int, int> > > gmap;

    void addEdge(int src, int dest, int distance){
        pair<int, int> pair_src (dest, distance);
        gmap[src].push_back(pair_src);
        pair<int, int> pair_dest (src, distance);
        gmap[dest].push_back(pair_dest);
    }

    void djikstra(int V, int E, Graph g){
    // * visited array to mark vertices which were visited    
        bool *visited = new bool[V];

    // * distance array maintains the current shortest path/distance from the source, and gives O(1) access to it's element which makes implementation faster while accessing a vertex in the set    
        int *distance = new int[V];

    // * set maintains an increasing order in terms of distance from the source (How far a vertex is from the source)    
        set<pair<int, int> > my_set;

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
        pair<int, int> src_pair(distance[vtx], vtx);
        my_set.insert(src_pair);

        while(!my_set.empty()){
            pair<int, int> curr_pair = *(my_set.begin());
            my_set.erase(my_set.begin());
          
            visited[curr_pair.second] = true;
            for(auto neighbour : gmap[curr_pair.second]){
             if(visited[neighbour.first] == false){
                 int child_vtx, distance_from_src, distance_from_vtx;
                 child_vtx = neighbour.first;
                 distance_from_vtx = neighbour.second;
                 distance_from_src = curr_pair.first + neighbour.second;

                 pair<int, int> search_pair(distance[child_vtx], child_vtx);

                 auto found = my_set.find(search_pair);
                 if (found == my_set.end())
                 {
                     distance[child_vtx] = distance_from_src;
                     pair<int, int> child_pair(distance[child_vtx], child_vtx);
                     my_set.insert(child_pair);
                 }
                 else
                 {
                     pair<int, int> child_pair = *(found);
                     if (distance_from_src < child_pair.first)
                     {
                         my_set.erase(found);
                         distance[child_vtx] = distance_from_src;
                         child_pair.first = distance[child_vtx];
                         my_set.insert(child_pair);
                     }
                 }
             }
           }
        }
        for(int i = 0; i < V; i++){
            if(distance[i] == INT_MAX){
                cout << "Vertex: " << i << "==> "<< "-1" << '\n';
            }
            else{
                cout << "Vertex: " << i << "==> " << distance[i] << '\n'; 
            }
        }
    }
};

int main(){

    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g;
    int V, E, u, v, d;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }
    auto start = high_resolution_clock::now();

    g.djikstra(V, E, g);

    auto stop = high_resolution_clock::now();

    
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}