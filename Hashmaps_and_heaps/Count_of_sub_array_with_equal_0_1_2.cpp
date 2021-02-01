#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;

struct hash_pair{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

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
    
    unordered_map<pi, int, hash_pair> my_map;
    int n, element, zeroes = 0, ones = 0, twoes = 0, count = 0, diff01, diff12;
    cin >> n;
    my_map[mp(0, 0)] = 1;
    for(int i = 0; i < n; i++){
        cin >> element;
        if(element == 0){
            zeroes++;
        }
        else if(element == 1){
            ones++;
        }
        else{
            twoes++;
        }
        diff01 = ones - zeroes;
        diff12 = twoes - ones;
        count += my_map[mp(diff01, diff12)];
        my_map[mp(diff01, diff12)] += 1;
    }

    cout << count << '\n';
}