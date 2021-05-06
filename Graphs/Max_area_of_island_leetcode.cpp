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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;

int dfs(int si, int sj, int n, int m, vvi &matrix, vvb &visited)
{
    if (si < 0 || si >= n || sj < 0 || sj >= m || visited[si][sj] || matrix[si][sj] == 0)
        return 0;

    visited[si][sj] = true;
    return 1 + dfs(si - 1, sj, n, m, matrix, visited) + dfs(si + 1, sj, n, m, matrix, visited) + dfs(si, sj - 1, n, m, matrix, visited) + dfs(si, sj + 1, n, m, matrix, visited);
}

int max_size_island(int n, int m, vvi &matrix)
{
    vvb visited(n, vb(m, false));
    int _max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && matrix[i][j] == 1)
                _max = max(_max, dfs(i, j, n, m, matrix, visited));
        }
    }
    return _max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vvi matrix(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << max_size_island(n, m, matrix) << '\n';
}