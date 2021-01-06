#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef stack<pair<int, string> > sis;

class Graph
{
public:
    unordered_map<int, list<pi> > gmap;

    void addEdge(int src, int dest, int weight, bool bidir = true)
    {
        gmap[src].push_back(mp(dest, weight));
        if (bidir)
        {
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    void iterative_dfs_helper(int src, vb &visited)
    {
        sis my_stack;
        my_stack.push(mp(src, to_string(src)));
        while (!my_stack.empty())
        {
            auto p = my_stack.top();
            my_stack.pop();
            if (visited[p.first])
            {
                continue;
            }
            visited[p.first] = true;
            cout << p.first << "@" << p.second << '\n';
            string neighbour_path = "";
            for (auto neighbour : gmap[p.first])
            {
                if (!visited[neighbour.first])
                {
                    neighbour_path = p.second + to_string(neighbour.first);
                    my_stack.push(mp(neighbour.first, neighbour_path));
                }
            }
        }
    }

public:
    void iterative_dfs(int V, int E, int src)
    {
        vb visited(V, false);
        iterative_dfs_helper(src, visited);
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int V, E, u, v, w, src;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cin >> src;
    g.iterative_dfs(V, E, src);
}