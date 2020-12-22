#include <iostream>
#include <map>
#include <list>
#include<stack>
using namespace std;

template <typename all>
class Graph
{
    map<all, list<all>> gmap;

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
    // * 4 5 6 0 1 2 3
    

};

