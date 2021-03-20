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

    int n, N, S, _max, left = 0, right = 0, midpoint = 0;
    cin >> n;
    vector<pi> v(n);
    vi dp;
    for(int i = 0; i < n; i++){
        cin >> N >> S;
        v[i] = mp(N, S);
    }
    sort(v.begin(), v.end());
    dp.pb(v[0].second);
    _max = 1;
    
    for(int i = 1; i < n; i++){
        left = 0, right = dp.size() - 1;
        while(left < right){
            midpoint = left + (right - left)/2;
            dp[midpoint] < v[i].second ? left = midpoint + 1 : right = midpoint;
        }
        if(left == dp.size() - 1){
            if(dp[left] >= v[i].second)
            dp[left] = v[i].second;
            else
            dp.pb(v[i].second);
        }
        else{
            if(dp[left] > v[i].second)
            dp[left] = v[i].second;
        }
        _max = max(_max, (int) dp.size());
    }
    cout << _max << '\n';
}