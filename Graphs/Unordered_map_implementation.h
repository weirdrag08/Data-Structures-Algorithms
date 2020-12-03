#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename all>
class Graph
{
    unordered_map<all, list<all>> gmap;

public:
    void addEdge(all u, all v, bool bidir = true)
    {
        gmap[u].push_back(v);
        if (bidir)
        {
            gmap[v].push_back(u);
        }
    }

    void display()
    {
        for (auto vertex : gmap)
        {
            cout << vertex.first << " ==> {";
            for (auto neighbour : gmap[vertex.first])
            {
                cout << neighbour << ", ";
            }
            cout << "}" << '\n';
        }
    }
};
