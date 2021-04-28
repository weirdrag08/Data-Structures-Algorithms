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

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        if (obstacleGrid[0][0])
            return 0;

        obstacleGrid[0][0] = 1;
        for (int i = 0; i < (int)obstacleGrid.size(); i++)
        {
            for (int j = 0; j < (int)obstacleGrid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;

                else if (obstacleGrid[i][j])
                    obstacleGrid[i][j] = 0;

                else if (!obstacleGrid[i][j])
                {
                    if (i == 0)
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                    else if (j == 0)
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                    else
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                }
            }
        }
        return obstacleGrid[(int)obstacleGrid.size() - 1][(int)obstacleGrid[0].size() - 1];
    }

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > obstacleGrid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> obstacleGrid[i][j];
        }
    }
    cout <<  uniquePathsWithObstacles(obstacleGrid) << '\n';
}