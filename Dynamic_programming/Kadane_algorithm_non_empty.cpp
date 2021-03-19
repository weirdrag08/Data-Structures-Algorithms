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

    // * If we can return a empty set, then the minimal value which can be returned is 0, because ∑(empty) = 0, ie if max subarray sum < 0, then we can return the max value = 0, but if we have to return a non-empty set, then we have to return the best, whether it is positive or negative.
    // * The only difference in both codes is the initialization of the best and current best variable.

    // TODO For empty set - We will initialize both the variables from 0, so that we can ignore the updation of a negative best value.
    // TODO For non empty set - We will initialize both the variables with INT_MIN, so that, we can have a negative max subarray sum.

    int n, curr_best = INT_MIN, best = INT_MIN;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        curr_best > 0 ? curr_best += v[i] : curr_best = v[i];
        if(best < curr_best) best = curr_best;
    }
    cout << best << '\n';
}