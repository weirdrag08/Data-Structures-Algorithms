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

int max_gold_path(int r, int c, vvi &mine, vvi &dp){
    for(int j = 1; j < c; j++){
        for(int i = 0; i < r; i++){
            if(i == 0){
                dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i + 1][j - 1]);
            }
            else if(i == r - 1){
                dp[i][j] = mine[i][j] + max(dp[i][j - 1], dp[i - 1][j - 1]);
            }
            else{
                dp[i][j] = mine[i][j] + max(dp[i][j - 1], max(dp[i - 1][j - 1], dp[i + 1][j - 1]));
            }
        }
    }
    int max_gold = INT_MIN;
    for(int i = 0; i < r; i++){
        max_gold = max(dp[i][c - 1], max_gold);
    }
    return max_gold;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vvi mine(r, vi(c)), dp(r, vi(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mine[i][j];
            if(j == 0){
                dp[i][j] = mine[i][j]; // * To fill the left wall
            }
        }
    }
    int max_gold = max_gold_path(r, c, mine, dp);
    cout << max_gold << '\n';
}