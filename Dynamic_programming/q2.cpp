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

int find_infinity_helper(int i, int j, int n, int m, vector<vector<char> > &universe, vector<vector<int> > &dp, vector<vector<bool> >visited){
    if(visited[i][j] || dp[i][j] != -1){
        if(visited[i][j])
            return 0;
        else
            return dp[i][j];    
    }
    visited[i][j] = true;
    int up = -1, down = -1, left = -1, right = -1, up_left = -1, up_right = -1, down_left = -1, down_right = -1;
    if(i > 0 && universe[i - 1][j] == universe[i][j] + 1){
        up = find_infinity_helper(i - 1, j, n, m, universe, dp, visited);
    }

    if(i > 0 && j < m - 1 && universe[i - 1][j + 1] == universe[i][j] + 1){
        up_right = find_infinity_helper(i - 1, j + 1, n, m, universe, dp, visited);
    }
    if(j < m - 1 && universe[i][j + 1] == universe[i][j] + 1){
        right = find_infinity_helper(i, j + 1, n, m, universe, dp, visited);
    }
    if (i < n - 1 && j < m - 1 && universe[i + 1][j + 1] == universe[i][j] + 1){
        down_right = find_infinity_helper(i + 1, j + 1, n, m, universe, dp, visited);
    }
    if (i < n - 1 && universe[i + 1][j] == universe[i][j] + 1){
        down = find_infinity_helper(i + 1, j, n, m, universe, dp, visited);
    }
    if (i < n - 1 && j > 0 && universe[i + 1][j - 1] == universe[i][j] + 1){
        down_left = find_infinity_helper(i + 1, j - 1, n, m, universe, dp, visited);
    }
    if (j > 0 && universe[i][j - 1] == universe[i][j] + 1){
        left = find_infinity_helper(i, j - 1, n, m, universe, dp, visited);
    }
    if (i > 0 && j > 0 && universe[i - 1][j - 1] == universe[i][j] + 1){
        up_left = find_infinity_helper(i - 1, j - 1, n, m, universe, dp, visited);
    }
    dp[i][j] = 1 + max(max(max(up, down), max(left, right)), max(max(up_left, up_right), max(down_left, down_right)));
    visited[i][j] = false;
    return 1 + max(max(max(up, down), max(left, right)), max(max(up_left, up_right), max(down_left, down_right)));
}

int find_infinity(int n, int m, vector<vector<char> > &universe){
    vvb visited(n, vb(m, false));
    vvi dp(n, vi(m, -1));
    int _max = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int up = -1, down = -1, left = -1, right = -1, up_left = -1, up_right = -1, down_left = -1, down_right = -1, recursive_max = -1;
            if(dp[i][j] == -1){
                if(i > 0 && universe[i - 1][j] == universe[i][j] + 1){
                    up = 1 + dp[i - 1][j];
                }
                if(i > 0 && j < m - 1 && universe[i - 1][j + 1] == universe[i][j] + 1){
                    up_right = 1 + dp[i - 1][j + 1];
                }
                if(j < m - 1 && universe[i][j + 1] == universe[i][j] + 1){
                    right = 1 + dp[i][j + 1];
                }
                if(i < n - 1 && j < m - 1 && universe[i + 1][j + 1] == universe[i][j] + 1){
                    down_right = 1 + dp[i + 1][j + 1];
                }
                if(i < n - 1 && universe[i + 1][j] == universe[i][j] + 1){
                    down = 1 + dp[i + 1][j];
                }
                if(i < n - 1 && j > 0 && universe[i + 1][j - 1] == universe[i][j] + 1){
                    down_left = 1 + dp[i + 1][j - 1];
                }
                if(j > 0 && universe[i][j - 1] == universe[i][j] + 1){
                    left = 1 + dp[i][j - 1];
                }
                if(i > 0 && j > 0 && universe[i - 1][j - 1] == universe[i][j] + 1){
                    up_left = 1 + dp[i - 1][j - 1];
                }
                recursive_max = find_infinity_helper(i, j, n, m, universe, dp, visited);
            }
            dp[i][j] = max(max(max(max(up, down), max(left, right)), max(max(up_left, up_right), max(down_left, down_right))), recursive_max);
            if((i == 0 && j == 0) || universe[i][j] == 'A'){
                _max = max(_max, dp[i][j]);
            }
        }
    }
    return _max;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char> > universe(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> universe[i][j];
        }
    }
    int max_infinity = find_infinity(n, m, universe);
    cout << 1 + max_infinity << '\n';
}