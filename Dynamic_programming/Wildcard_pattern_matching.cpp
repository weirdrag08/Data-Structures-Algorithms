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
    int n = (int) s1.size(), m = (int) s2.size();
    bool only_asterisk = true;
    vvb dp(n + 1, vb(m + 1, false));
    dp[n][m] = true;
   for(int j = m - 1; j >= 0; j--){
       if(s2[j] != '*'){
           only_asterisk = false;
       }
       if(only_asterisk){
           dp[n][j] = true;
       }
       else{
           break;
       }
   }
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i + 1][j + 1];
            }
            else{
                if(s2[j] >= 'a' && s2[j] <= 'z'){
                    dp[i][j] = false;
                }
                else if(s2[j] == '?'){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    for(int k = 0; k <= s1.substr(i).size(); k++){
                        dp[i][j] = dp[i + k][j + 1];
                        if(dp[i][j]) 
                          break;
                    }
                }
            }
        }
    }
    cout << boolalpha << dp[0][0] << '\n'; 
}