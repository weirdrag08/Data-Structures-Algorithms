#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
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

    vector<list<pi> *> v;
    int k, n, element;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> n;
        list<pi> *my_list = new list<pi>();
        for(int j = 0; j < n; j++){
            cin >> element;
            my_list-> push_back(mp(element, i));
        }
        v.push_back(my_list);
    }
    priority_queue<pi, vector<pi>, greater<pi> >pq; 
    int l = 0;
    while(pq.size() != k){
        pq.push(v[l]-> front());
        l++;
    }

    while(!pq.empty()){
        pi top = pq.top();
        pq.pop();
        cout << top.first << " ";
        v[top.second]->pop_front();
        if (v[top.second]->size() == 0){
            continue;
        }
        pq.push(v[top.second]-> front());
    }
}