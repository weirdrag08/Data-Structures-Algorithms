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
#include<math.h>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef long long int lli;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<long long> > vvll;
typedef vector<long long> vll;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    lli n;
    cin >> n;
    vvlli plot(2, vll(n + 1, 0));
    
    // * '0' => Space
    // * '1' => Building
    plot[0][1] = plot[1][1] = 1;
    for(lli i = 2; i <= n; i++){
        plot[0][i] = plot[0][i - 1] + plot[1][i - 1];
        plot[1][i] = plot[0][i - 1];
    }
    lli one_sided_comb = plot[0][n] + plot[1][n];
    cout << (one_sided_comb * one_sided_comb) << '\n';
}