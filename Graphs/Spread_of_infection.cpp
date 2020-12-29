#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<queue>
#include<string>
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

    void spread_of_infection(int V, int E, int src, int time){
        int initial_time = 1;
        int count = 0;
        queue<pi> q;
        vb visited(V, false);
        q.push(mp(src, initial_time));
        visited[src] = true;
        while(!q.empty()){
            pi front = q.front();
            q.pop();
            if(front.second == time){
                break;
            }
            for(auto neighbour : gmap[front.first]){
                if(!visited[neighbour.first]){
                   int curr_time = front.second + 1;
                    q.push(mp(neighbour.first, curr_time));
                    count++;
                    visited[neighbour.first] = true;
                }
            }
        }
        cout << count + 1 << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, d, src, time;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        g.addEdge(u, v, d);
    }

    cin >> src >> time;
    g.spread_of_infection(V, E, src, time);
}