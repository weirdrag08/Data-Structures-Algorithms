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
#define INFI 10e8
#define INF 10e7

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

class Graph
{
    public:
    unordered_map<int, list<int> > gmap;


    void addEdge(int src, int dest, bool bidir = false)
    {
        gmap[src].push_back(dest);
        if (bidir)
        {
            gmap[dest].push_back(src);
        }
    }

    void dfs(int src, unordered_set<int> &visited, int count, int &max_count)
    {
        visited.insert(src);
        max_count = max(max_count, count);
        for(auto neighbour : gmap[src]){
            if(visited.find(neighbour) == visited.end()){
                dfs(neighbour, visited, count + 1, max_count);
            }
        }
        visited.erase(src);
    }
};

int solve(int n, int m, Graph &g, unordered_set<int> &no_indeg)
{  
        int max_size = 0;

       for(auto i : no_indeg){
           cout << i << '\n';
           if(g.gmap[i].size() == 0){
               no_indeg.erase(i);
           }
           else{
               //cout << "Source: " << i << '\n';
               unordered_set<int> curr_visited;
               int count = 0, max_count = 0;
               g.dfs(i, curr_visited, count, max_count);
               max_size = max(max_size, max_count);
           }
       }
       
    
    return max_size;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();
    Graph g;
    unordered_set<int> no_indeg;
    int n, m, src, dest;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        no_indeg.insert(i);
    }
    for(int i = 0; i < m; i++){
        cin >> src >> dest;
        g.addEdge(src, dest);
        if(no_indeg.find(dest) != no_indeg.end()){
            no_indeg.erase(dest);
        }
    }
   // cout << no_indeg.size() << '\n';
    int max_size = solve(n, m, g, no_indeg);
   // cout << max_size << '\n';
}

// 6 8
// 0 1
// 0 3
// 1 2 
// 1 5
// 2 4
// 3 1
// 3 4
// 4 5
