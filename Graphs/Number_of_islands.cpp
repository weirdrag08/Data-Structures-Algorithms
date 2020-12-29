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


int main(){
    int V, E;
    cin >> V >> E;
    int* *edges = new int*[V];    
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
    }

}