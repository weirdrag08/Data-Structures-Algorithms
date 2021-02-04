#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
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

    priority_queue<int, vi, greater<int> > pq; 
    int n, k, element, first, second, net_sweetness, count = 0;
    bool possible = true;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> element;
        pq.push(element);
    }
    while(!pq.empty()){
       if(pq.top() >= k){
           break;
       }
       else{
           first = pq.top();
           pq.pop();
          if(pq.empty()){
              possible = false;
              count = -1;
              break;
          }
          second = pq.top();
          pq.pop();
          net_sweetness = ((1 * first) + (2 * second));
          count++;
          pq.push(net_sweetness);
       }
    }
    cout << count << '\n';
}