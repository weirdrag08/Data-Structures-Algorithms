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

const int dx[6] = {-2, -2, 0, 2, 2, 0};
const int dy[6] = {-1, 1, 2, 1, -1, -2};
const string ds[6] = {"UL", "UR", "R", "LR", "LL", "L"};
class cell{
public:
    int x, y, len;
    string path;

    cell(int x, int y, int len, string path){
        this-> x = x;
        this-> y = y;
        this-> len = len;
        this-> path = path;
    }    
};

bool valid(int x, int y, int &n, vvb &matrix){
    if(x < 0 || x >= n || y < 0 || y >= n || matrix[x][y])
        return false;
    return true;   
}


void shortest_path(int &si, int &sj, int &ei, int &ej, vvi &distance, vvb &matrix, int &n){
    queue<cell> q;
    bool reached = false;
    cell src(si, sj, 0, "");
    distance[si][sj] = 0;
    q.push(src);
    matrix[src.x][src.y] = true;
    while(!q.empty()){
        cell front = q.front();
        q.pop();
        
        if(front.x == ei && front.y == ej){
            front.path.erase(0, 1);
            cout << front.len << '\n' << front.path << '\n';
            reached = true;
            break;
        }
        for(int i = 0; i < 6; i++){
            if(valid(front.x + dx[i], front.y + dy[i], n, matrix) && front.len + 1 < distance[front.x + dx[i]][front.y + dy[i]]){
                cell neighbour(front.x + dx[i], front.y + dy[i], front.len + 1, front.path + " " + ds[i]);
                q.push(neighbour);
                matrix[neighbour.x][neighbour.y] = true;
            }
        }  
    }
    if(!reached)
        cout << "Impossible" <<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvb matrix(n, vb(n, false));
    vvi distance(n, vi(n, INT_MAX));
    int si, sj, ei, ej;
    cin >> si >> sj >> ei >> ej;
    shortest_path(si, sj, ei, ej, distance, matrix, n);
}