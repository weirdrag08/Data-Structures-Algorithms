#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
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
    cout.tie(NULL);

    int n, k;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    priority_queue<int, vi, greater<int> > pq;
    for(int i = 0; i < n;){
        while(pq.size() != k + 1){
            pq.push(v[i]);
            i++;
        }
        if(i == n){
            while(!pq.empty()){
                cout << pq.top() << '\n';
                pq.pop();
            }
            break;
        }
        cout << pq.top() << '\n';
        pq.pop();
    } 
}
