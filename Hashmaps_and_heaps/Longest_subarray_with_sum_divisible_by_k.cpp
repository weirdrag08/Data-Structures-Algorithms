#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
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
    int n, k, sum = 0, size = 0, rem, prev_index = -1;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    for(int i = 0; i < n; i++){
        sum += v[i];
        rem = sum / k;
        if(my_map.count(rem) > 0){
             prev_index = my_map[rem];
            size = max(size, i - prev_index);
        }
        else{
            my_map[rem] = i;
        }
    }
    cout << size << '\n';
}