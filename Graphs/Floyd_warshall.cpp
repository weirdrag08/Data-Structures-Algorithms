#include<iostream>
#include<climits>
#include<vector>
#include<utility>
using namespace std;

#define INFI 10e8
#define INF 1e7
#define mp make_pair
typedef pair<int, int> pi;
typedef vector<int> vi;


void floyd_warshall(int V, int* *edges){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                for(int k = 0; k < V; k++){
                    if((j == i) || (k == i) || (j == k)){
                        continue;
                    }
                    
                    if(edges[j][i] == INFI || edges[i][k] == INFI){
                        continue;
                    }
                    else{
                        edges[j][k] = min(edges[j][k], edges[j][i] + edges[i][k]);
                    }
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (edges[i][j] == INFI)
                {
                    cout << "∞" << " ";
                }
                else
                {
                    cout << edges[i][j] << " ";
                }
            }
            cout << '\n';
        }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    for(int k = 0; k < tc; k++){
        int V, E, u, v, d;
        cin >> V >> E;
        int **edges = new int *[V];

        for (int i = 0; i < V; i++)
        {
            edges[i] = new int[V];
        }

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i == j){
                    edges[i][j] = 0;
                }
                else{
                    edges[i][j] = INFI;
                }
            }
        }

        for (int i = 0; i < E; i++){
            cin >> u >> v >> d;
            edges[u][v] = d;
        }

        floyd_warshall(V, edges);
    }
}