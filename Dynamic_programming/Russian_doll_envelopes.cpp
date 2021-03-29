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

    int n, width, height, _max = 1;
    cin >> n;
    vector<pi> v(n);
    for(int i = 0; i < n; i++){
        cin >> width >> height;
        v[i] = mp(width, height);
    }
    sort(v.begin(), v.end());
    vi dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            v[j].second < v[i].second && v[j].first < v[i].first ? dp[i] = max(dp[i], dp[j] + 1) : dp[i] = dp[i];
        }
        _max = max(_max, dp[i]);
    }
    cout << _max << '\n';
}