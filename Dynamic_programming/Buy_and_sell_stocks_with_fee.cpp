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

    int n, fee;
    cin >> n;
    vi v(n);
    vvi dp(n, vi(2, 0));
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> fee;
    
    dp[0][0] -= v[0];
    dp[0][1] = 0;

    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - v[i]);
        dp[i][1] = max(dp[i - 1][1], v[i] + dp[i - 1][0] - fee);
    }
    cout << dp[n - 1][1] << '\n';
}