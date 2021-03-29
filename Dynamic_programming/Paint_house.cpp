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
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi color(3, vi(n)), dp(3, vi(n, 0));
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 3; i++){
            cin >> color[i][j];
            if(j == 0){
                dp[i][j] = color[i][j];
            }
        }
    } 

    for(int j = 1; j < n; j++){
        dp[0][j] = color[0][j] + min(dp[1][j - 1], dp[2][j - 1]);
        dp[1][j] = color[1][j] + min(dp[0][j - 1], dp[2][j - 1]);
        dp[2][j] = color[2][j] + min(dp[0][j - 1], dp[1][j - 1]);
    }  
    cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1])) << '\n';
}