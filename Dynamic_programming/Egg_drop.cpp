#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vvi dp(n + 1, vi(k + 1, 0));
    for(int i = 0;  i <= n; i++){
        dp[i][1] = 1;
    }
    for(int j = 1; j <= k; j++){
        dp[1][j] = j;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= k; j++){
            int _min = INT_MAX;
            for(int l = 0, m = j - 1; l < j; l++, m--){
                _min = min(_min, max(dp[i - 1][l], dp[i][m]) + 1);
            }
            dp[i][j] = _min;
        }
    }
    cout << dp[n][k] << '\n';
}