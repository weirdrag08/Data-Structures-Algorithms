#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#include<queue>
#include<climits>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;


void discover_island(int V, int E, int i, int j, int* *edges, vector<vector<bool> > &visited){
    if(i < 0 || j < 0 || i == V || j == V || visited[i][j] == true || edges[i][j] == 1){
        return;
    }

    visited[i][j] = true;
    discover_island(V, E, i, j - 1, edges, visited);
    discover_island(V, E, i + 1, j, edges, visited);
    discover_island(V, E, i, j + 1, edges, visited);
    discover_island(V, E, i - 1, j, edges, visited);
}

void islands(int V, int E, int* *edges){
    vector<vector<bool> > visited(V, vector<bool>(V, false));
    int count = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(edges[i][j] == 0 && visited[i][j] == false){
                discover_island(V, E, i, j, edges, visited);
                count++;
            }
        }
    }
    cout << count << '\n';
}

int main(){
    int V, E;
    cin >> V >> E;
    int* *edges = new int*[V];    
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cin >> edges[i][j];
        }
    }

    islands(V, E, edges);

}