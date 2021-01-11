#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<string>
#include<cstring>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<string> vs;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string emp, mgr;
    map<string, vs> my_map;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> emp >> mgr;
        my_map[mgr].push_back(emp);
    }
    for(auto manager : my_map){
        for(auto employee : my_map)
    }
}