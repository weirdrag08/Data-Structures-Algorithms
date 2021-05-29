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

void iterative_pre_post(Node *root){
    stack<pair<Node*, int> > my_stack;
    vi preorder, postorder;
    // * 1) Node -> status : -1 (push in preorder, just visiting)
    // * 2) Node -> status : 0 - children.size() - 1 (push child in stack)
    // * 3) Node -> status : children.size() (have pushed all the children in stack, and now we are in postorder wrt to current node, so push in postorder)
    my_stack.push(mp(root, -1));
    while(!my_stack.empty()){
        auto top = my_stack.top();
        my_stack.pop();
        if(top.second == -1){ // * 1st condition
            preorder.pb(top.first-> data);
            top.second++;
            my_stack.push(top);
        } 
        else if(top.second >= 0 && top.second < top.first-> children.size()){ // * 2nd condition
            auto child = mp(top.first-> children[top.second], -1);
            top.second++;
            my_stack.push(top);
            my_stack.push(child);
        }
        else if(top.second >= top.first-> children.size()){ // * 3rd condition
            postorder.pb(top.first-> data);
        }
    }
    for(int i : preorder)
        cout << i << " ";
    cout << '\n';
    for(int i : postorder)
        cout << i << " ";
    cout << '\n';    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    iterative_pre_post(root);
}