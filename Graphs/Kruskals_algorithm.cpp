#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;
};

bool sort_weight(const Edge &e1, const Edge &e2)
{
    if (e1.weight < e2.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int parent_finder(int src, int *parent)
{
    if (parent[src] == src)
    {
        return src;
    }
    else
    {
        while (parent[src] != src)
        {
            src = parent[src];
        }
        return src;
    }
}

Edge *kruskals(int v, int e, Edge *input, int *parent)
{
    int count = 0;
    sort(input, input + e, sort_weight);
    Edge *output = new Edge[v - 1];
    for (int i = 0; i < e; i++)
    {
        if (count == v - 1)
        {
            break;
        }
        int v1 = input[i].src, v2 = input[i].dest;
        int parent_src = parent_finder(v1, parent);
        int parent_dest = parent_finder(v2, parent);
        if (parent_src == parent_dest)
        {
            continue;
        }
        else
        {
            parent[parent_dest] = parent_src;
            output[count] = input[i];
            count++;
        }
    }
    return output;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int *parent = new int[v];
    Edge *input = new Edge[e];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int src, dest, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> weight;
        input[i].src = src;
        input[i].dest = dest;
        input[i].weight = weight;
    }
    Edge *output = kruskals(v, e, input, parent);
    for (int i = 0; i < v - 1; i++)
    {
        if (output[i].src <= output[i].dest)
        {
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << '\n';
        }
        else
        {
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << '\n';
        }
    }
}
