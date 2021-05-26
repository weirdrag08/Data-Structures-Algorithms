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

class Node
{
public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};

Node *input()
{
    stack<Node *> *stk = new stack<Node *>;
    int element, root_data, size;
    cin >> size >> root_data;
    Node *root = new Node(root_data);
    stk->push(root);
    while (!stk->empty())
    {
        cin >> element;
        if (element == -1)
        {
            stk->pop();
        }
        else
        {
            Node *new_node = new Node(element);
            stk->top()->children.push_back(new_node);
            stk->push(new_node);
        }
    }
    return root;
}

void pred_and_succ(Node *root, int &pred, int &succ, int &target, int target_data){
    if(root == NULL)
        return;
    if(target != INT_MIN && succ == INT_MIN)
        succ = root-> data;
    if(root-> data == target_data)
        target = root-> data;
    if(target == INT_MIN)
        pred = root-> data; 
     for(int i = 0; i < (int) root-> children.size(); i++)
        pred_and_succ(root-> children[i], pred, succ, target, target_data);          
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int pred = INT_MIN, succ = INT_MIN, target = INT_MIN;
    int target_data;
    cin >> target_data;
    pred_and_succ(root, pred, succ, target, target_data);
    if(pred != INT_MIN)
        cout << "Predecessor = " << pred << '\n';
    else
        cout << "Predecessor = Not found" << '\n';    
    if(succ != INT_MIN)
        cout << "Successor = " << succ << '\n';
    else 
        cout << "Successor = Not found" << '\n';
}