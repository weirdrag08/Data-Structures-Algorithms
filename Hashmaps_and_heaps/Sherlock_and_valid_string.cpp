#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
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

    unordered_map<char, int> my_map, count_map;
    string s;
    int minimum = INT_MAX, limit = 0;
    bool valid = true;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        my_map[s[i]] += 1;
    }

    for(auto character : my_map){
        count_map[character.second] += 1;
    }

    if(count_map.size() > 2){
        valid = false;
        cout << "NO" << '\n';
    }

    if(count_map.size() == 2){
        
    }
   
    if(valid){
        cout << "YES" << '\n';
    }

}