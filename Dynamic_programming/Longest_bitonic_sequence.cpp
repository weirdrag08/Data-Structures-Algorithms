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

int b_search(vi &v, vi &dp, int left, int right, int target){
    int midpoint = 0;
    while (left < right){
        midpoint = left + (right - left) / 2;
        dp[midpoint] < target ? left = midpoint + 1 : right = midpoint;
    }
    if (left == dp.size() - 1){
        if (dp[left] >= target)
            dp[left] = target;

        else
            dp.push_back(target);
    }
    else{
        if (dp[left] > target)
            dp[left] = target;
    }
    return dp.size();
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, left = 0, right = 0, max_len = 0;
    cin >> n;
    vi v(n), left_lis(n), right_lis(n), ldp, rdp;

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    ldp.pb(v[0]);
    rdp.pb(v[n - 1]);
    left_lis[0] = right_lis[n - 1] = 1;


    // * For finding the LIS from left side -

    for(int i = 1; i < n; i++){
        left = 0, right = ldp.size() - 1;
        int lis_val = b_search(v, ldp, left, right, v[i]);
        left_lis[i] = lis_val;
    }
    

    // * For finding the LIS from right side -

    for(int i = n - 1; i >= 0; i--){
        left = 0, right = rdp.size() - 1;
        int lis_val = b_search(v, rdp, left, right, v[i]);
        right_lis[i] = lis_val;
    }


    // * For finding the maximum length of bitonic sequence

    for(int i = 0; i < n; i++){
        max_len = max(max_len, (left_lis[i] + right_lis[i]));
    }


    // * We will subtract 1 from the result because the index 'i' from where we got the maximum length of bitonic sequence, counted the index 'i' twice in the calculation of left LIS and right LIS because both times the index 'i' was included during the calculation.
    cout << max_len - 1 << '\n';
}