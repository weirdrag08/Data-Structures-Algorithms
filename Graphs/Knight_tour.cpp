#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<set>
#include<unordered_set>
using namespace std;

struct pair_hash{
    template <class T1, class T2>
    std::size_t operator()(std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unordered_set<pi, pair_hash> usp;
typedef vector<vi> vvi;


void knight_tour_helper(int n, int sx, int sy, int count, vvi chess_board, usp &visited){
    if(sx >= n || sy >= n || sx < 0 || sy < 0 || visited.find(mp(sx, sy)) != visited.end()){
        return;
    }

    visited.insert(mp(sx, sy));
    count++;
    chess_board[sx][sy] = count;
   
    knight_tour_helper(n, sx + 1, sy - 2, count, chess_board, visited);
    knight_tour_helper(n, sx + 2, sy - 1, count, chess_board, visited);
    knight_tour_helper(n, sx + 2, sy + 1, count, chess_board, visited);
    knight_tour_helper(n, sx + 1, sy + 2, count, chess_board, visited);
    knight_tour_helper(n, sx - 1, sy + 2, count, chess_board, visited);
    knight_tour_helper(n, sx - 2, sy + 1, count, chess_board, visited);
    knight_tour_helper(n, sx - 2, sy - 1, count, chess_board, visited);
    knight_tour_helper(n, sx - 1, sy - 2, count, chess_board, visited);

    if (visited.size() == n * n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << chess_board[i][j] << " ";
            }
            cout << '\n';
        }
    }
}

void knight_tour(int n, int sx, int sy){
    usp visited;
    int count = 0;
    vvi chess_board(n, vi(n, 0));
    knight_tour_helper(n, sx, sy, count, chess_board, visited);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sx, sy;
    cin >> n >> sx >> sy;
    knight_tour(n, sx, sy);
}