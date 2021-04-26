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

void rotate(vvi &matrix)
{

    for (int g = 1; g < (int)matrix.size(); g++)
    {
        for (int i = 0, j = g; j < (int)matrix.size(); i++, j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for (int i = 0, j = (int)matrix.size() - 1; i < j; i++, j--)
    {
        for (int k = 0; k < (int)matrix.size(); k++)
        {
            int temp = matrix[k][i];
            matrix[k][i] = matrix[k][j];
            matrix[k][j] = temp;
        }
    }
    return;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvi matrix(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] <<  " ";
        }
        cout << '\n';
    }
}