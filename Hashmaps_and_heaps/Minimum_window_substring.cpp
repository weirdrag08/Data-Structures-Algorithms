#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    string org, s;
    cin >> org >> s;
    unordered_map<char, int> my_map, match;
    for(int i = 0; i < match.size(); i++){
        if(match.count(s[i]) > 0){
            match[s[i]]++;
        }
        else{
            match[s[i]] = 1;
        }
    }
    int match_count = 0;
    string *result = new string();
    *result = "";
    for(int i = 0, j = 0; i < org.size(); i++){
        if(match_count != s.size()){
            my_map[org[i]] += 1;
            if(match.count(org[i]) > 0){
                if(my_map[org[i]] < match[org[i]]){
                    match_count++;
                }
            }
            *result += org[i];
        }
        else{
            string *new_result = new string();
            *new_result = "";
            for(int j = 0; j < result-> size(); j++){
                if(my_map[org[j]] >= match[org[j]]){
                    
                }
                j++;
            }
        }
    }

}