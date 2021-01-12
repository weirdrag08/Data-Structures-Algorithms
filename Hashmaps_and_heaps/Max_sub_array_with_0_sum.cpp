#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
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
    int n;
    cin >> n;
    unordered_map<int, int> my_map;
    int size = 0, element, prev_sum = 0;
    my_map[prev_sum] = -1;
    for(int i = 0; i < n; i++){
        cin >> element;
        prev_sum += element;
        if(my_map.count(prev_sum) > 0){
            int prev_index = my_map[prev_sum];
            size = max(i - prev_index, size);
        }
        else{
            my_map[prev_sum] = i;
        }
    }
    cout << size << '\n';
}