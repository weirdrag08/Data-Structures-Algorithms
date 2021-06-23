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

class triplet{
public:
    int findex, sindex, frq;

    triplet(){
        this-> findex = 0;
        this-> sindex = 1000000;
        this-> frq = 0;
    }

    triplet(int findex, int sindex, int frq){
        this-> findex = findex;
        this-> sindex = sindex;
        this-> frq = frq;
    }    
};

void smallest_subarray(int &n, vi &v){
    unordered_map<int, triplet> my_map;
    for(int i = 0; i < n; i++){
        if(my_map.count(v[i]) > 0)
            my_map[v[i]].sindex = i, my_map[v[i]].frq++;
        else{
            triplet element(i, i, 1);
            my_map[v[i]] = element;
        }   
    }
    triplet result(0, 1000000, 0);
    int key = 0;
    for(auto element : my_map){
        if(element.second. frq == result. frq){
            if(element.second. sindex - element.second. findex < result. sindex - result. findex)
                result = element.second, key = element.first;
            else if(element.second. sindex - element.second. findex == result. sindex - result. findex && element.second. findex < result. findex)
                result = element.second, key = element.first;    
        }
       else if(element.second. frq > result. frq)
            result = element.second, key = element.first;
    }
    cout << key << '\n' << result. findex << '\n' << result. sindex << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    smallest_subarray(n, v);
}