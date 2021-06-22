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

int get_rabbits(unordered_map<int, int> &my_map){
    int total_rabbits = 0;
    for(auto individual : my_map){
        total_rabbits += (individual.first + 1) * ceil((float) individual.second / (individual.first + 1));
    }
    return total_rabbits;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, element;
    cin >> n;
    unordered_map<int, int> my_map;
    for(int i = 0; i < n; i++){
        cin >> element;
        my_map[element] += 1;
    }
    cout << get_rabbits(my_map) << '\n';

}