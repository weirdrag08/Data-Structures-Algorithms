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
    vi value(n), weight(n);
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;
    vi dp(max_weight + 1, 0);

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= max_weight; j++){
            if(j >= weight[i]){
                dp[j] = max(dp[j], (value[i] + dp[j - weight[i]]));
            }
        }
    }
    cout << dp[max_weight] << '\n';
}