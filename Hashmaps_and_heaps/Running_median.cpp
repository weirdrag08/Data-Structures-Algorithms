#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>
#include <math.h>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef long long ll;

class median_pq{

priority_queue<float> pql;
priority_queue<float, vector<float>, greater<float> > pqr;

public: 
    void add(float element){
        if(!pqr.empty() && element > pqr.top()){
            pqr.push(element);
        }
        else{
            pql.push(element);
        }
        int rem = pql.size() - pqr.size();
        rem = abs(rem);
        if(rem > 1){
            if(pql.size() > pqr.size()){
                float top = pql.top();
                pql.pop();
                pqr.push(top);
            }
            else if(pql.size() < pqr.size()){
                float top = pqr.top();
                pqr.pop();
                pql.push(top);
            }
        }
    }

    float median(){
        if(pql.size() == pqr.size()){
            return (pql.top() + pqr.top())/2;
        }
        else{
            if(pql.size() > pqr.size()){
                return pql.top();
            }
            else{
                return pqr.top();
            }
        }
    }

};

int main(){
    median_pq pq;
    int n;
    float element;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> element;
        pq.add(element);
        float median = pq.median();
        printf("%0.2f \n", median);
    }
}
