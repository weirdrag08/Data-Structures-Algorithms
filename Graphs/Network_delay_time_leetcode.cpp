#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
#include<unordered_set>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;
typedef unordered_set<int> usi;

int max_time = 0;

class Graph{    
    unordered_map<int, list<pi> > gmap;

 public:   
    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

    void print(){
        for (auto neighbour : gmap)
        {
            cout << neighbour.first << ": ";
            for (auto i : gmap[neighbour.first])
            {
                cout << i.first << " ";
            }
            cout << '\n';
        }
    }

private:
    void flow_time_helper(int V, int E, int k, usi &visited, int time){
        visited.insert(k);
        max_time = max(max_time, time);
        for(auto neighbour : gmap[k]){
            if(visited.find(neighbour.first) == visited.end()){
                flow_time_helper(V, E, neighbour.first, visited, time + neighbour.second);
            }
        }
    }

public:
    int flow_time(int V, int E, int k){
        usi visited;
        flow_time_helper(V, E, k, visited, 0);
        int total_time = max_time;
        max_time = 0; 
        return visited.size() == V ? total_time : -1;
    }

};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int V, E, k, u, v, w;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w, false);
    }
    cin >> k;
    int total_time = g.flow_time(V, E, k - 1);
    cout << total_time << '\n';
}