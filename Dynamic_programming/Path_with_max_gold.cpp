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

int max_gold_path_helper(int i, int j, int r, int c, vvi &mine, vvb &visited){
    if(i < 0 || i >= r || j < 0 || j >= c || mine[i][j] == 0 || visited[i][j] == true){
        return 0;
    }
    visited[i][j] = true;
    
    int top = max_gold_path_helper(i - 1, j, r, c, mine, visited);
    int right = max_gold_path_helper(i, j + 1, r, c, mine, visited);
    int bottom = max_gold_path_helper(i + 1, j, r, c, mine, visited);
    int left = max_gold_path_helper(i, j - 1, r, c, mine, visited);
    visited[i][j] = false;
    return mine[i][j] + max(max(top, bottom), max(left, right));
}

int max_gold_path(vvi &mine){
    int r = mine.size(), c = mine[0].size(), maximum_gold = 0;
    vvb visited(r, vb(c, false));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mine[i][j] != 0){
               int curr_max = max_gold_path_helper(i, j, r, c, mine, visited);
                maximum_gold = max(maximum_gold, curr_max);
            }
        }
    }
    return maximum_gold;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    int r, c, curr_max = 0;
    cin >> r >> c;
    vvi mine(r, vi(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mine[i][j];
        }
    }
    int max_gold = max_gold_path(mine);
    cout << "Maximum Gold: " << max_gold << '\n';
}