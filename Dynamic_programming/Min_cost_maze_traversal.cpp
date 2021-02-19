#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int> > vvi;

int min_cost_path(int r, int c, vvi &maze, vvi &dp){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(i == 0){
                dp[i][j] = maze[i][j] + dp[i][j - 1];
            }
            else if(j == 0){
                dp[i][j] = maze[i][j] + dp[i - 1][j];
            }
            else{
                dp[i][j] = maze[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[r - 1][c - 1];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c;
    cin >> r >> c;
    vvi maze(r, vi(c)), dp(r, vi(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> maze[i][j];
            dp[i][j] = INFI;
        }
    }
    dp[0][0] = maze[0][0];
    int min_cost = min_cost_path(r, c, maze, dp);
    cout << min_cost << '\n';
}