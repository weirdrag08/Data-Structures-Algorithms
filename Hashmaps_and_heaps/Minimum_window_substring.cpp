#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<string>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int match_size = s2.size(), match_count = 0;
    unordered_map<char, int> s2_map, s1_map;
    for(int i = 0; i < s2.size(); i++){
        s2_map[s2[i]] += 1;
    }
    string temp = "";
    int j = 0;
    for(int i = 0; i < s1.size() || j < s1.size();){
        if (match_count != s2.size() && i < s1.size()){
            if(s1_map[s1[i]] < s2_map[s1[i]]){
                match_count++;
            }
            s1_map[s1[i]] += 1;
            temp += s1[i];
            //cout << temp << '\n';
            i++;
        }
        else{
            for(;j < i;){
                if(s1_map[s1[j]] > s2_map[s1[j]] || s2_map.count(s1[j]) == 0){
                    s1_map[s1[j]]--;
                    cout << temp << '\n';
                    temp = temp.substr(j + 1, i - j);
                    cout << temp << '\n' << '\n';
                    j++;
                }
                else if(s1_map[s1[j]] <= s2_map[s1[j]]){
                    //temp = temp.substr(j + 1, i - j);
                    match_count--;
                    break;
                }
                //cout << temp << '\n';
            }
        }
    }
    // if(match_count != s2.size()){
    //     temp += s1[j];
    // }
    cout << temp << '\n';
}