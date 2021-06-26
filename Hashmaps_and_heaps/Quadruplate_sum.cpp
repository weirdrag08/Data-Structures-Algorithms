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

void get_two_sum(int l, int r, vi &v, int target, vector<deque<int> > &result, int &tri_val, int &quad_val){
    for(int i = l, j = r; i < j;){
        if(v[i] + v[j] < target)
            i++;
        else if(v[i] + v[j] > target)
            j--;
        else{
            deque<int> two_pair;
            two_pair.push_back(quad_val), two_pair.push_back(tri_val), two_pair.push_back(v[i]), two_pair.push_back(v[j]);
            result.__emplace_back(two_pair);
            i++, j--;
            while(i < j && v[i] == v[i - 1])
                i++;
            while(i < j && v[j] == v[j + 1])
                j--;    
        }        
    }
}

void get_three_sum(int l, int r, vi &v, int target, vector<deque<int> > &result, int &quad_val){
    for(int i = l; i <= r; i++){
        if(i != l && v[i] == v[i - 1])
            continue;
        get_two_sum(i + 1, r, v, target - v[i], result, v[i], quad_val);
    }
}

vector<deque<int> > get_four_sum(int l, int r, vi &v, int &target){
    sort(v.begin(), v.end());
    vector<deque<int> > result;
    for(int i = l; i <= r; i++){
        if(i != 0 && v[i] == v[i - 1])
            continue;
        get_three_sum(i + 1, r, v, target - v[i], result, v[i]);
    }
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cin >> target;
    vector<deque<int> > result = get_four_sum(0, n - 1, v, target);
    for(int i = 0; i < (int) result.size(); i++){
        for (auto j : result[i])
            cout << j << " ";
        cout << '\n';    
    }
}