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
    
    int tc;
    cin >> tc;
    for(int k = 0; k < tc; k++){
        unordered_map<char, int> s1_chars, s2_chars;
        string s;
        cin >> s;
        int match_diff = 0;
        bool match = true;
        if (s.size() % 2 != 0)
        {
            match = false;
            cout << "-1" << '\n';
            continue;
        }
        for (int i = 0, j = (s.size() / 2); i < (s.size() / 2); i++, j++)
        {
            s1_chars[s[i]] += 1;
            s2_chars[s[j]] += 1;
        }

        for (auto character : s2_chars)
        {
            if (s1_chars.count(character.first) == 0 || s2_chars[character.first] > s1_chars[character.first])
            {
                match_diff += s2_chars[character.first] - s1_chars[character.first];
            }
        }
        cout << match_diff << '\n';
    }
}