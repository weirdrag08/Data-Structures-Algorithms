#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
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
    unordered_map<int, int> my_map;
    int n, element, k;
    cin >> n;
    vi v(n);
    // if(n % 2 != 0){
    //     cout << "false" << '\n';
    // }
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    for(int i = 0; i < n; i++){
        element = v[i] % k;
        if(my_map.count(element) > 0){
            my_map[element]++;
        }
        else{
            my_map[element] = 1;
        }
    }
    
    bool not_paired = false;
    for(unordered_map<int, int>::iterator it = my_map.begin(); it != my_map.end(); it++){
        if(my_map.count(k - (it-> first)) > 0){
            my_map[k - (it-> first)]--;
            my_map[it-> first]--;
            if(my_map[k - (it-> first)] == 0){
                my_map.erase(k - (it-> first));
            }
            if(my_map[it-> first] == 0){
                my_map.erase(it-> first);
            }
        }
        else{
            not_paired = true;
            break;
        }
    }
    if(not_paired){
        cout << "false" << '\n';
    }
    else{
        cout << "true" << '\n';
    }
}