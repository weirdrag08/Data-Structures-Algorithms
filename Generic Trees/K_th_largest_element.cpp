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

void k_th_largest_helper(Node *root, int &target, int &ans){
    if(root == NULL)
        return;
    if(root-> data < target){
        ans = max(ans, root-> data);
    }    
    for(Node *child : root-> children)
        k_th_largest_helper(child, target, ans);
}

int k_th_largest(Node *root, int k){
    int target = INT_MAX, ans = INT_MIN;
     while(k--){
         k_th_largest_helper(root, target, ans);
         target = ans;
         ans = INT_MIN;
     }
     return target;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int k;
    cin >> k;
    cout << k_th_largest(root, k) << '\n';
}