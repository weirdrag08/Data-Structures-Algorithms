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
    vi dp(s.size(), 0);
    dp[0] = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == '0' && s[i] == '0'){
            dp[i] = 0;
        }
        else if (s[i - 1] == '0' && s[i] != '0'){
            dp[i] += dp[i - 1];
        }
        else if(s[i - 1] != '0' && s[i] == '0'){
            string new_str = s.substr(i - 1, 2);
            if(new_str <= "26"){
                if(i == 1){
                    dp[i] = 1;
                }
                else{
                    dp[i] += dp[i - 2];
                }
            }
            else{
                dp[i] = 0;
            }
        }
        else{
            dp[i] += dp[i - 1];
            string new_str = s.substr(i - 1, 2);
            if(new_str <= "26"){
                if(i == 1){
                    dp[i] += 1;
                }
                else{
                    dp[i] += dp[i - 2];
                }
            }
        }
    }
    cout << dp[s.size() - 1] << '\n';
}