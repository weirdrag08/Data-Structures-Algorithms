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

    unordered_map<char, char> my_map, visited;
    string s1, s2;
    cin >> s1 >> s2;
    bool isomorphic = true;
    for(int i = 0; i < s1.size(); i++){

       if(visited.count(s2[i]) > 0){
           if (visited[s2[i]] != s1[i]){
               cout << "false" << '\n';
               isomorphic = false;
               break;
           }
       }

        if(my_map.count(s1[i]) > 0){
            if(my_map[s1[i]] != s2[i]){
                cout << "false" << '\n';
                isomorphic = false;
                break;
            }
        }
        else{
            my_map[s1[i]] = s2[i];
            visited[s2[i]] = s1[i];
        }
    }
    if(isomorphic){
        cout << "true" << '\n';
    }
}