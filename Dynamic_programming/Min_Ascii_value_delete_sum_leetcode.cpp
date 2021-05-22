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

    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int> > dp((int) s1.size() + 1, vector<int>((int) s2.size() + 1, 0));
        for(int j = s2.size() - 1; j >= 0; j--)
            dp[(int) s1.size()][j] = s2[j] + dp[(int) s1.size()][j + 1];
        for(int i = s1.size() - 1; i >= 0; i--)
            dp[i][(int) s2.size()] = s1[i] + dp[i + 1][(int) s2.size()];
        
        for(int i = s1.size() - 1; i >= 0; i--){
            for(int j = s2.size() - 1; j >= 0; j--){
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
            }
        }
        cout << dp[0][0] << '\n';
}