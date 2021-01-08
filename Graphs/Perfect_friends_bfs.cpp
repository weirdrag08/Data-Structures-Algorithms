#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<utility>
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

    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    int perfect_friends_helper(int src, vb &visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int count = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    count++;
                }
            }
        }
        return count;
    }

public:
    void perfect_friends(int V, int E){
        vb visited(V, false);
        vi connected_components_size;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                int size = perfect_friends_helper(i, visited);
                connected_components_size.push_back(size);
            }
        }
        int total_combinations = (V*(V - 1))/2;
        int same_club_combinations = 0;
        for(int i = 0; i < connected_components_size.size(); i++){
            if(connected_components_size[i] > 1){
                same_club_combinations += (connected_components_size[i]*(connected_components_size[i] - 1))/2;
            }
        }
        cout << total_combinations - same_club_combinations << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int V, E, u, v, w;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        g.addEdge(u, v, 10);
    }
    g.perfect_friends(V, E);
}