#include <iostream>
#include <unordered_map>
#include <list>
#include <climits>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;

class Graph
{
public:
    unordered_map<int, list<pi>> gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true)
    {
        gmap[src].push_back(mp(dest, weight));
        if (bidir)
        {
            gmap[dest].push_back(mp(src, weight));
        }
    }

    void print_all_paths_string(int V, int E, int src, int dest, string path, vb &visited)
    {
        visited[src] = true;
        if (src == dest)
        {
            path += to_string(src);
            cout << path << '\n';
            visited[src] = false;
            return;
        }

        path += to_string(src);
        for (auto neighbour : gmap[src])
        {
            if (!visited[neighbour.first])
            {
                print_all_paths_string(V, E, neighbour.first, dest, path, visited);
            }
        }
        visited[src] = false;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    Graph g;
    int V, E, u, v, w, src, dest;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src >> dest;
    vb visited(V, false);
    string path = "";
    g.print_all_paths_string(V, E, src, dest, path, visited);
}