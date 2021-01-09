#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
#include<climits>
#include<string>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<long, long> pl;
typedef vector<long> vl;
typedef vector<bool> vb;

class Graph{
public:
    unordered_map<long, list<pl> > gmap;
    
    void addEdge(long src, long dest, long weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    long astronauts_pair_helper(long src, vb &visited){
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
    void astronauts_pair(long V, long E){
        vb visited(V, false);
        vl countries;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                long count = astronauts_pair_helper(i, visited);
                countries.push_back(count);
            }
        }
        long total_pairs = (V * (V - 1))/ 2, country_pair = 0;
        for(int i = 0; i < countries.size(); i++){
            if(countries[i] > 1){
                country_pair += (countries[i] * (countries[i] - 1)) / 2;
            }
        }
        cout << total_pairs - country_pair << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    long V, E, u, v;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        g.addEdge(u, v, INFI);
    }
    g.astronauts_pair(V, E);
}  