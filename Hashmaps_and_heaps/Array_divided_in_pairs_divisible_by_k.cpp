#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
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
    unordered_map<int, int> my_map;
    int n, k, rem;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    for(int i = 0; i < n; i++){
        rem = v[i] % k;
        my_map[rem] += 1;
    }
    bool divisible = true;
    if (my_map[0] % 2 != 0 || (k % 2 == 0 && my_map[k / 2] % 2 != 0)){
        divisible = false;
        cout << "false" << '\n';
    }

    else{
        for(auto remains : my_map){
            if(remains.first != 0 && my_map[remains.first] != my_map[k - remains.first]){
                divisible = false;
                cout << "false" << '\n';
                break;
            }
        }
    }

    if(divisible){
        cout << "true" << '\n';
    }

}