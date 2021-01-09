#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<unordered_set>
#include<queue>
#include<stack>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

void max_frequency(string s){
    unordered_map<char, int> my_map;

    for(int i = 0; i < s.size(); i++){
        if(my_map.count(s[i]) > 0){
            my_map[s[i]]++;
        }
        else{
            my_map[s[i]] = 1;
        }
    }
    pair<char, int> p('\0', INT_MIN);

    for(auto character : my_map){
        if(character.second >= p.second){
            p.first = character.first;
            p.second = character.second;
        }
    }
    cout << p.first << '\n';
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    max_frequency(s);
}