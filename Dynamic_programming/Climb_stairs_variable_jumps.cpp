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

void climb_stairs(vi &v, vi &dp, int n){
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= v[i]; j++){
            dp[i + j] += dp[i];
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; 
    vi v(n), dp(n + 1);
    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
    }
    //* There is 1 way to start from 0 and end at 0
    dp[0] = 1;
    climb_stairs(v, dp, n);
    cout << dp[n] << '\n';
}