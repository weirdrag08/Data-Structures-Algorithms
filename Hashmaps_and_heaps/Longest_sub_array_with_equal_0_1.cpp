#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<utility>
#include<string>
#include<algorithm>
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
    
    unordered_map<int, int> my_map;
    int n, element, sum = 0, max_size = 0;
    cin >> n;
    my_map[sum] = -1;
    for(int i = 0; i < n; i++){
        cin >> element;
        if(element == 0){
            element = -1;
        }
        sum += element;
        if(my_map.count(sum) > 0){
            int prev_index = my_map[sum];
            max_size = max(max_size, i - prev_index);
        }
        else{
            my_map[sum] = i;
        }
    }

    cout << max_size << '\n';
}