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

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> words(n);
    unordered_map<string, int> dict;
    for(int i = 0; i < n; i++){
        cin >> words[i];
        dict[words[i]] += 1;
    }
    string sentence;
    cin >> sentence;
    vi dp((int) sentence.size(), 0);
    for(int i = 0; i < (int) sentence.size(); i++){
        for(int j = 0; j <= i; j++){
            string suffix = sentence.substr(j, i + 1 - j);
            if(dict.count(suffix) > 0){
                if(j == 0)
                    dp[i] += 1;
                else
                    dp[i] += dp[j - 1];
            }
        }
    }
    cout << dp[(int) sentence.size() - 1] << '\n';
}