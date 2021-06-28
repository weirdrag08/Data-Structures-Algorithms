#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
using namespace std;

#define mp make_pair
#define pb push_back
#define INFI 10e8
#define INF 10e7
#define mod 1000000007
#define sieve_limit 10e6

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
typedef vector<vector<bool> > vvb;

vector<string> count_unique_substring(string &s){
    // TODO: i -> acquire, j -> release
    unordered_map<char, int> my_map;
    vector<string> all_substring;
    for(int i = 0, j = -1; i < (int) s.size(); i++){
        my_map[s[i]] += 1;
        if(my_map[s[i]] > 1){
            while(my_map[s[i]] > 1){
                j++;
                my_map[s[j]]--;
            }
        }
        for(int k = j + 1, l = 0; k <= i; k++, l++)
            all_substring.__emplace_back(s.substr(k, i - j - l));
    }
    return all_substring;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<string> result = count_unique_substring(s);
    cout << result.size() << '\n';
    for(string i : result)
        cout << i << '\n';
}