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

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, f_min = INT_MAX, s_min = INT_MAX;
    cin >> n >> k;
    vvi v(n, vi(k)), dp(n, vi(k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> v[i][j];
            if(i == 0){
                dp[i][j] = v[i][j];
                if (dp[i][j] < f_min){
                    s_min = f_min;
                    f_min = dp[i][j];
                }
                else if (dp[i][j] >= f_min && dp[i][j] < s_min){
                    s_min = dp[i][j];
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        int curr_row_f_min = INT_MAX, curr_row_s_min = INT_MAX;
        for(int j = 0; j < k; j++){
            if(dp[i - 1][j] != f_min){
                dp[i][j] = f_min + v[i][j];
            }
            else{
                dp[i][j] = s_min + v[i][j];
            }
            if(dp[i][j] < curr_row_f_min){
                curr_row_s_min = curr_row_f_min;
                curr_row_f_min = dp[i][j];
            }
            else if(dp[i][j] >= curr_row_f_min && dp[i][j] < curr_row_s_min){
                curr_row_s_min = dp[i][j];
            }
        }
        f_min = curr_row_f_min;
        s_min = curr_row_s_min;
    }
   cout << f_min << '\n';
}