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

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie();

    int n, target, count = 0;
    cin >> n;
    vi v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> target;
    vvb matrix(n + 1, vb(target + 1, false));
    for(int i = 0; i < n + 1; i++){
        matrix[i][0] = true;
    }
    matrix[1][v[1]] = true;

    for(int i = 2; i < n + 1; i++){
        for(int j = 1; j < target + 1; j++){
            if(v[i] > j){
                matrix[i][j] = matrix[i - 1][j];
            }
            else{
                if(matrix[i - 1][j]){
                    matrix[i][j] = matrix[i - 1][j];
                }
                else{
                   matrix[i][j] = matrix[i - 1][j - v[i]];
                }
            }
        }
    }
    bool subset = false;
    for(int i = 0; i < n + 1; i++){
        if(matrix[i][target]){
            cout << "true" << '\n';
            subset = true;
            break;
        }
    }
    if(!subset){
        cout << "false" << '\n';
    }
}