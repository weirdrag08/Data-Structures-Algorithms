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

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> target;
    vi dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= target; i++){
        for(int j = 0; j < n; j++){
            if(i >= v[j]){
                dp[i] += dp[i - v[j]];
            }
        }
    }
    cout << dp[target] << '\n';
}