#include<iostream>
#include<climits>
using namespace std;


int vtx_finder(int V, bool *visited, int *distance){
    int min_index = -1;
    int min_value = INT_MAX;
    for(int i = 0; i < V; i++){
        if((visited[i] == false) && (distance[i] < min_value)){
                min_index = i;
                min_value = distance[i];
        }
    }
    
    return min_index;
}

void djikstra(int V, int E, int* *edges){
    bool *visited = new bool[V];
    int *distance = new int[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
        if(i == 0){
            distance[i] = 0;
        }
        else{
            distance[i] = INT_MAX;
        }
    }
    int count = 0;
    while(count < V){
        int src = vtx_finder(V, visited, distance);
        if(src == -1){
            count++;
            continue;
        }
        visited[src] = true;
        count++;
        for(int i = 0; i < V; i++){
            if((edges[src][i] != -1) && (distance[src] + edges[src][i] < distance[i])){
                distance[i] = distance[src] + edges[src][i];
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        if(distance[i] == INT_MAX){
            cout << i << "==> " << -1 << '\n';
            continue;
        }
        cout << i << "==> " << distance[i] << '\n';
    }
}

int main(){
    int V, E, u, v, d;
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
        cin >> u >> v >> d;
        edges[u][v] = d;
        edges[v][u] = d;
    }

    djikstra(V, E, edges);

}


// #include<iostream>
// using namespace std;
// int main(){
//     int tc;
//     cin >> tc;
//     for(int i = 0; i < tc; i++){
//         int z = 0, o = 0, N;
//         string s;
//         cin >> N >> s; 
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == '1'){
//                 o++;
//             }
//             else{
//                 z++;
//             }
//         }
//         if(z > 30){
//             cout << "NO" << '\n';
//         }
//         else{
//             int rem = 120 - N;
//             if(o + rem >= 90){
//                 cout << "YES" << '\n';
//             }
//             else{
//                 cout << "NO" << '\n';
//             }
//         }
//     }
// }