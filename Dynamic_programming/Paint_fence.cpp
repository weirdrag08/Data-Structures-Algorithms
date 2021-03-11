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
    cin.tie();

    int n, k, same = 0, diff = 0, total = 0;
    cin >> n >> k;
    if(n == 1){
        return k;
    }
    same = k;
    diff = k * (k - 1);
    total = same + diff;
    for(int i = 3; i <= n; i++){
        same = diff;
        diff = (total * (k - 1));
        total = same + diff; 
    }
    cout << total << '\n';
}