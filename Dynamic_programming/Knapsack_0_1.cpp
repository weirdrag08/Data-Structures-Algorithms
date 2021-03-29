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

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, max_weight;
    cin >> n;
    vi weight(n + 1), value(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;
    vvi dp(n + 1, vi(max_weight + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= max_weight; j++){
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], (value[i] + dp[i - 1][j - weight[i]]));
            }
        }
    }
    cout << dp[n][max_weight] << '\n';
}