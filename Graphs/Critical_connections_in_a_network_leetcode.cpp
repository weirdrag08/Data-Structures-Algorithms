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

int discover_time = 0;
vvi critical; 

class Graph{
    unordered_map<int, list<pi> > gmap;

public:
    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:

    int critical_connections_helper(int caller, int nodes, int edges, int start, vb &visited, stack<int> &path, vb &in_stack, vi &discover, vi &low_link){
        if(visited[start]){
            return in_stack[start] ? discover[start] : INT_MAX;
        }

        path.push(start);
        visited[start] = in_stack[start] = true;
        discover[start] = low_link[start] = discover_time; 
        discover_time++;

        for(auto neighbours : gmap[start]){
            if(neighbours.first == caller) continue;
            low_link[start] = min(low_link[start], critical_connections_helper(start, nodes, edges, neighbours.first, visited, path, in_stack, discover, low_link));
        }

        path.pop();
        in_stack[start] = false;

        if(low_link[start] == discover[start]){
            if(caller != start){
                vi arr;
                arr.push_back(caller);
                arr.push_back(start);
                critical.push_back(arr);
            }
            
        }
        return low_link[start];
    }

public:
    void critical_connections(int nodes, int edges){
        stack<int> path;
        vb visited(nodes, false), in_stack(nodes, false);
        vi discover(nodes, INT_MAX), low_link(nodes, INT_MAX);
    
        int count =  critical_connections_helper(0, nodes, edges, 0, visited, path, in_stack, discover, low_link);
        for (int i = 0; i < nodes; i++)
        {
            cout << "Node: " << i << "  Discover Time: " << discover[i] << "  Low Link: " << low_link[i] << '\n';
        }
    }
};


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++){
        cin >> u >> v;
        g.addEdge(u, v, INFI);
    }

     g.critical_connections(nodes, edges);
    for(int i = 0; i < (int) critical.size(); i++){
        for(int j = 0; j < (int) critical[i].size(); j++){
            cout << critical[i][j] << " ";
        }
        cout << '\n';
    }
}