#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
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
    cout.tie(NULL);

    int n, m, element;
    cin >> n;
    vi arr1(n);
        map<int, int> my_map;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        if(my_map.count(arr1[i]) > 0){
            my_map[arr1[i]]++;
        }
        else{
            my_map[arr1[i]] = 1;
        }
    }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> element;
            if(my_map.count(element) > 0){
                cout << element << '\n';
                my_map[element]--;
                if(my_map[element] == 0){
                    my_map.erase(element);
                }
            }
        }
}
