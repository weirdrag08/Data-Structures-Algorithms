#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int vtx_finder(int V, int *weight, bool *visited){
    int min_weight = INT_MAX;
    int min_index = -1;
    for(int i = 0; i < V; i++){
        if(visited[i] == false && weight[i] < min_weight){
            min_weight = weight[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims(int V, int E, int* *edges){
    int *parent = new int[V];
    int *weight = new int[V];
    for(int i = 0; i < V; i++){
        parent[i] = -1;
        if(i == 0){
            weight[i] = 0;
        }
        else{
            weight[i] = INT_MAX;
        }
    }
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    int count = 0;
    while(count < V){
       int curr_vtx = vtx_finder(V, weight, visited);
       visited[curr_vtx] = true;
       count++;
       for (int i = 0; i < V; i++)
       {
           if (edges[curr_vtx][i] != -1 && visited[i] == false)
           {
               if (edges[curr_vtx][i] < weight[i])
               { 
                   weight[i] = edges[curr_vtx][i];
                   parent[i] = curr_vtx;
               }
           }
       }
   }
   for(int i = 1; i < V; i++){
       if(i < parent[i]){
           cout << i << " " << parent[i] << " " << weight[i];
       }
       else{
           cout << parent[i] << " " << i << " " << weight[i];
       } 
       cout << '\n';
   }
}


int main(){
    int V, E, u, v, w;
    cin >> V >> E;
    int* *edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
    }

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            edges[i][j] = -1;
        }
    }

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        edges[u][v] = w;
        edges[v][u] = w;
    }

     prims(V, E, edges);
}