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
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;

vb *v_sieve = new vb(sieve_limit + 1, false);

void sieve(){
    
    // * As we know that 2 is the only even number which is prime, so we mark all the odd numbers as potentially prime(like they can be prime or non prime). But all the even number except 2 are non prime because they always have one divisor in common which is 2
    for (int i = 3; i <= sieve_limit; i += 2){
        v_sieve->at(i) = true;
    }

    // * 2 is the only even number which is prime
    v_sieve->at(2) = true;

    for (int i = 3; i * i <= sieve_limit; i++){
        if (v_sieve->at(i)){
            for (int j = i * i; j <= sieve_limit; j += i){
                v_sieve->at(j) = false;
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++){
        int n;
        cin >> n;
        vll dp(n + 1, 0);
        for (int j = 1; j <= n; j++){
            if (j < 4){
                dp[j] = 1;
            }
            else if (j == 4){
                dp[j] = 2;
            }
            else{
                dp[j] = dp[j - 1] + dp[j - 4];
            }
        }
        ll max_range = dp[n];
        ll prime_count = 0;
        for (int i = 0; i <= max_range; i++){
            if (v_sieve->at(i)){
                prime_count++;
            }
        }
        cout << prime_count << '\n';
    }
}