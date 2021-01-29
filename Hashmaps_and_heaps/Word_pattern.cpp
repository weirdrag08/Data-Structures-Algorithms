#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<string>
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
    unordered_map<string, char> my_map;
    string s1 = "", s2 = "", temp = "";
    getline(cin, s1);
    getline(cin, s2);
    bool rhyme = true;
    int j = 0;
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] == ' '){
            if(my_map.count(temp) > 0){

                if(my_map[temp] != s1[j]){
                    cout << "false" << '\n';
                    rhyme = false;
                    break;
                }
            }
            else{
                my_map[temp] = s1[j];
            }
            temp = "";
            j++;
        }
        else{
            temp += s2[i];
        }
    }

    if(rhyme){
        if((my_map.count(temp) > 0 && my_map[temp] == s1[j]) || my_map.count(temp) == 0){
            cout << "true" << '\n';
        }
        else{
            cout << "false" << '\n';
        }
    }
}