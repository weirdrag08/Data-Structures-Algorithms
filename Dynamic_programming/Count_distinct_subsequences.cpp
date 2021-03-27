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
    cin.tie();

    string s;
    unordered_map<char, int> my_map;
    cin >> s;
    vll dp((int) s.size() + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= (int) s.size(); i++){
        if(my_map.count(s[i - 1]) == 0){
            my_map[s[i - 1]] = i;
            dp[i] = 2 * dp[i - 1];
        }
        else{
            int prev_index = my_map[s[i - 1]];
            dp[i] = (2 * dp[i - 1]) - dp[prev_index - 1];
            my_map[s[i - 1]] = i;
        }
    }
    cout << dp[s.size()] - 1 << '\n';
}