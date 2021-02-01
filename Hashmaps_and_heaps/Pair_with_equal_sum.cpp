#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
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

    unordered_map<int, pi> my_map;
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    bool found = false;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int sum = v[i] + v[j];
            if (my_map.count(sum) > 0 && (v[i] != my_map[sum].first && v[i] != my_map[sum].second) && (my_map[sum].first != v[j] && my_map[sum].first != v[j]))
            {
                found = true;
                cout << "true" << '\n';
                break;
            }
            else{
                my_map[sum] = mp(v[i], v[j]);
            }
        }
        if(found){
            break;
        }
    }
    if(!found){
        cout << "false" << '\n';
    }
}