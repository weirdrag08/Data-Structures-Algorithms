#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<map>
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

    unordered_map<int, &list<int> > my_map;
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(my_map.count(v[i] - 1) > 0){
            my_map[v[i]] = my_map[v[i] - 1];
            my_map[v[i]]-> push_back(v[i]);
            my_map.erase(my_map[v[i] - 1]);
        }
        else{
            my_map[v[i]]-> push_back(v[i]);
        }
    }
    int max_size = 0;
    int key = -1;
    for(auto segment : my_map){
        if(segment.second-> size() > max_size){
            key = segment.first;
        }
    }
    for(auto segment : my_map[key]){
        cout << segment << '\n';
    }
}   