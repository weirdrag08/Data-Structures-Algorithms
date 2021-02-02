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

    unordered_map<char, int> s1_chars, s2_chars;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        s1_chars[s1[i]] += 1;
    }
    for(int i = 0; i < s2.size(); i++){
        s2_chars[s2[i]] += 1;
    }
    bool anagram = true;
    for(auto character : s2_chars){
        if(s1_chars.size() != s2_chars.size()){
            anagram = false;
            cout << "false" << '\n';
            break;
        }
        if(s1_chars.count(character.first) == 0 || s1_chars[character.first] != s2_chars[character.first]){
            anagram = false;
            cout << "false" << '\n';
            break;
        }
    }
    if(anagram){
        cout << "true" << '\n';
    }
}