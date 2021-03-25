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

    int n, m;
    cin >> n >> m;
    vi v1(n), v2(m), result;
    vvi dp(n + 1, vi(m + 1, 0));
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(v1[i] == v2[j]){
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    
    for(int i = 0, j = 0; i != n && j != m;){
        if(v1[i] == v2[j]){
            result.pb(v1[i]);
            i++;
            j++;
        } 
        else{
            if(dp[i][j + 1] > dp[i + 1][j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    if(v1[n - 1] == v2[m - 1]){
        result.pb(v1[n - 1]);
    }
    
    for(int i : result){
        cout << i << " ";
    }
    cout << '\n';
}