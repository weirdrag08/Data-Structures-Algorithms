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
    cin.tie();

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vvi dp(2, vi(n));
    dp[0][0] = v[0];
    dp[1][0] = 0;
    for(int i = 1; i < n; i++){
        dp[0][i] = dp[1][i - 1] + v[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]); 
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}