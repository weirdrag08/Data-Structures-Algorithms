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

    int n, _max = 0;
    cin >> n;
    vi v(n), dp(n, 1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    } 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        _max = max(_max, dp[i]);
    }
    cout << _max << '\n';
}