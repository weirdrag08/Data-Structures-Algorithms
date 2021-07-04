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

int longest_subarray_ones(vi &v){
    unordered_map<int, int> my_map;
    int _max = 0;
    for(int i = 0, j = -1; i < (int) v.size(); i++){
        my_map[v[i]] += 1;
        while(my_map[0] > 1){
            j++;
            my_map[v[j]]--;
            if(my_map[v[j]] == 0)
                my_map.erase(v[j]);
        }
        _max = max(_max, i - j);
    }
    return _max;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout <<  longest_subarray_ones(v) << '\n';
}