#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
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
    unordered_map<int, int> my_map;
    int n, k, rem;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    for(int i = 0; i < v.size(); i++){
        rem = v[i] % k;
        my_map[rem] += 1;
    }
    bool divisible = true;
    for(auto remainders : my_map){
        if((my_map[remainders.first] == my_map[k - remainders.first]) || (my_map[0] % 2 == 0) || (k % 2 == 0 && (my_map[k / 2] % 2 == 0))){
            continue;
        }
        else{
            cout << "false" << '\n';
            divisible = false;
            break;
        }
    }
    if(divisible){
        cout << "true" << '\n';
    }
}