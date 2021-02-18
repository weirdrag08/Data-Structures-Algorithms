#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
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

int climb_stairs(int n, vi &v, vi &dp)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= v[i]; j++)
        {
            if (i + j <= n)
            {
                dp[i] = min(1 + dp[i + j], dp[i]);
            }
        }
    }
    return dp[0];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vi v(n), dp(n + 1, INFI);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp[n] = 0;
    int min_moves = climb_stairs(n, v, dp);
    cout << min_moves << '\n';
}