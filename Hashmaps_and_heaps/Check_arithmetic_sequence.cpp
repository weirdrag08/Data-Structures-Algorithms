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

bool is_arithmetic_seq(int &n, vi &v){
    if(n == 1)
        return true;
    int a = INT_MAX, an = INT_MIN;
    unordered_map<int, int> my_map;
    for(int i : v)
         a = min(a, i), an = max(an, i), my_map[i] += 1;
    int d = (an - a) / (n - 1);
    
    // * a, a + d, a + 2d, a + 3d, a + 4d ...... 
    bool ap = true;
    for(int i = 0, j = a; i < n; i++){
        if(my_map.count(j) == 0){
            ap = false;
            break;
        }
        j += d;    
    }
    return ap ? true : false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << boolalpha << is_arithmetic_seq(n, v) << '\n';     
}