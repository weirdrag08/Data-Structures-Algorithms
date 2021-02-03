#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
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
    
    unordered_map<char, int> s1_chars, s2_chars;
    string s1, s2;
    int k, match_diff = 0;
    bool match_limit = true;
    cin >> s1 >> s2 >> k;
    for(int i = 0; i < s1.size(); i++){
        s1_chars[s1[i]] += 1;
        s2_chars[s2[i]] += 1;
    }

    for(auto character : s2_chars){
        if(s1_chars.count(character.first) == 0 || (s2_chars[character.first] > s1_chars[character.first])){
            match_diff += s2_chars[character.first] - s1_chars[character.first];
        }
        if(match_diff > k){
            cout << "false" << '\n';
            match_limit = false;
            break;
        }
    }
    if(match_limit){
        cout << "true" << '\n';
    }
}