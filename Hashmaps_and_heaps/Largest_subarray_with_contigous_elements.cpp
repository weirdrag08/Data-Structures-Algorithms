#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<utility>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int length = 0;
    for(int i = 0; i < n - 1; i++){
        unordered_map<int, int> my_map;
        my_map[v[i]] = 1;
        int minimum = INT_MAX, maximum = INT_MIN;
        maximum = max(maximum, v[i]);
        minimum = min(minimum, v[i]);
        for(int j = i + 1; j < n; j++){
            if(minimum != INT_MAX && maximum != INT_MIN && (maximum - minimum) > n){
                break;
            }
           
            if(my_map.count(v[j]) > 0){
                break;
            }
            my_map[v[j]] = 1;
            minimum = min(minimum, v[j]);
            maximum = max(maximum, v[j]);

            if(maximum - minimum == j - i){
                length = max(length, (j - i + 1));
            }
        }   
    }
    cout << length << '\n';
}