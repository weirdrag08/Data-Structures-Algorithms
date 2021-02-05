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
    int minimum = INT_MAX, maximum = INT_MIN, limit = 0;
    bool valid = true;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        my_map[s[i]] += 1;
    }

    for(auto character : my_map){
        cout << "Character: " << character.first << " " << " Count: " << character.second << '\n';
    }
    for(auto character : my_map){
        count_map[character.second] += 1;
        minimum = min(minimum, character.second);
        maximum = max(maximum, character.second);
    }

    if(count_map.size() > 2){
        valid = false;
        cout << "NO" << '\n';
    }
    
    if(count_map.size() == 2){
       if((maximum - minimum > 1 && minimum != 1 && count_map[minimum] != 1) || (count_map[maximum] != 1 && count_map[minimum] != 1)){
           valid = false;
           cout << "NO" << '\n';
       }
    }

    if(valid){
        cout << "YES" << '\n';
    }

}