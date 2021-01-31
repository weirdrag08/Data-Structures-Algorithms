#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

struct hash_pair
{
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
    unordered_map<pi, int, hash_pair> my_map;
    int n, element, ones = 0, twoes = 0, zeroes = 0, diff01, diff12, max_size = 0;
    cin >> n;
    my_map[mp(0, 0)] = -1;
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

        if (my_map.count(mp(diff01, diff12)) > 0){
            int prev_index = my_map[mp(diff01, diff12)];
            max_size = max(max_size, i - prev_index);
        }
        else{
            my_map[mp(diff01, diff12)] = i;
        }
    }
    cout << max_size << '\n';
}