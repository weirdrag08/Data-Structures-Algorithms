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

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vvi bstring(2, vi(n + 1, 0));
    bstring[0][1] = bstring[1][1] = 1;
    for(int i = 2; i <= n; i++){
        bstring[1][i] = bstring[0][i - 1] + bstring[1][i - 1];
        bstring[0][i] = bstring[1][i - 1];
    }
    cout << bstring[0][n] + bstring[1][n] << '\n';
}