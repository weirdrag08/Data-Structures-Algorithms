#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
#include<queue>
#include<utility>
#include<string>
#include<unordered_set>
#include<math.h>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef long l;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef pair<ll, ll> pll;
typedef unordered_set<pi> uspi;


void to_binary(ll sum, string &s){
    if(sum == 0){
        return;
    }
    to_binary(sum / 2, s);
    s += to_string(sum % 2);
}

void all_shortest(int V, int E, vector<vb> &visited, vvll &edges){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(j == i){
                continue;
            }
            for(int k = 0; k < V; k++){
                if(k == i || j == k){
                    continue;
                }
                edges[j][k] = min(edges[j][k], (edges[j][i] + edges[i][k]));
                edges[k][j] = min(edges[j][k], (edges[j][i] + edges[i][k]));
            }
        }
    }
    ll sum = 0;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i != j && visited[i][j] == false && visited[j][i] == false){
                sum += edges[i][j];
                visited[i][j] = true;
                visited[j][i] = true;
            }
        }
    }

    string s = "";
    to_binary(sum, s);
    cout << s << '\n';
}


int main(){
    ll V, E, u, v, d;
    cin >> V >> E;
    vvll edges(V, vll(V, INFI));
    for(int i = 0; i < E; i++){
        cin >> u >> v >> d;
        edges[u - 1][v - 1] = pow(2, d);
        edges[v - 1][u - 1] = pow(2, d);
    }
    vector<vb> visited(V, vb(V, false));
    all_shortest(V, E, visited, edges);
  
}