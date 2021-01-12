#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
#include<utility>
#include<string>
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

    unordered_map<int, int> my_map;
    int n, k;
    cin >> n;
    vi v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cin >> k;
    int count = 0;
    for(int t = 0; t < k; t++){
        if(my_map.count(v[t]) > 0){
            my_map[v[t]]++;
        }
        else{
            my_map[v[t]] = 1;
        }
        count++;
    }
   
    int i = 0;
    for(int j = k; j < n; j++, i++){
            cout << my_map.size() << " ";
            my_map[v[i]]--;
            if(my_map[v[i]] == 0){
                my_map.erase(v[i]);
            }
            if(my_map.count(v[j]) > 0){
                my_map[v[j]]++;
            }
            else{
                my_map[v[j]] = 1;
            }
    }
    cout << my_map.size() << " " << '\n';  
}