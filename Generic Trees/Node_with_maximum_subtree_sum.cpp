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

int max_sum(Node *root, int &_max, int &max_node){
    if(root == NULL)
        return 0;
    int recursive_sum = 0;    
    for(int i = 0; i < (int) root-> children.size(); i++){
        recursive_sum += max_sum(root-> children[i], _max, max_node);
    }   
    recursive_sum += root-> data;
    if(_max < recursive_sum){
        _max = recursive_sum;
        max_node = root-> data;
    }
    return recursive_sum; 
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = input();
    int _max = INT_MIN;
    int max_node = INT_MIN;
    int total_sum = max_sum(root, _max, max_node);
    cout << max_node << "@" << _max << '\n'; 
}