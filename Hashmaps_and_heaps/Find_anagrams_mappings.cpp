#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, vi> my_map;
    int n, element;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        cin >> element;
        my_map[element].push_back(i);
    }
    
    for(int i = 0; i < n; i++){
        cout << my_map[v[i]][0] << " ";
        my_map[v[i]].erase(my_map[v[i]].begin());
    }
}