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

    int n;
    cin >> n;
    vi dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int k = 2; k <= n; k++){
        for(int i = 0, j = k - 1; i <= j; i++, j--){
            dp[k] += dp[i] * dp[j];
            i == j ? dp[k] = dp[k] : dp[k] += dp[j] * dp[i]; 
        }
    }
    cout << dp[n] << '\n';
}