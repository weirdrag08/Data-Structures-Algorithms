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
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vvi dp(n - 1, vi(n - 1, INFI));
    for(int g = 0; g < n - 1; g++){
        for(int i = 0, j = g; j < n - 1; i++, j++){
            if(g == 0)
                dp[i][j] = 0;

            else if(g == 1)
                dp[i][j] = v[j - 1] * v[j] * v[j + 1];

            else{
                for(int k = j - g, l = i + 1; k < g; k++, l++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[l][j] + (v[i] * v[j + 1] * v[k + 1]));
                }
            }        
        }
    }
    cout << dp[0][n - 2] << '\n';
}