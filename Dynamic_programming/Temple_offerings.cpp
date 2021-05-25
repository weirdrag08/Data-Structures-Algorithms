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

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vi left_arr(n), right_arr(n);
    left_arr[0] = right_arr[n - 1] = 1;
    for(int i = 1; i < n; i++)
        v[i - 1] < v[i] ? left_arr[i] = left_arr[i - 1] + 1 : left_arr[i] = 1;
    for(int i = n - 2; i >= 0; i--)
        v[i + 1] < v[i] ? right_arr[i] = right_arr[i + 1] + 1 : right_arr[i] = 1;
        int total_offerings = 0;
    for(int i = 0; i < n; i++){
        left_arr[i] =  max(left_arr[i], right_arr[i]);
        total_offerings += left_arr[i];
    } 
   cout << total_offerings << '\n';     
}