#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<algorithm>
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
    unordered_map<int, int> my_map;
    int n, element, prev_sum = 0, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> element;
        prev_sum += element;
        if(my_map.count(prev_sum) > 0){
            int times = my_map[prev_sum];
            count += times;
        }
        my_map[prev_sum]++;
    }
    cout << count << '\n';
}