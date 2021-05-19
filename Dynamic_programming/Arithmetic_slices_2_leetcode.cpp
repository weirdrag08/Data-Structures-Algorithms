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
    vi v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<unordered_map<long long, int> > store_cd(n);
    int total_ap = 0;
    long long cd = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            cd = (long long) v[i] - (long long) v[j];
            if(store_cd[j].count(cd) > 0){
                total_ap += store_cd[j][cd]; // * sequence of more than 3 length
                store_cd[i][cd] += store_cd[j][cd] + 1;
            }
            else
                store_cd[i][cd] += 1; // * only of 2 length, so it won't be added to the answer.
        }
    }
   cout << total_ap << '\n';
}

