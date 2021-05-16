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
#include<unordered_set>
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

class Solution
{
public:
    void findWords_helper(int sx, int sy, string path, vector<vector<char> > &board, unordered_set<string> &uss, vector<string> &found)
    {
        if (sx < 0 || sx >= (int)board.size() || sy < 0 || sy >= board[0].size() || board[sx][sy] == '#')
            return;

        path += board[sx][sy];

        if (uss.find(path) != uss.end())
        {
            found.__emplace_back(path);
            uss.erase(path);
        }
        if (uss.empty())
            return;

        board[sx][sy] = '#';
        findWords_helper(sx - 1, sy, path, board, uss, found);
        findWords_helper(sx + 1, sy, path, board, uss, found);
        findWords_helper(sx, sy - 1, path, board, uss, found);
        findWords_helper(sx, sy + 1, path, board, uss, found);
        board[sx][sy] = path[path.size() - 1];
    }

    vector<string> findWords(vector<vector<char> > &board, vector<string> &words)
    {
        unordered_set<string> uss;
        for (int i = 0; i < (int)words.size(); i++)
            uss.insert(words[i]);
        vector<string> found;
        for (int i = 0; i < (int)board.size(); i++)
        {
            for (int j = 0; j < (int)board[0].size(); j++)
            {
                string path = "";
                findWords_helper(i, j, path, board, uss, found);
            }
        }
        return found;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<char> > matrix(n, vector<char>(m));
    vector<string> words(l);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < l; i++){
        cin >> words[i];
    }
    Solution s;
    vector<string> found_words = s.findWords(matrix, words);
    for(int i = 0; i < (int) found_words.size(); i++){
        cout << found_words[i] << " ";
    }
    cout << '\n';
}