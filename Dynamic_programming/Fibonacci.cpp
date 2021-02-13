#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v;
    v.push_back(0);
    v.push_back(1);
    for(int i = 2; i <= n; i++){
        v.push_back(v[i - 1] + v[i - 2]);
    }
    cout << v[n] << '\n';
}