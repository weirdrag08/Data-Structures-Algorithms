#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<climits>
#include<utility>
#include<math.h>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef long long ll;

class median_pq{
public:
    priority_queue<int> pql;
    priority_queue<int, vi, greater<int> > pqr;

    void add(int element){
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
                int top = pql.top();
                pql.pop();
                pqr.push(top);
            }
            else{
                int top = pqr.top();
                pqr.pop();
                pql.push(top);
            }
        }
    }

    void peek(){
        if(pql.empty() && pqr.empty()){
            cout << "Underflow" << '\n';
        }

       else if(pql.size() == pqr.size()){
            cout << pql.top() << '\n';
        }
        else{
            if(pql.size() > pqr.size()){
                cout << pql.top() << '\n';
            }
            else{
                cout << pqr.top() << '\n';
            }
        }
    }

    void remove(){

        if(pql.empty() && pqr.empty()){
            cout << "Underflow" << '\n';
        }

       else if(pql.size() == pqr.size()){
            cout << pql.top() << '\n';
            pql.pop();
        }
        else{
            if(pql.size() > pqr.size()){
                cout << pql.top() << '\n';
                pql.pop();
            }
            else{
                cout << pqr.top() << '\n';
                pqr.pop();
            }
        }
    }

    void get_size(){
        cout << pql.size() + pqr.size() << '\n';
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "";
    median_pq median;
    do{
        cin >> s;
        if (s == "add"){
            int element;
            cin >> element;
            median.add(element);
        }
        
        else if(s == "peek"){
            median.peek();
        }

        else if(s == "remove"){
            median.remove();
        }

        else if(s == "size"){
            median.get_size();
        }
    }       
    while(s != "quit");
}