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
    cin.tie();

    string s;
    cin >> s;
    int n = (int) s.size(), count = 0;
    vvi dp(n, vi(n, 0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0) dp[i][j] = 1; 
            else if(g == 1)
                s[i] == s[j] ? dp[i][j] = 3 : dp[i][j] = 2;
            else{
                if(s[i] == s[j]) dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                else dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}