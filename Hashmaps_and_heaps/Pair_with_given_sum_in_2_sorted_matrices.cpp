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

int pair_sum(int &n, vvi &m1, vvi &m2, int &x){
    unordered_map<int, int> my_map;
    int count = 0; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            my_map[m1[i][j]] += 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            if(my_map[x - m2[i][j]] > 0)
                count += my_map[x - m2[i][j]];
        }
    return count;            
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;
    vvi m1(n, vi(n)), m2(n, vi(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m1[i][j];
   for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m2[i][j];
    cin >> x;        
    cout << pair_sum(n, m1, m2, x) << '\n';                 
}