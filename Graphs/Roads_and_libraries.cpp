#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<utility>
#include<queue>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7


typedef pair<long, long> pl;
typedef vector<int> vi;
typedef vector<bool> vb;

class Graph{
public:
    unordered_map<int, list<pl> > gmap;

    void addEdge(long src, long dest, long weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private: 
    long construct_helper(long src, vb &visited){
        queue<long> q;
        q.push(src);
        visited[src] = true;
        long count = 1;
        while(!q.empty()){
            long front = q.front();
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
    void construct(long V, long E, long clib, long croad){
        vb visited(V, false);
        long count = 0, total_cost = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count = construct_helper(i, visited);
                if(clib <= croad){
                    total_cost += count * clib;
                }
                else{
                    total_cost += ((count - 1) * croad) + clib;
                }
            }
        }
        cout << total_cost << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        Graph g;
        long V, E, clib, croad, u, v;
        cin >> V >> E >> clib >> croad;
        for (int j = 0; j < E; j++){
            cin >> u >> v;
            g.addEdge(u - 1, v - 1, INFI);
        }
        g.construct(V, E, clib, croad);
    }
}