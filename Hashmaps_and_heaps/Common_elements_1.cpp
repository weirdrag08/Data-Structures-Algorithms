#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#include<string>
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
    unordered_map<int, int> my_map;

    for(int i = 0; i < n; i++){
        cin >> element;
        if(my_map.count(element) > 0){
            my_map[element]++;
        }
        else{
            my_map[element] = 1;
        }
    }
    cin >> m;
     for (int i = 0; i < m; i++){
        cin >> element;
        if(my_map.count(element) > 0){
            cout << element << '\n';
            my_map.erase(element);
        }
    }
}