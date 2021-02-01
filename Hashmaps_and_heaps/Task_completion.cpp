#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
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
    
    unordered_map<string, vi> my_map;
    int n, m, element;
    bool s1 = true, s2 = false;
    cin >> n >> m;
    vi v(n + 1, 1);
    for(int i = 0; i < m; i++){
        cin >> element;
        v[element] = 0;
    }
    for(int i = 1; i < v.size(); i++){
        if(v[i] == 1){
            if(s1 == true){
                my_map["s1"].push_back(i);
                s1 = false;
                s2 = true;
            }
            else{
                my_map["s2"].push_back(i);
                s1 = true;
                s2 = false;
            }
        }
    }

    for(auto i : my_map["s1"]){
        cout << i << " ";
    }

    cout << '\n';

    for(auto i : my_map["s2"]){
        cout << i << " ";
    }

}