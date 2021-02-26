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

    string s;
    cin >> s;
    vvi dp(3, vi(s.size() + 1, 0));

    for(int i = 1; i <= s.size(); i++){
            if(s[i - 1] == 'a'){
                dp[0][i] = (2 * dp[0][i - 1]) + 1;
                dp[1][i] = dp[1][i - 1];
                dp[2][i] = dp[2][i - 1];
            }
            else if(s[i - 1] == 'b'){
                dp[1][i] = (2 * dp[1][i - 1]) + dp[0][i - 1];
                dp[0][i] = dp[0][i - 1];
                dp[2][i] = dp[2][i - 1];
            }
            else{
                dp[2][i] = (2 * dp[2][i - 1]) + dp[1][i - 1];
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1];
            }
    }
    cout << dp[2][s.size()] << '\n';
}