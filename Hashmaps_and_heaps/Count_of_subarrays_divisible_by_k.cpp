#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<string>
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
    unordered_map<int, int> my_map;
    int n, k, sum = 0, rem, count = 0;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    my_map[0] = 1;
    for(int i = 0; i < n; i++){
        sum += v[i];
        rem = sum % k;
        if(rem < 0){
            rem += k;
        }
        int times = my_map[rem];
        count += times;
        my_map[rem]++;
    }
    cout << count << '\n';
}


