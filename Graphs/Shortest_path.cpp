#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
#include<queue>
using namespace std;

//? Better Code(GENERIC), works on windows(mingw compiler), doesn't work in macos(Xcode compiler)

// template <typename all>
// class Graph
// {
//     unordered_map<all, list<all> > gmap;

// public:
//     void addEdge(all u, all v, bool bidir = true)
//     {
//         gmap[u].push_back(v);
//         if (bidir)
//         {
//             gmap[v].push_back(u);
//         }
//     }

//     unordered_map<all, int>* shortestPath(all src){
//         unordered_map<all, int> *distance = new unordered_map<all, int>();
//         unordered_map<all, int> visited;
//         queue<all> q;
//         q.push(src);
//         visited[src] = 1;
//         distance-> insert({src, 0});
//         while(!q.empty()){
//             all front = q.front();
//             q.pop();
//             for(auto neighbour : gmap[front]){
//                 if(visited.count(neighbour) == 0){
//                     q.push(neighbour);
//                     visited[neighbour] = 1;
//                     distance-> insert({neighbour, distance-> at(front) + 1});
//                 }
//             }
//         }
//         return distance;    
//     }
// };


// ? For integer data only
class Graph
{
    int vertices;
    list<int> *l;

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        l = new list<int>[vertices];
    }

    void addEdge(int u, int v, bool bidir = true)
    {
        l[u].push_back(v);
        if (bidir)
        {
            l[v].push_back(u);
        }
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << "==> {";
            for (int j : l[i])
            {
                cout << j << ", ";
            }
            cout << " }" << '\n';
        }
    }

    vector<int> shortestPath(int src, vector<int> *parent){
        vector<int> distance(vertices, INT_MAX);
        queue<int> q;
        q.push(src);
        distance[src] = 0;
        parent-> at(src) = src;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto i : l[front]){
                if(distance[i] == INT_MAX){
                    q.push(i);
                    distance[i] = distance[front] + 1;
                    parent-> at(i) = front;
                }
            }
        }
        return distance;
    }
};


int main(){
    int v;
    cin >> v; 
    Graph g(v);
    vector<int> *parent = new vector<int>(v);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    vector<int> output = g.shortestPath(0, parent);
    for(int i = 0; i < output.size(); i++){
        cout << "The shortest path of " << i << " from the source vertex: " << output[i] << '\n';
    }
    for(int i : *parent){
        cout << i << ' ';
    }
    cout << '\n';
}