#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
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
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<char, int> my_map;
    string s;
    bool found = false;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        my_map[s[i]] += 1;
    }
    for(int i = 0; i < s.size(); i++){
        if(my_map[s[i]] == 1){
            cout << i << '\n';
            found = true;
            break; 
        }
    }
    if(!found){
        cout << -1 << '\n';
    }
}