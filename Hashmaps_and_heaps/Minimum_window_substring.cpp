#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
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

    string s1, s2, temp = "", min_string = "";
    unordered_map<char, int> s1_map, s2_map;
    int match_count = 0, j = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.size(); i++){
        s2_map[s2[i]] += 1;
    }
    for(int i = 0; i < s1.size(); i++){
        if(match_count != s2.size()){
            if(s1_map[s1[i]] < s2_map[s1[i]]){
                match_count++;
            }
            temp += s1[i];
            s1_map[s1[i]] += 1;
        }
        else{
            while(j < i){
                if(s1_map[s1[j]] > s2_map[s1[j]]){
                    s1_map[s1[j]]--;
                    temp = temp.substr(1, i - j);
                    min_string = temp;
                    j++;
                }
                else{
                    temp = temp.substr(1, i - j);
                    s1_map[s1[j]]--;
                    match_count--;
                    break;
                }
            }
        }
    }
    cout << min_string << '\n';
}