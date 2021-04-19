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

int count_submatrices(vvi &matrix, int target){
    int n = (int) matrix.size(), m = (int) matrix[0].size(), count = 0;
    vvi prefix_sum(n, vi(m, 0));
    for(int i = 0; i < n; i++){
        prefix_sum[i][0] = matrix[i][0];
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            prefix_sum[i][j] = prefix_sum[i][j - 1] + matrix[i][j];
        }
    }

    for(int k = 0; k < m; k++){
        for(int j = k; j < m; j++){
            unordered_map<int, int> my_map;
            int matrix_sum = 0;
            for(int i = 0; i < n; i++){
                if(k == 0){
                    matrix_sum += prefix_sum[i][j];
                    matrix_sum == target ? count++ : count = count;
                    if(my_map.count(matrix_sum - target) > 0){
                        count += my_map[matrix_sum - target];
                    }
                    my_map[matrix_sum] += 1;
                }
                else{
                    matrix_sum += prefix_sum[i][j] - prefix_sum[i][k - 1];
                    matrix_sum == target ? count++ : count = count;
                    if(my_map.count(matrix_sum - target) > 0){
                        count += my_map[matrix_sum - target];
                    }
                    my_map[matrix_sum] += 1;
                }
            }
        }
    }
    return count;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, target;
    cin >> n >> m;
    vvi matrix(n, vi(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    cin >> target;
    int count = count_submatrices(matrix, target);
    cout << count << '\n';
}